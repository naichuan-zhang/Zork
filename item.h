#ifndef ITEM_H
#define ITEM_H

#include <QGraphicsPixmapItem>
#include <string>
#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QtGui>

#include "mainwindow.h"

using namespace std;

class Item : public QGraphicsPixmapItem
{
    friend class Background;

public:
    Item();
    Item(const string description);

    virtual string getDescription() const { return description; }

protected:
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *event) = 0;

private:
    string description;
    Ui::MainWindow *ui;
};

#endif // ITEM_H
