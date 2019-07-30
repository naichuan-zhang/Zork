#ifndef MYLABEL_H
#define MYLABEL_H

#include <Qt>
#include <QLabel>
#include <QWidget>
#include <QMouseEvent>

class MyLabel : public QLabel
{
    Q_OBJECT

public:
    MyLabel(QWidget *parent = nullptr);

signals:
    void clicked();

protected:
    void mousePressEvent(QMouseEvent *event);

};

#endif // MYLABEL_H
