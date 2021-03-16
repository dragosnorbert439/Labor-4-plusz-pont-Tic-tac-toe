#ifndef RBUTTON_H
#define RBUTTON_H
#include <QPushButton>
#include <QMouseEvent>

class rButton : public QPushButton
{
    Q_OBJECT

public:
    rButton(QWidget *parent = 0);

private slots:
    void mousePressEvent(QMouseEvent *e);

signals:
    void rightClicked();

public slots:

};


#endif // RBUTTON_H
