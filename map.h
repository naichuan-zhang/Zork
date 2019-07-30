#ifndef MAP_H
#define MAP_H

#include "item.h"
#include "ui_mainwindow.h"
#include "mainwindow.h"

#include <QMainWindow>
#include <string>

namespace Ui {
class MainWindow;
};

class Map : public Item
{
public:
    Map(QWidget *parent = nullptr, Ui::MainWindow *ui = nullptr);
    Map(const string description);
    string getDescription() const { return description; }

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);

private:
    Ui::MainWindow *ui;
    const string description;
    QString text;
};

#endif // MAP_H
