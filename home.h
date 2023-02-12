#ifndef HOME_H
#define HOME_H
#include <QDialog>
#include "QListWidgetItem"
#include "profile.h"
#include "priority.h"
namespace Ui {
class home;
}

class home : public QDialog
{
    Q_OBJECT

public:
    explicit home(QWidget *parent = nullptr,QString id="",QHash<QString,information>* info=nullptr,QHash<QString,user>* pass=nullptr);
    ~home();
    void profile();
    void suggest(QString id,int n);
    void new_member_suggest();
    void show_suggestions(int Coef_s=5, int Coef_f=4, int Coef_u=2,int Coef_w=3,int Coef_d=1);



private slots:
 void changed();
 void on_tabWidget_currentChanged(int index);
 void on_connections_itemDoubleClicked(QListWidgetItem *item);
 void on_suggest_itemDoubleClicked(QListWidgetItem *item);


private:
    Ui::home *ui;
    QString user_id;
    class profile* prfl;
    class priority*prt;
    QHash<QString,information>* hash_map;
    QHash<QString,user>* hash_pass;
    QHash<QString,int> suggestions;
    int Coef_s=5,  Coef_f=4,  Coef_u=2, Coef_w=3, Coef_d=1;

};

#endif // HOME_H
