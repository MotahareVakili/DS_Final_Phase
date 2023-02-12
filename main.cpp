#include "log_in.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    log_in w;
    w.show();
    return a.exec();
}
