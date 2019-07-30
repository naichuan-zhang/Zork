#include "game.h"
#include "ui_mainwindow.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "background.h"

#include "gold.h"
#include "logs.h"
#include "map.h"
#include "snake.h"
#include "stone.h"
#include "tiger.h"

#include <QDebug>
#include <QMainWindow>
#include <QTimer>
#include <QRegExp>

Game::Game(QWidget *parent, Ui::MainWindow *ui) :
    QGraphicsView(parent), ui(ui)
{
    this->setAlignment(Qt::AlignLeft | Qt::AlignTop);

    currentRoom = createRooms();
    createExits();
}

Game::~Game()
{
    delete home;
    delete path1;
    delete forest;
    delete river;
    delete bank;
    delete garden;
    delete balcony;
    delete castle;
    delete path2;
    delete tree;
    delete mountain;
    delete spring;
}

void Game::play()
{
    bool loop = true;
    while (loop)
    {
        roleDialog = new RoleDialog;
        roleDialog->setAttribute(Qt::WA_Disabled);

        if (roleDialog->exec() == QDialog::Accepted && roleDialog->getName() != nullptr)
        {
            name = roleDialog->getName();
            gender = roleDialog->getGender();

            QString message = "Hi, " + name + "! Welcome to Zork World! ";

            ui->textLabel->setText(message);
            ui->textLabel->setGeometry(20, 300, 800, 80);
            ui->imageLabel->setGeometry(20, 20, 250, 250);
            ui->textLabel->setAlignment(Qt::AlignCenter);

            if (gender == QObject::tr("&Male"))
            {
                QPixmap pixmap(":/images/male.png");
                QSize sz(250, 250);
                pixmap = pixmap.scaled(sz, Qt::KeepAspectRatio);
                ui->imageLabel->setPixmap(pixmap);
            }

            else if (gender == QObject::tr("&Female"))
            {
                QPixmap pixmap(":/images/female.png");
                QSize sz(250, 250);
                pixmap = pixmap.scaled(sz, Qt::KeepAspectRatio);
                ui->imageLabel->setPixmap(pixmap);
            }

            loop = false;
        }
    }
    QTimer::singleShot(5000, this, SLOT(start()));
}

void Game::start()
{
    ui->loadingWidget->setCurrentIndex(3);
    //Background *background = new Background();
    Background *background = new Background(ui->game, ui->loadingWidget, ui);
    //ui->game->setScene(background);
    ui->game->show();
}

Room *Game::createRooms()
{
    Logs *logs = new Logs("You found some Logs in the Forest");
    Map *map = new Map("You got a Map");
    Tiger *tiger = new Tiger("Beware of the Tiger");
    Stone *stone = new Stone("You got a Stone");
    Gold *gold = new Gold("Congrats! You found the Gold!");
    Snake *snake = new Snake("Opps! A Snake!");

    home = new Room("at Home");
    path1 = new Room("on the Path1");
    forest = new Room("in the Forest");
    river = new Room("at the River");
    bank = new Room("in the Bank");
    garden = new Room("in the Garden");
    balcony = new Room("at the Balcony");
    castle = new Room("in the Castle");
    path2 = new Room("on the Path2");
    tree = new Room("under the Tree");
    mountain = new Room("on the Mountain");
    spring = new Room("beside the Spring");


    forest->addItem(logs);
    forest->addItem(map);
    forest->setLogs(true);
    forest->setMap(true);
    forest->setItem(true);
    bank->addItem(tiger);
    bank->setTiger(true);
    bank->setItem(true);
    tree->addItem(stone);
    tree->addItem(gold);
    tree->setStone(true);
    tree->setGold(true);
    tree->setItem(true);
    spring->addItem(snake);
    spring->setSnake(true);
    spring->setItem(true);

    return home;
}

void Game::createExits()
{
    home->setExits(path1, garden, river, mountain);
    path1->setExits(forest, nullptr, home, nullptr);
    forest->setExits(nullptr, nullptr, path1, nullptr);
    river->setExits(home, nullptr, bank, nullptr);
    bank->setExits(river, nullptr, nullptr, nullptr);
    garden->setExits(nullptr, path2, nullptr, home);
    balcony->setExits(nullptr, nullptr, castle, nullptr);
    castle->setExits(balcony, nullptr, path2, nullptr);
    path2->setExits(castle, nullptr, tree, garden);
    tree->setExits(path2, nullptr, nullptr, nullptr);
    mountain->setExits(nullptr, home, nullptr, spring);
    spring->setExits(nullptr, mountain, nullptr, nullptr);
}
