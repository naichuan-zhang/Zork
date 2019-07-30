#include "background.h"

Background::Background(Game *game, QWidget *parent, Ui::MainWindow *ui)
    : QGraphicsScene (parent), ui(ui)
{
    this->game = game;

    setButtons();
    setRoomExits(ui->game->currentRoom);
    setSceneRect(10, 0, 780, 520);
    ui->game->setGeometry(10, 0, 780, 520);

    configure();
    updateRoomDescription();
    setRoomBackground();
    addItemToScene();
}

Background::~Background()
{

}

void Background::setButtons()
{
    ui->northButton->setText(tr("NORTH"));
    ui->southButton->setText(tr("SOUTH"));
    ui->westButton->setText(tr("WEST"));
    ui->eastButton->setText(tr("EAST"));
}

void Background::setScene(const string direction)
{
    ui->showImage1->hide();
    ui->showImage2->hide();
    ui->textEdit2->setPlainText("");

    nextRoom = ui->game->currentRoom->nextRoom(direction);

    if (nextRoom != nullptr)
    {
        if (nextRoom->getCanEnter() == true)
        {
            nextRoom = ui->game->currentRoom->nextRoom(direction);
            ui->game->currentRoom=nextRoom;

            setRoomExits(ui->game->currentRoom);
            configure();
            updateRoomDescription();
            setRoomBackground();
            addItemToScene();

            errorMessage = " ";
            ui->textEdit2->setPlainText(QString::fromStdString(errorMessage));
        }

        else if (nextRoom->getCanEnter() == false)
        {
            errorMessage = " ";
            ui->textEdit2->setPlainText(QString::fromStdString(errorMessage));
        }
    }
}

void Background::setRoomBackground()
{
    QString bgdImage = QString::fromStdString(getFilename());

    ui->game->setStyleSheet("Game {border-image:url(" + bgdImage + ");}");
}

string Background::getFilename()
{
    return ":/game/" + ui->game->currentRoom->getDescription() + ".jpg";
}

void Background::setRoomExits(Room *room)
{
    ui->game->currentRoom = room;
    vector<string> exits = ui->game->currentRoom->exitString();

    disconnectButtons();

    for (unsigned int i = 0; i < exits.size(); i++)
    {
        if (exits[i] == "north")
            connect(ui->northButton, SIGNAL(clicked()), this, SLOT(northButtonClicked()));

        else if (exits[i] == "south")
            connect(ui->southButton, SIGNAL(clicked()), this, SLOT(southButtonClicked()));

        else if (exits[i] == "west")
            connect(ui->westButton, SIGNAL(clicked()), this, SLOT(westButtonClicked()));

        else if (exits[i] == "east")
            connect(ui->eastButton, SIGNAL(clicked()), this, SLOT(eastButtonClicked()));
    }
}

void Background::configure()
{
    ui->textEdit->setReadOnly(true);
    ui->textEdit->resize(300, 50);

    ui->textEdit2->setReadOnly(true);
    ui->textEdit2->resize(250, 40);

    ui->showImage1->setStyleSheet("QLabel#showImage1 {background:transparent;}");
    ui->showImage2->setStyleSheet("QLabel#showImage2 {background:transparent;}");

    this->addWidget(ui->northButton);
    this->addWidget(ui->southButton);
    this->addWidget(ui->westButton);
    this->addWidget(ui->eastButton);
    this->addWidget(ui->textEdit);
    this->addWidget(ui->textEdit2);
}

void Background::updateRoomDescription()
{
    roomDescription = "You are " + game->currentRoom->getDescription() + " now";
    ui->textEdit->setPlainText(QString::fromStdString(roomDescription));
}

void Background::addItemToScene()
{
    if (ui->game->currentRoom->getDescription() == "in the Forest")
    {
        map = new Map("You got a Map");
        logs = new Logs("You found some Logs in the Forest");
        this->addItem(map);
        this->addItem(logs);
        ui->showImage1->show();
        ui->showImage1->setPixmap(QPixmap(":/game/logs.jpg"));
        ui->textEdit2->setPlainText(QString("You found some logs in the Forest"));
        connect(ui->showImage1, SIGNAL(clicked()), this, SLOT(showClicked()));
    }

    else if (ui->game->currentRoom->getDescription() == "in the Bank")
    {
        tiger = new Tiger("Beware of the Tiger");
        this->addItem(tiger);
        ui->showImage1->show();
        ui->showImage1->setPixmap(QPixmap(":/game/tiger.jpg"));
        ui->textEdit2->setPlainText(QString("Beware of the Tiger"));
        connect(ui->showImage1, SIGNAL(clicked()), this, SLOT(showClicked3()));
    }

    else if (ui->game->currentRoom->getDescription() == "under the Tree")
    {
        stone = new Stone("You got a Stone");
        gold = new Gold("Congrats! You found the Gold!");
        this->addItem(stone);
        this->addItem(gold);
        ui->showImage1->show();
        ui->showImage1->setPixmap(QPixmap(":/game/stone.jpg"));
        ui->textEdit2->setPlainText(QString("You got a Stone"));
        connect(ui->showImage1, SIGNAL(clicked()), this, SLOT(showClicked4()));
    }

    else if (ui->game->currentRoom->getDescription() == "beside the Spring")
    {
        snake = new Snake("Opps! A Snake!");
        this->addItem(snake);
        ui->showImage1->show();
        ui->showImage1->setPixmap(QPixmap(":/game/snake.jpg"));
        ui->textEdit2->setPlainText(QString("Opps! A Snake!"));
        connect(ui->showImage1, SIGNAL(clicked()), this, SLOT(showClicked6()));
    }

}

void Background::disconnectButtons()
{
    disconnect(ui->northButton, SIGNAL(clicked()), this, SLOT(northButtonClicked()));
    disconnect(ui->southButton, SIGNAL(clicked()), this, SLOT(southButtonClicked()));
    disconnect(ui->westButton, SIGNAL(clicked()), this, SLOT(westButtonClicked()));
    disconnect(ui->eastButton, SIGNAL(clicked()), this, SLOT(eastButtonClicked()));
}

void Background::gameWin()
{
    winDialog = new WinDialog;
    winDialog->setAttribute(Qt::WA_DeleteOnClose);
    winDialog->setStyleSheet("QDialog#winDialog {background-image: url(:/images/win.gif);}");
    winDialog->exec();
}

void Background::northButtonClicked()
{
    setScene("north");
}

void Background::southButtonClicked()
{
    setScene("south");
}

void Background::westButtonClicked()
{
    setScene("west");
}

void Background::eastButtonClicked()
{
    setScene("east");
}

void Background::showClicked()
{
    ui->showImage1->hide();
    ui->showImage2->show();
    ui->showImage2->setPixmap(QPixmap(":/game/map.jpg"));
    connect(ui->showImage2, SIGNAL(clicked()), this, SLOT(showClicked2()));
}

void Background::showClicked2()
{
    ui->showImage1->hide();
    ui->showImage2->hide();
    setScene("south");
    setScene("south");
    setScene("east");
    ui->textEdit2->setPlainText("You walked to the Garden by Map");
}

void Background::showClicked3()
{
    ui->showImage1->hide();
    setScene("north");
    setScene("north");
    setScene("east");
    setScene("east");
    setScene("south");
    ui->textEdit2->setPlainText(QString("You killed the Tiger and got a Stone"));
}

void Background::showClicked4()
{
    ui->showImage1->hide();
    ui->showImage2->show();
    ui->showImage2->setPixmap(QPixmap(":/game/gold.JPG"));
    connect(ui->showImage2, SIGNAL(clicked()), this, SLOT(showClicked5()));
}

void Background::showClicked5()
{
    ui->showImage2->hide();
    ui->textEdit2->setPlainText(QString("Congrats! You found the Gold!"));
    gameWin();
}

void Background::showClicked6()
{
    ui->showImage1->hide();
    setScene("east");
    setScene("east");
    ui->textEdit2->setPlainText(QString("You ran back to Home"));
}
