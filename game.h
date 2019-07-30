#ifndef GAME_H
#define GAME_H

#include "roledialog.h"

#include <Qt>
#include <QLabel>
#include <QMainWindow>
#include <QObject>
#include <QGraphicsView>
#include <vector>

#include "room.h"

using namespace std;

namespace Ui {
class MainWindow;
};

class Game : public QGraphicsView
{
    Q_OBJECT

    friend class Background;

public:
    Game(QWidget *parent = nullptr, Ui::MainWindow *ui = nullptr);
    virtual ~Game();

    QLabel *textLabel;
    QLabel *imageLabel;

    void play();
    void createExits();
    Room *createRooms();

private slots:
    void start();

private:
    Ui::MainWindow *ui;

    RoleDialog *roleDialog;

    QString name;
    QString gender;

    QTimer *timer;

    Room *home, *path1, *forest, *river, *bank, *garden,
         *balcony, *castle, *path2, *tree, *mountain, *spring;

    Room *currentRoom;
};

#endif // GAME_H
