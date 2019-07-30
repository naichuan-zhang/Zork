#ifndef SETTING_H
#define SETTING_H

#include <QDialog>
#include <QMediaPlayer>

namespace Ui {
class Setting;
}

class QMediaPlayer;
class Setting : public QDialog
{
    Q_OBJECT

public:
    explicit Setting(QWidget *parent = nullptr);
    ~Setting();

private slots:
    void on_open_clicked();
    void on_play_clicked();
    void on_pause_clicked();
    void on_stop_clicked();
    void on_mute_clicked();
    void on_volume_valueChanged(int value);

private:
    Ui::Setting *ui;
    QMediaPlayer *mMediaPlayer;
};

#endif // SETTING_H
