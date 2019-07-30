#ifndef LOADINGWIDGET_H
#define LOADINGWIDGET_H

#include "game.h"

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QStackedWidget>
#include <QProgressBar>
#include <QLabel>
#include <QCommandLinkButton>

namespace Ui {
class MainWindow;
}

class LoadingWidget : public QStackedWidget
{
    Q_OBJECT

public:
    explicit LoadingWidget(QWidget *parent = nullptr, Ui::MainWindow *ui = nullptr);
    virtual ~LoadingWidget();

    static int counter;
    Ui::MainWindow *ui;

public slots:
    void generateLoadingWidget();
    void loadingGame();
    void updateProgress();
    void showSubtitle();

private slots:
    void on_commandLinkButton_clicked();

private:
    QTimer *timer;
    QLabel *label2;
    QCommandLinkButton *commandLinkButton;
    QWidget *widget;

    Game *game;
};

#endif // LOADINGWIDGET_H
