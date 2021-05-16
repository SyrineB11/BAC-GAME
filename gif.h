#ifndef GIF_H
#define GIF_H
#include <QObject>


class QLabel ;
class QMovie ;
class gif : public QObject
{
public:
    gif(QObject *parent=nullptr);
    void startMovie() ;
    void setFilename(const QString &filename)
    {
        mFilename=filename ;
    }
    QString getFilename() const
    {
        return mFilename;
    }
private :
    QLabel *mLabel ;
    QMovie *mMovie ;
    QString mFilename ;
};

#endif // GIF_H
