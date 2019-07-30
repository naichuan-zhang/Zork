#include "snake.h"

Snake::Snake(QWidget *parent, Ui::MainWindow *ui)
    : ui(ui)
{

}

Snake::Snake(const string description)
    : description (description)
{
    this->setPixmap(QPixmap(":/game/snake.jpg"));
    this->setPos(350, 250);
}

void Snake::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    text = QString::fromStdString(getDescription());
    ui->textEdit2->setPlainText(text);

    QGraphicsItem::mousePressEvent(event);
}
