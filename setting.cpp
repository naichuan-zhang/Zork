#include "setting.h"
#include "ui_setting.h"

#include <QMediaPlayer>
#include <QFileDialog>

Setting::Setting(QWidget *parent)
    : QDialog(parent), ui(new Ui::Setting)
{
    ui->setupUi(this);
    mMediaPlayer = new QMediaPlayer(this);

    connect(mMediaPlayer, &QMediaPlayer::positionChanged, [&](qint64 position) {
        ui->progress->setValue((qint64)position);
    });

    connect(mMediaPlayer, &QMediaPlayer::durationChanged, [&](qint64 duration) {
        ui->progress->setMaximum((qint64)duration);
    });
}

Setting::~Setting()
{
    delete ui;
}

void Setting::on_open_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this, "Open");
    if (filename.isEmpty())
        return;

    mMediaPlayer->setMedia(QUrl::fromLocalFile(filename));
    mMediaPlayer->setVolume(ui->volume->value());
    on_play_clicked();
}

void Setting::on_play_clicked()
{
    mMediaPlayer->play();
}

void Setting::on_pause_clicked()
{
    mMediaPlayer->pause();
}

void Setting::on_stop_clicked()
{
    mMediaPlayer->stop();
}

void Setting::on_mute_clicked()
{
    if (ui->mute->text() == "Mute")
    {
        mMediaPlayer->setMuted(true);
        ui->mute->setText("Unmute");
    }

    else
    {
        mMediaPlayer->setMuted(false);
        ui->mute->setText("Mute");
    }
}

void Setting::on_volume_valueChanged(int value)
{
    mMediaPlayer->setVolume(value);
}
