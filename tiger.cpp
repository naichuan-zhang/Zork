#include "tiger.h"

Tiger::Tiger(QWidget *parent, Ui::MainWindow *ui)
    : ui(ui)
{

}

Tiger::Tiger(const string description)
    : description (description)
{
    this->setPixmap(QPixmap(":/game/tiger.jpg"));
    this->setPos(350, 250);
}

void Tiger::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    text = QString::fromStdString(getDescription());
    ui->textEdit2->setPlainText(text);

    QGraphicsItem::mousePressEvent(event);
}
