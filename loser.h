#ifndef LOSER_H
#define LOSER_H

#include <QWidget>

namespace Ui {
class loser;
}

class loser : public QWidget
{
    Q_OBJECT

public:
    explicit loser(QWidget *parent = nullptr);
    ~loser();

private:
    Ui::loser *ui;
};

#endif // LOSER_H
