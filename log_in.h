#ifndef LOG_IN_H
#define LOG_IN_H
#include <QDialog>
#include"join.h"
#include "QJsonDocument"
#include "QJsonArray"
#include "QJsonObject"
#include "QFile"
#include "QTextStream"
#include "QByteArray"
#include "QDebug"

QT_BEGIN_NAMESPACE
namespace Ui { class log_in; }
QT_END_NAMESPACE

class log_in : public QDialog
{
    Q_OBJECT

public:
    log_in(QWidget *parent = nullptr);
    ~log_in();
    void Read_Json_File();
    void Save_to_File();



private slots:
    void on_join_clicked();

    void on_sign_in_clicked();

private:
    Ui::log_in *ui;
    class join* join;
    class home* home;
     QHash<QString,information> hash_map;
     QHash<QString,user> hash_pass;
     int size;

};
#endif // LOG_IN_H
