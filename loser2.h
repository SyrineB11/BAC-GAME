#ifndef LOSER2_H
#define LOSER2_H

#include <QWidget>

namespace Ui {
class loser2;
}

class loser2 : public QWidget
{
    Q_OBJECT

public:
    explicit loser2(QWidget *parent = nullptr);
    ~loser2();

private:
    Ui::loser2 *ui;
};

#endif // LOSER2_H
