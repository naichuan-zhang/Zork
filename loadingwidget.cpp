#include "loadingwidget.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "textticker.h"
#include "game.h"

#include <QVBoxLayout>
#include <QDebug>
#include <QLabel>
#include <QTimer>
#include <QMainWindow>
#include <QResizeEvent>
#include <QSize>

LoadingWidget::LoadingWidget(QWidget *parent, Ui::MainWindow *ui) :
    QStackedWidget(parent)
{
    this->ui = ui;
}

LoadingWidget::~LoadingWidget()
{

}

void LoadingWidget::generateLoadingWidget()
{
    QProgressBar *progressBar = findChild<QProgressBar*> ("progressBar");
    QLabel *label = findChild<QLabel*> ("label");

    label->setText(tr("Loading ..."));
    label->setGeometry(310, 240, 140, 40);
    label->setAlignment(Qt::AlignCenter);
    label->setStyleSheet("QLabel {color:white;font:30px;font-family:Arial;text-align:center;}");

    progressBar->setValue(0);
    progressBar->setRange(0, 100);
    progressBar->setGeometry(170, 180, 480, 30);
    progressBar->setStyleSheet("QProgressBar {color:black;font:30px;text-align:center; }"
                               "QProgressBar::chunk {background-color: rgb(202, 165, 14);}");

    setStyleSheet("background-image: url(:/images/bgd.jpg) no-repeat; ");
    setGeometry(0, 30, 800, 540);
    setCurrentIndex(0);
    QWidget *secondPage = new QWidget;
    addWidget(secondPage);
    show();

    loadingGame();
}

void LoadingWidget::loadingGame()
{
    this->timer = new QTimer;
    timer->setInterval(10000);
    timer->start(100);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateProgress()));
}

void LoadingWidget::updateProgress()
{
    QProgressBar *progressBar = findChild<QProgressBar*> ("progressBar");
    int currentVal = progressBar->value();
    currentVal += 3;
    progressBar->setValue(currentVal);

    if (currentVal > 100 && timer->isActive())
    {
        showSubtitle();

        emit timer->stop();
        delete timer;
    }
}

void LoadingWidget::showSubtitle()
{
    setCurrentIndex(1);
    label2 = findChild<QLabel*> ("label2");
    label2->setStyleSheet("QLabel {color:yellow;text-align:center;}");

    commandLinkButton = findChild<QCommandLinkButton*> ("commandLinkButton");
    commandLinkButton->setText(tr("Skip"));
    //commandLinkButton->setDescription(tr("Skip the introduction"));
    commandLinkButton->setEnabled(TRUE);
    commandLinkButton->setStyleSheet("QCommandLinkButton {color:white;text-align:center;background:yellow;}");
    commandLinkButton->setGeometry(270, 300, 230, 60);

    connect(commandLinkButton, &QCommandLinkButton::clicked, this, &LoadingWidget::on_commandLinkButton_clicked);
}

void LoadingWidget::on_commandLinkButton_clicked()
{
    setCurrentIndex(2);

    widget = currentWidget();

    widget->setObjectName("myWidget");
    widget->setGeometry(0, 0, 800, 540);
    widget->setStyleSheet("QWidget#myWidget"
             "{border-image:url(':/images/bgd_play.jpg')}");
    widget->show();

    ui->imageLabel->setStyleSheet("QLabel#imageLabel {background:transparent;}");
    ui->textLabel->setStyleSheet("QLabel#textLabel {color:blue; background:transparent;}");

    Game *game = new Game(ui->loadingWidget, ui);
    game->play();
}
