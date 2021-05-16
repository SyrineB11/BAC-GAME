#ifndef CINEMA_H
#define CINEMA_H

#include <QDialog>
#include <QTimer>
#include "loser.h"
#include "winner.h"

namespace Ui {
class cinema;
}

class cinema : public QDialog
{
    Q_OBJECT

public:
    explicit cinema(QWidget *parent = nullptr);
    ~cinema();

    QString verif(QString &nom_fichier,QString mot);
    int score();



private slots:
    void on_pushButton_clicked();

private:
    Ui::cinema *ui;
    loser *mloser ;
    winner *mwinner ;



};

#endif // CINEMA_H
