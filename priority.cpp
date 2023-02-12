#include "priority.h"
#include "ui_priority.h"

priority::priority(QWidget *parent,int* Coef_s, int *Coef_f, int* Coef_u,int* Coef_w,int* Coef_d) :
    QDialog(parent),
    ui(new Ui::priority)
{
    ui->setupUi(this);
    this->Coef_d=Coef_d;
    this->Coef_f=Coef_f;
    this->Coef_s=Coef_s;
    this->Coef_u=Coef_u;
    this->Coef_w=Coef_w;
}

priority::~priority()
{
    delete ui;
}



void priority::on_spinBox_s_valueChanged(const QString &arg1)
{
    ui->lineEdit_s->setText(arg1);
}

void priority::on_spinBox_w_valueChanged(const QString &arg1)
{
    ui->lineEdit_w->setText(arg1);
}

void priority::on_spinBox_f_valueChanged(const QString &arg1)
{
    ui->lineEdit_f->setText(arg1);
}

void priority::on_spinBox_u_valueChanged(const QString &arg1)
{
    ui->lineEdit_u->setText(arg1);
}

void priority::on_spinBox_l_valueChanged(const QString &arg1)
{
    ui->lineEdit_l->setText(arg1);
}



void priority::on_save_clicked()
{
    if((ui->lineEdit_s->text()!="" &&ui->lineEdit_w->text()!=""&&ui->lineEdit_f->text()!=""&&ui->lineEdit_u->text()!=""
            &&ui->lineEdit_l->text()!="") ||ui->checkBox->isChecked())
    {   if(!ui->checkBox->isChecked())
       {
            *Coef_d=ui->lineEdit_l->text().toInt();
           *Coef_s=ui->lineEdit_s->text().toInt();
           *Coef_u=ui->lineEdit_u->text().toInt();
           *Coef_w=ui->lineEdit_w->text().toInt();
           *Coef_f=ui->lineEdit_f->text().toInt();
        }
        this->hide();
        parentWidget()->show();
    }

  else
        QMessageBox::warning(this,"","Please rate all items or use default preferences");

}

void priority::on_cancel_clicked()
{
    ui->lineEdit_f->clear();
    ui->lineEdit_s->clear();
    ui->lineEdit_l->clear();
    ui->lineEdit_u->clear();
    ui->lineEdit_w->clear();
}
