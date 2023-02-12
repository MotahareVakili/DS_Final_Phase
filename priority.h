#ifndef PRIORITY_H
#define PRIORITY_H

#include <QDialog>
#include "QMessageBox"
namespace Ui {
class priority;
}

class priority : public QDialog
{
    Q_OBJECT

public:
    explicit priority(QWidget *parent = nullptr,int* Coef_s=nullptr, int* Coef_f=nullptr, int* Coef_u=nullptr,int* Coef_w=nullptr,int* Coef_d=nullptr);
    ~priority();

private slots:



    void on_spinBox_s_valueChanged(const QString &arg1);

    void on_spinBox_w_valueChanged(const QString &arg1);

    void on_spinBox_f_valueChanged(const QString &arg1);

    void on_spinBox_u_valueChanged(const QString &arg1);

    void on_spinBox_l_valueChanged(const QString &arg1);



    void on_save_clicked();

    void on_cancel_clicked();

private:
    Ui::priority *ui;
    int* Coef_s;int* Coef_f;int* Coef_u; int*Coef_w;int* Coef_d;
};

#endif // PRIORITY_H
