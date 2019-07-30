#include "logs.h"

Logs::Logs(QWidget *parent, Ui::MainWindow *ui)
    : ui(ui)
{

}

Logs::Logs(const string description)
    : description (description)
{
    this->setPixmap(QPixmap(":/game/logs.jpg"));
    this->setPos(350, 250);
}

void Logs::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    text = QString::fromStdString(getDescription());
    ui->textEdit2->setPlainText(text);

    QGraphicsItem::mousePressEvent(event);
}
