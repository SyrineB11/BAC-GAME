#ifndef LETTRE_H
#define LETTRE_H
#include <QGraphicsTextItem>

class lettre: public QGraphicsTextItem
{
public :
    lettre(QGraphicsItem * parent=0);
    void get_l();

private:
   char l ;};











#endif // LETTRE_H
