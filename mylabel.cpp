#include "mylabel.h"

MyLabel::MyLabel(QWidget *parent)
    : QLabel (parent)
{

}

void MyLabel::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
        emit clicked();

    QLabel::mousePressEvent(event);
}
