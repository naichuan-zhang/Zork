#include "windialog.h"
#include "ui_windialog.h"

#include <QPropertyAnimation>

WinDialog::WinDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WinDialog)
{
    ui->setupUi(this);

    ui->lineEdit->setText(QString("Congratulations! You win the game!"));

    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(on_pushButton_clicked()));
}

WinDialog::~WinDialog()
{
    delete ui;
}

void WinDialog::on_pushButton_clicked()
{
    QPropertyAnimation *animation = new QPropertyAnimation(this, "windowOpacity");
    animation->setDuration(3000);
    animation->setStartValue(1);
    animation->setEndValue(0);
    animation->start();
    connect(animation, SIGNAL(finished()), this, SLOT(close()));

    exit(0);
}
