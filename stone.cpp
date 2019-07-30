#include "stone.h"

Stone::Stone(QWidget *parent, Ui::MainWindow *ui)
    : ui(ui)
{

}

Stone::Stone(const string description)
    : description (description)
{
    this->setPixmap(QPixmap(":/game/stone.jpg"));
    this->setPos(350, 250);
}

void Stone::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    text = QString::fromStdString(getDescription());
    ui->textEdit2->setPlainText(text);

    QGraphicsItem::mousePressEvent(event);
}
