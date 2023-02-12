#include "profile.h"
#include "ui_profile.h"

profile::profile(QWidget *parent,QHash<QString,information>* info,QString id,QString user) :
    QDialog(parent),
    ui(new Ui::profile)
{
    ui->setupUi(this);
    this->hash_map=info;
    this->Id=id;
    this->user_id=user;
    prf();
    if(is_follower())
        ui->follow_remove->setText("Unfollow");
    else
      ui->follow_remove->setText("Follow");



}

profile::~profile()
{
    delete ui;
}

void profile::prf()
{
    information info= hash_map->value(Id);
    ui->name->setText(info.name);
    ui->following->setText("Following: "+QString::number( info.connectionId.size()));
    ui->post->setText("Post: 0");
    ui->birth->setText("Date of Birth: "+info.dateOfBirth);
    ui->field->setText("Field: "+info.field);
    ui->uni_loc->setText("University Location: "+info.universityLocation);
    ui->wplace->setText("Work Place: "+info.workplace);
    ui->special->setText("Specialties:");
    for (QString s:info.specialties)
        ui->textEdit->append(s);
}

bool profile::is_follower()
{
    for(QString s:hash_map->value(user_id).connectionId)
    {
        if(s==Id)
            return true;
    }
    return false;
}

void profile::on_back_clicked()
{
    this->hide();
    parentWidget()->show();


}

void profile::on_follow_remove_clicked()
{
    if(is_follower())
    {

      information tmp= hash_map->value(user_id);
      tmp.connectionId.removeOne(Id);
      hash_map->insert(user_id,tmp);
      QMessageBox::information(this,"","unfollow");
       ui->follow_remove->setText("Follow");
     emit mysignal();
    }
    else
    {

           information tmp= hash_map->value(user_id);
           tmp.connectionId.push_back(Id);
           hash_map->insert(user_id,tmp);
           QMessageBox::information(this,"","follow");
            ui->follow_remove->setText("Unfollow");
           emit mysignal();
    }

}
