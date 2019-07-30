#ifndef STONE_H
#define STONE_H

#include "item.h"
#include "ui_mainwindow.h"
#include "mainwindow.h"

#include <QMainWindow>
#include <string>

namespace Ui {
class MainWindow;
};

class Stone : public Item
{
public:
    Stone(QWidget *parent = nullptr, Ui::MainWindow *ui = nullptr);
    Stone(const string description);

    string getDescription() const { return description; }

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);

private:
    Ui::MainWindow *ui;
    const string description;
    QString text;
};

#endif // STONE_H
