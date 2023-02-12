#include "log_in.h"
#include "ui_log_in.h"


log_in::log_in(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::log_in)
{
    ui->setupUi(this);
    Read_Json_File();

}

log_in::~log_in()
{
    Save_to_File();
    delete ui;
}

void log_in::Read_Json_File()
{

    QFile file(QString::fromStdString("users.json"));
    if (!file.open(QIODevice::ReadOnly))
     qDebug() << "Failed to open ";
    QTextStream txs(&file);
    QByteArray qb=txs.readAll().toLocal8Bit();
    QJsonDocument jdoc = QJsonDocument::fromJson(qb);
    QJsonArray ary = jdoc.array();
    size=ary.size();
    foreach (const QJsonValue & value, ary)
    {
        QJsonObject obj = value.toObject();
        information info;
        info.name=obj["name"].toString();
        info.dateOfBirth=obj["dateOfBirth"].toString();
        info.field=obj["field"].toString();
        info.universityLocation=obj["universityLocation"].toString();
        info.workplace=obj["workplace"].toString();
        QJsonArray x=obj["specialties"].toArray();
        for(int i=0;i<x.size();i++)
            info.specialties.append(x[i].toString());

        QJsonArray y=obj["connectionId"].toArray();
        for(int i=0;i<y.size();i++)
            info.connectionId.append(y[i].toString());

       hash_map.insert(obj["id"].toString(),info);
       if(!obj.keys().contains("password"))
       obj.insert("password",QString::number( obj["id"].toString().toInt()*size+1000));
       user usr;
       usr.id=obj["id"].toString();
       usr.password=obj["password"].toString();
       hash_pass.insert(obj["name"].toString(),usr);


    }
}

void log_in::Save_to_File()
{
    QJsonArray ary;
    for(QString i:hash_map.keys())
    {
        QJsonObject obj;
        information info=hash_map.value(i);
        obj["name"]=info.name;
        obj["dateOfBirth"]=info.dateOfBirth;
        obj["field"]=info.field;
        obj["id"]=i;
        obj["universityLocation"]=info.universityLocation;
        obj["workplace"]=info.workplace;
        obj["connectionId"]=QJsonArray::fromStringList(info.connectionId);
        obj["specialties"]=QJsonArray::fromStringList(info.specialties);
        obj["password"]=hash_pass.value(info.name).password;
        QJsonValue value=obj;
        ary.append(value);
    }
    QJsonDocument doc;
    doc.setArray(ary);  
    QFile save_file(QString::fromStdString("users.json"));
      if (!save_file.open(QIODevice::WriteOnly)) {
          qDebug() << "Failed to open ";
       }
       save_file.write(doc.toJson());
       save_file.close();

}



void log_in::on_join_clicked()
{
  join=new class join(this,&hash_map,&hash_pass,size);
  this->hide();
  join->show();


}

void log_in::on_sign_in_clicked()
{   if(ui->username->text()=="" ||ui->password->text()=="")
    {
        QMessageBox::critical(this,"Login Faild","please enter a valid username or password.");
        return;
    }
    QString name=this->ui->username->text();
    QString pass=this->ui->password->text();

    if(hash_pass[name].password==pass)
      {

         home=new class home(this,hash_pass[name].id,&hash_map,&hash_pass);
         this->hide();
         home->show();
      }
    else
    {
        this->ui->username->clear();
        this->ui->password->clear();
        QMessageBox::critical(this,"Login Faild","please enter a valid username or password.");
    }
}
