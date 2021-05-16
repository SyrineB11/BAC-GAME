#include "gif.h"
#include <QMovie>
#include <QLabel>
#include <QObject>

gif::gif(QObject *parent=nullptr)
    :QObject(parent)
{
    mMovie = new QMovie(this) ;
    mLabel = new QLabel(this) ;

}
void gif::startMovie()
{
 mMovie->setFilename(mFilename) ;
 mMovie->start();
 mLabel->setMovie(mMovie) ;

}
