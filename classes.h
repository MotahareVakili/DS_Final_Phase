#ifndef CLASSES_H
#define CLASSES_H
#include "QString"
#include "QStringList"
#endif // CLASSES_H

class information
{
public:
    QString name;
    QString dateOfBirth;
    QString universityLocation;
    QString field;
    QString workplace;
    QStringList specialties={};
    QStringList connectionId={};

};

class user
{
public:
    QString id;
    QString password;
};
