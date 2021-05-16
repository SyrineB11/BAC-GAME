#include "loser2.h"
#include "ui_loser2.h"

loser2::loser2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::loser2)
{
    ui->setupUi(this);
}

loser2::~loser2()
{
    delete ui;
}
