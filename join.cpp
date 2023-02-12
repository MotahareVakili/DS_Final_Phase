#include "join.h"
#include "ui_join.h"
#include "QDebug"
#include <string>
join::join(QWidget *parent,QHash<QString,information>* info,QHash<QString,user>* pass,int sz) :
    QDialog(parent),
    ui(new Ui::join)
{
    ui->setupUi(this);
    this->hash_map=info;
    this->hash_pass=pass;
    this->size=sz;
}

join::~join()
{
    delete ui;
}

void join::on_back_clicked()
{
    this->hide();
    parentWidget()->show();

}

void join::on_signup_clicked()
{
    information info;
    info.dateOfBirth=ui->birth->text();
    info.field=ui->field->text();
    info.name=ui->fname->text()+ui->lname->text();
    info.specialties=ui->specialties->text().split(",");
    info.universityLocation=ui->uni_location->text();
    info.workplace=ui->workplace->text();
    hash_map->insert(QString::number(size+1),info);
    user usr;
    usr.password=ui->password->text();
    usr.id=QString::number(size+1);
    hash_pass->insert(ui->fname->text()+ui->lname->text(),usr);
    QMessageBox::information(this,"Sign Up","Account created successfully");
    home=new class home(this,QString::number(size+1),hash_map,hash_pass);
    this->hide();
    home->show();





}
