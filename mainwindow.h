#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>
#include <QList>
#include <QMenuBar>
#include <QMediaPlaylist>
#include <QMediaPlayer>

#include "loadingwidget.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void playMusic();

    QLabel *titleBar;
    QPushButton *max;
    QPushButton *min;
    QPushButton *close;

    QMenu *menu[6];
    QAction *act[6];
    QMenuBar *menuBar;
    QToolBar *toolBar;
    QActionGroup *toolBarActionGroup;
    QAction *actionToolBar1;
    QAction *actionToolBar2;

public slots:
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *event);

    void clickMax();
    void clickMin();
    void clickClose();
    void createMenuBar();
    void createToolBar();
    void createButtons();
    void triggerMenu(QAction *act);
    void triggerToolBar(QAction *act);
    void playGame();
    void exitGame();
    void settingGame();
    void helpGame();

private:
    Ui::MainWindow *ui;
    bool m_bPressed;
    QPoint m_point;
    LoadingWidget *loadingWidget;
    QMediaPlayer *music;
    QMediaPlaylist *playlist;

};

#endif // MAINWINDOW_H
