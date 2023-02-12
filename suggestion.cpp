#include "suggestion.h"
#include "ui_suggestion.h"

suggestion::suggestion(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::suggestion)
{
    ui->setupUi(this);
}

suggestion::~suggestion()
{
    delete ui;
}
