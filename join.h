#ifndef JOIN_H
#define JOIN_H
#include "home.h"
#include <QDialog>


namespace Ui {
class join;
}

class join : public QDialog
{
    Q_OBJECT

public:
    explicit join(QWidget *parent = nullptr,QHash<QString,information>* info=nullptr,QHash<QString,user>* pass=nullptr,int sz=0);
    ~join();

private slots:
    void on_back_clicked();

    void on_signup_clicked();

private:
    Ui::join *ui;
     class home* home;
    QHash<QString,information>* hash_map;
    QHash<QString,user>* hash_pass;
    int size;
};

#endif // JOIN_H
