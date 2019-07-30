#ifndef LOGS_H
#define LOGS_H

#include "item.h"
#include "ui_mainwindow.h"
#include "mainwindow.h"

#include <QMainWindow>
#include <string>

namespace Ui {
class MainWindow;
};

class Logs : public Item
{
public:
    Logs(QWidget *parent = nullptr, Ui::MainWindow *ui = nullptr);
    Logs(const string description);
    string getDescription() const { return description; }

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);

private:
    Ui::MainWindow *ui;
    const string description;
    QString text;
};

#endif // LOGS_H
