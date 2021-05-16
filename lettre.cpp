#include "lettre.h"
#include <QFont>
#include <QGraphicsItem>
#include "QString"
#include "ctime"
#include "conio.h"

lettre::lettre(QGraphicsItem *parent) : QGraphicsTextItem(parent)
{

    setPlainText(QString("La lettre est :")) ;
    setDefaultTextColor(Qt::blue);

}
void lettre ::get_l()
{
    const char alphabet[] = "BACDEFGHIJKLMNOPQRSTUVWXYZ";
          size_t indice;
          srand(time(NULL));
          indice = rand() % (25 + 1);
          char L = alphabet[indice];
          setPlainText(QString("La lettre est :") + L ) ;
}
