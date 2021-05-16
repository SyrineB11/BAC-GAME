#include "m1.h"
#include "ui_m1.h"

m1::m1(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::m1)
{
    ui->setupUi(this);
}

m1::~m1()
{
    delete ui;
}
