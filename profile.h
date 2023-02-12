#ifndef PROFILE_H
#define PROFILE_H
#include "QMessageBox"
#include <QDialog>
#include "QHash"
#include "classes.h"
namespace Ui {
class profile;
}

class profile : public QDialog
{
    Q_OBJECT
signals:
void mysignal();
public:
    explicit profile(QWidget *parent = nullptr,QHash<QString,information>* hash_map=nullptr,QString id="",QString user_id="");
    ~profile();
    void prf();
    bool is_follower();

private slots:
    void on_back_clicked();

    void on_follow_remove_clicked();

private:
    Ui::profile *ui;
    QHash<QString,information>* hash_map;
    QString Id;
    QString user_id;

};

#endif // PROFILE_H
