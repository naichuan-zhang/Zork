#ifndef SNAKE_H
#define SNAKE_H

#include "item.h"
#include "ui_mainwindow.h"
#include "mainwindow.h"

#include <QMainWindow>
#include <string>

namespace Ui {
class MainWindow;
};
class Snake : public Item
{
public:
    Snake(QWidget *parent = nullptr, Ui::MainWindow *ui = nullptr);
    Snake(const string description);
    string getDescription() const { return description; }

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);

private:
    Ui::MainWindow *ui;
    const string description;
    QString text;
};

#endif // SNAKE_H
