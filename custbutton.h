#ifndef CUSTBUTTON_H
#define CUSTBUTTON_H

#include <QtGui>
#include <QPushButton>


class CustButton : public QPushButton
{
    Q_OBJECT

public:
    explicit CustButton(QWidget *parent = nullptr);
    virtual ~CustButton();

    void setButtonIcons(const QIcon &normal,
             const QIcon &hover = QIcon(), const QIcon &press = QIcon());

protected:
    virtual void enterEvent(QEvent *event);
    virtual void leaveEvent(QEvent *event);
    virtual void mousePressEvent(QMouseEvent *event);
    virtual void mouseReleaseEvent(QMouseEvent *event);

private:
    QIcon m_NormalIcon;
    QIcon m_FocusIcon;
    QIcon m_PressIcon;

};

#endif // CUSTBUTTON_H
