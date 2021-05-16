#include "cinema.h"
#include "ui_cinema.h"
#include "loser.h"
#include "winner.h"
#include "QDebug"
#include <QMessageBox>
#include <QTextStream>
#include "QString"
#include "ctime"
#include "conio.h"
#include "QTimer"
#include "QTime"
#include <QFile>
#include <QIODevice>
#include <iostream>
#include <QTextStream>
#include <QLabel>
#include <QString>
#include <QLineEdit>
#include <QWidgetSet>


cinema::cinema(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::cinema)

{
    ui->setupUi(this);


}


cinema::~cinema()
{
    delete ui;
}

void cinema::on_pushButton_clicked()

{   QString L = ui->lineEdit_5->text() ;
    int score =0 ;
    QString m1 = ui->lineEdit->text();
    QFile file1("C:/Users/21694/Documents/jeu1/Movies.txt");
    if (!file1.open(QIODevice::ReadOnly | QIODevice::Text))
    { QMessageBox::warning(this,"title","file not open" );
    }
    else
    {


     QTextStream donnees1(&file1) ;

     QString ligne1;
      while(! donnees1.atEnd())
      {
        donnees1 >> ligne1 ;


        if (( m1==ligne1) && (m1[0]==L))
          {
            score=2+score  ;}
     file1.close() ;
    }
    }
    QString m2 = ui->lineEdit_2->text();
    QFile file2("C:/Users/21694/Documents/jeu1/Actors.txt");
    if (!file2.open(QIODevice::ReadOnly | QIODevice::Text))
      { QMessageBox::warning(this,"title","file not open" );
      }
    else
      {

       QTextStream donnees2(&file2) ;
       QString ligne2;
       while(! donnees2.atEnd())
       {
        donnees2 >> ligne2 ;

        if (( m2==ligne2)&&(m2[0]==L))
          {
            score=2+score  ;}


     file2.close() ;
    }
    }
    QString m3 = ui->lineEdit_3->text();
    QFile file3("C:/Users/21694/Documents/jeu1/Actress.txt");
    if (!file3.open(QIODevice::ReadOnly | QIODevice::Text))
      { QMessageBox::warning(this,"title","file not open" );
      }
    else
      {
       QTextStream donnees3(&file3) ;
       QString ligne3;
       while(! donnees3.atEnd())
       {
        donnees3 >> ligne3 ;

        if (( m3==ligne3)&&(m3[0])==L)
          {
            score=score+2  ;}

       else
           { score=score+0  ;}
     file3.close() ;
    }
     }
    QString m4 = ui->lineEdit_4->text();
    QFile file4("C:/Users/21694/Documents/jeu1/Prizes.txt");
    if (!file4.open(QIODevice::ReadOnly | QIODevice::Text))
      { QMessageBox::warning(this,"title","file not open" );
      }
    else
    {


      QTextStream donnees4(&file4) ;
      QString ligne4;
      while(! donnees4.atEnd())
      {
       donnees4 >> ligne4 ;

        if (( m4==ligne4)&& (m4[0]==L))
          {
            score=score+2  ;}

       else
           { score=score+0  ;}
     file4.close() ;
      }
    }
    if ((m1=="")||(m2=="")||(m3=="")||(m4=="")||(L==""))

      {QMessageBox::information(this,"cinema","Veuillez remplir tous les champs !!! ");}

    else
       {
    if (score >=4)
    {
       QMessageBox::information(this,"GAGANT AVEC SCORE",QString::number(score) );
       mwinner = new winner();
       mwinner->show();
    }

    else
      {

        mloser = new loser();
        mloser->show();



      }


       }
}






