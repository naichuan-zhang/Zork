#ifndef GOLD_H
#define GOLD_H

#include "item.h"
#include "ui_mainwindow.h"
#include "mainwindow.h"

#include <QMainWindow>
#include <string>

namespace Ui {
class MainWindow;
};

class Gold : public Item
{
public:
    Gold(QWidget *parent = nullptr, Ui::MainWindow *ui = nullptr);
    Gold(const string description);

    string getDescription() const { return description; }

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);

private:
    Ui::MainWindow *ui;
    const string description;
    QString text;
};

#endif // GOLD_H
