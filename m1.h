#ifndef M1_H
#define M1_H

#include <QMainWindow>

namespace Ui {
class m1;
}

class m1 : public QMainWindow
{
    Q_OBJECT

public:
    explicit m1(QWidget *parent = nullptr);
    ~m1();

private:
    Ui::m1 *ui;
};

#endif // M1_H
