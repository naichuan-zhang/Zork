#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "exitdialog.h"
#include "custbutton.h"
#include "loadingwidget.h"
#include "setting.h"
#include "help.h"

#include <Qt>
#include <QPainter>
#include <QRect>
#include <QMessageBox>
#include <QString>
#include <QMediaPlayer>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setGeometry(0, 0, 800, 600);
    this->setMinimumWidth(800);
    this->setMinimumHeight(600);
    this->setWindowTitle(QObject::tr("Zork - Project"));
    ui->loadingWidget->ui = ui;
    ui->loadingWidget->hide();

    max = new QPushButton;
    max->setIcon(QIcon(":/images/max.jpg"));
    max->setCheckable(TRUE);
    min = new QPushButton;
    min->setIcon(QIcon(":/images/min.png"));
    close = new QPushButton;
    close->setIcon(QIcon(":/images/close.png"));

    setWindowFlags(windowFlags() &~ Qt::WindowMinMaxButtonsHint);
    setWindowFlags(windowFlags() &~ Qt::WindowCloseButtonHint);
    setAttribute(Qt::WA_TranslucentBackground);     // transparent

    connect(ui->max, SIGNAL(clicked()), this, SLOT(clickMax()));
    connect(ui->min, SIGNAL(clicked()), this, SLOT(clickMin()));
    connect(ui->close, SIGNAL(clicked()), this, SLOT(clickClose()));

    createMenuBar();
    createToolBar();
    createButtons();

    playMusic();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::paintEvent(QPaintEvent *event)
{

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setBrush(QBrush(Qt::gray));
    painter.setPen(Qt::transparent);
    QRect rect = this->rect();
    rect.setWidth(rect.width() - 1);
    rect.setHeight(rect.height() - 1);
    painter.drawRoundedRect(rect, 15, 15);

    QWidget::paintEvent(event);

    painter.drawPixmap(0, 0, width(), height(), QPixmap(":/images/background.jpg"));

    QPixmap *pixmap = new QPixmap(":/images/logo.png");
    pixmap->scaled(ui->titleLabel->size(), Qt::KeepAspectRatio);
    ui->titleLabel->setScaledContents(true);
    ui->titleLabel->setPixmap(*pixmap);
    ui->titleLabel->setGeometry(260, 70, 250, 160);
}

// Set borderless free movement
void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        m_bPressed = true;
        m_point = event->pos();
    }
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    if (m_bPressed)
        move(event->globalPos() - m_point);
}

void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
    m_bPressed = false;
}

void MainWindow::clickMax()
{
    setWindowState(Qt::WindowMaximized);
}

void MainWindow::clickMin()
{
    setWindowState(Qt::WindowMinimized);
}

void MainWindow::clickClose()
{
    ExitDialog *dialog = new ExitDialog(this);
    dialog->setAttribute(Qt::WA_DeleteOnClose);
    int ret = dialog->exec();
    if (ret == QDialog::Accepted)
    {
        exit(0);
    }
    else
        return;
}

void MainWindow::createMenuBar()
{
    menu[0] = new QMenu("&Game");
    act[0] = new QAction("&Play", this);
    act[1] = new QAction("&New", this);
    menu[0]->addAction(act[0]);
    menu[0]->addAction(act[1]);

    menu[1] = new QMenu("&Exit");
    act[2] = new QAction("&Exit", this);
    menu[1]->addAction(act[2]);

    menu[2] = new QMenu("&Show");
    act[3] = new QAction("&Show Main Page", this);
    menu[2]->addAction(act[3]);

    menu[3] = new QMenu("&Help");
    act[4] = new QAction("&Help", this);
    act[5] = new QAction("&About", this);
    menu[3]->addAction(act[4]);
    menu[3]->addAction(act[5]);

    menuBar = new QMenuBar(this);
    menuBar->addMenu(menu[0]);
    menuBar->addMenu(menu[1]);
    menuBar->addMenu(menu[2]);
    menuBar->addMenu(menu[3]);
    connect(menuBar, SIGNAL(triggered(QAction*)), this, SLOT(triggerMenu(QAction*)));

    menuBar->setGeometry(QRect(0, 0, 400, 23));
    this->setMenuBar(menuBar);
}

void MainWindow::createToolBar()
{
    toolBar = findChild<QToolBar*> ("toolBar");
    toolBar->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    toolBarActionGroup = new QActionGroup(this);
    QList<QAction*> toolBarList;

    actionToolBar1 = new QAction(QIcon(":/icon/play_icon.jpg"), QStringLiteral("Play"));
    actionToolBar2 = new QAction(QIcon(":/icon/exit_icon.png"), QStringLiteral("Exit"));
    actionToolBar1->setCheckable(true);
    actionToolBar2->setCheckable(true);

    toolBarList.append(actionToolBar1);
    toolBarList.append(actionToolBar2);
    toolBarActionGroup->addAction(actionToolBar1);
    toolBarActionGroup->addAction(actionToolBar2);

    toolBar->addActions(toolBarList);
    toolBar->setStyleSheet("background-color:rgb(216,226,235);"
                           "color:black;"
                           "font-family:arial,diamond;");

    connect(toolBarActionGroup, SIGNAL(triggered(QAction*)), this, SLOT(triggerToolBar(QAction*)));

}

void MainWindow::createButtons()
{
    ui->playButton->setButtonIcons(QIcon(":/buttons/play1.png"),
             QIcon(":/buttons/play2.png"), QIcon(":/buttons/play3.png"));
    ui->playButton->setGeometry(150, 320, 165, 65);
    ui->playButton->setIconSize(QSize(165, 65));
    ui->playButton->setCursor(QCursor(Qt::PointingHandCursor));
    connect(ui->playButton, &QPushButton::clicked, this, &MainWindow::playGame);

    ui->helpButton->setButtonIcons(QIcon(":/buttons/help1.png"),
             QIcon(":/buttons/help1.png"), QIcon(":/buttons/help2.png"));
    ui->helpButton->setStyleSheet("border-top:1px transparent; "
                                  "border-bottom:1px transparent; "
                                  "border-right:7px transparent; "
                                  "border-left:7px transparent; "
                                  "height:20px; ");
    ui->helpButton->setGeometry(540, 180, 50, 50);
    ui->helpButton->setIconSize(QSize(50, 50));
    ui->helpButton->setCursor(QCursor(Qt::PointingHandCursor));
    connect(ui->helpButton, &QPushButton::clicked, this, &MainWindow::helpGame);

    ui->exitButton->setButtonIcons(QIcon(":/buttons/exit1.PNG"),
                                   QIcon(":/buttons/exit2.PNG"), QIcon(":/buttons/exit2.PNG"));
    ui->exitButton->setGeometry(460, 320, 165, 65);
    ui->exitButton->setIconSize(QSize(180, 80));
    ui->exitButton->setCursor(QCursor(Qt::PointingHandCursor));
    connect(ui->exitButton, &QPushButton::clicked, this, &MainWindow::exitGame);

    ui->settingButton->setGeometry(600, 180, 50, 50);
    ui->settingButton->setStyleSheet("border-top:1px transparent; "
                                  "border-bottom:1px transparent; "
                                  "border-right:7px transparent; "
                                  "border-left:7px transparent; "
                                  "height:20px; ");
    ui->settingButton->setIconSize(QSize(50, 50));
    ui->settingButton->setCursor(QCursor(Qt::PointingHandCursor));
    ui->settingButton->setButtonIcons(QIcon(":/buttons/setting.png"),
                                      QIcon(":/buttons/setting.png"), QIcon(":/buttons/setting.png"));
    connect(ui->settingButton, &QPushButton::clicked, this, &MainWindow::settingGame);
}

// TODO: .....
void MainWindow::triggerMenu(QAction *act)
{
    if (act->text() == tr("&Play"))
        playGame();

    else if (act->text() == tr("&Exit"))
        exitGame();

    else if (act->text() == tr("&New"))
        playGame();

    else if (act->text() == tr("&Show Main Page"))
    {
        music->stop();
        hide();

        MainWindow *w = new MainWindow;
        w->show();
    }

    else if (act->text() == tr("&Help") || act->text() == tr("&About"))
    {
        Help *help = new Help();
        help->setAttribute(Qt::WA_DeleteOnClose);
        int ret = help->exec();
        if (ret == QDialog::Accepted)
            return;
        else
            return;
    }
}

void MainWindow::triggerToolBar(QAction *act)
{
    if (act->text().compare(actionToolBar1->text()) == 0)
        playGame();

    else if (act->text().compare(actionToolBar2->text()) == 0)
        exitGame();

}

void MainWindow::playGame()
{
    emit ui->loadingWidget->generateLoadingWidget();

    actionToolBar1->setEnabled(false);
    act[0]->setEnabled(false);

    //act[0]->hover();
}

void MainWindow::exitGame()
{
    ExitDialog *dialog = new ExitDialog(this);
    dialog->setAttribute(Qt::WA_DeleteOnClose);
    int ret = dialog->exec();
    if (ret == QDialog::Accepted)
    {
        exit(0);
    }
    else
        return;
}

void MainWindow::settingGame()
{
    music->stop();
    Setting *setting = new Setting(this);
    setting->setAttribute(Qt::WA_DeleteOnClose);
    int ret = setting->exec();
    if (ret == QDialog::Accepted)
        return;
    else
        return;
}

void MainWindow::helpGame()
{
    Help *help = new Help();
    help->setAttribute(Qt::WA_DeleteOnClose);
    int ret = help->exec();
    if (ret == QDialog::Accepted)
        return;
    else
        return;
}

void MainWindow::playMusic()
{
    playlist = new QMediaPlaylist();
    playlist->addMedia(QUrl("qrc:/music/bgd_music.mp3"));
    playlist->setPlaybackMode(QMediaPlaylist::Loop);

    music = new QMediaPlayer();
    music->setPlaylist(playlist);
    music->play();
}
