#include "rButton.h"

rButton::rButton(QWidget *parent) : QPushButton(parent)
{
}

void rButton::mousePressEvent(QMouseEvent *e)
{
    if (e->button() == Qt::RightButton) emit rightClicked();
}
