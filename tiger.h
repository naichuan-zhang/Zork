#ifndef TIGER_H
#define TIGER_H

#include "item.h"
#include "ui_mainwindow.h"
#include "mainwindow.h"

#include <QMainWindow>
#include <string>

namespace Ui {
class MainWindow;
};

class Tiger : public Item
{
public:
    Tiger(QWidget *parent = nullptr, Ui::MainWindow *ui = nullptr);
    Tiger(const string description);

    string getDescription() const { return description; }

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);

private:
    Ui::MainWindow *ui;
    const string description;
    QString text;
};

#endif // TIGER_H
