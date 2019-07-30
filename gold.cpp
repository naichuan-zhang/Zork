#include "gold.h"

Gold::Gold(QWidget *parent, Ui::MainWindow *ui)
    : ui(ui)
{

}

Gold::Gold(const string description)
    : description (description)
{
    this->setPixmap(QPixmap(":/game/gold.JPG"));
    this->setPos(350, 250);
    this->show();
}

void Gold::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    text = QString::fromStdString(getDescription());
    ui->textEdit2->setPlainText(text);

    QGraphicsItem::mousePressEvent(event);
}
