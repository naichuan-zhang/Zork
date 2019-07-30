#include "textticker.h"

#include <QPainter>
#include <QTimer>

TextTicker::TextTicker(QWidget *parent)
    : QLabel(parent)
{
    setMinimumWidth(200);
    setMinimumHeight(40);
    setAlignment(Qt::AlignHCenter);
    setWordWrap(true);
    setFrameStyle(QFrame::Panel | QFrame::Sunken);
    setGeometry(0, 50, 800, 220);
    setStyleSheet("QLabel {color:white;text-align:center;}");


    m_curIndex = 0;
    m_showText = "There is a legend that there is a forest in Ireland. A group of rich Irish goblins live inside with their gold. Only those who have the courage and patience can find the treasures of the goblins. Now there is a chance for you to get the treasures. WIN THE GAME!!!!";
    m_charWidth = fontMetrics().width("a");

    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &TextTicker::updateIndex);
    timer->start(100);

}

TextTicker::~TextTicker()
{

}

void TextTicker::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawText(0, 70, m_showText.mid(m_curIndex));
    painter.drawText(width() - m_charWidth * m_curIndex, 150, m_showText.left(m_curIndex));

    QLabel::paintEvent(event);
}

void TextTicker::updateIndex()
{
    update();
    m_curIndex++;
    if (m_curIndex * m_charWidth > width())
        m_curIndex = 0;
}
