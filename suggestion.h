#ifndef SUGGESTION_H
#define SUGGESTION_H

#include <QWidget>

namespace Ui {
class suggestion;
}

class suggestion : public QWidget
{
    Q_OBJECT

public:
    explicit suggestion(QWidget *parent = nullptr);
    ~suggestion();

private:
    Ui::suggestion *ui;
};

#endif // SUGGESTION_H
