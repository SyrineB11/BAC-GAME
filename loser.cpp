#include "loser.h"
#include "ui_loser.h"

loser::loser(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::loser)
{
    ui->setupUi(this);
}

loser::~loser()
{
    delete ui;
}
