#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <QGraphicsScene>
#include <QPushButton>
#include <QWidget>
#include <string>
#include <QMainWindow>

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "game.h"
#include "room.h"
#include "item.h"
#include "gold.h"
#include "logs.h"
#include "map.h"
#include "snake.h"
#include "stone.h"
#include "tiger.h"
#include "windialog.h"

using namespace std;

namespace Ui {
class MainWindow;
};

class Background : public QGraphicsScene
{
    Q_OBJECT

public:
    Background(Game *game, QWidget *parent = nullptr, Ui::MainWindow *ui = nullptr);
    ~Background();

    void setScene(const string dir);
    void setRoomExits(Room *room);
    inline void setRoomBackground();
    void addItemToScene();

    inline void setButtons();
    inline void configure();
    void updateRoomDescription();
    void disconnectButtons();
    void gameWin();

    string getFilename();

public slots:
    void northButtonClicked();
    void southButtonClicked();
    void westButtonClicked();
    void eastButtonClicked();
    void showClicked();
    void showClicked2();
    void showClicked3();
    void showClicked4();
    void showClicked5();
    void showClicked6();

private:
    Ui::MainWindow *ui;

    Game *game;
    Room *nextRoom;

    QGraphicsScene *scene;
    QPlainTextEdit *textEdit;
    QGraphicsPixmapItem *px = nullptr;

    string roomDescription = "";
    string errorMessage = "";

    Gold *gold;
    Logs *logs;
    Map *map;
    Snake *snake;
    Stone *stone;
    Tiger *tiger;

    WinDialog *winDialog;
};

#endif // BACKGROUND_H
