#include "custbutton.h"

#include <Qt>

CustButton::CustButton(QWidget *parent)
    : QPushButton(parent)
{
    setDown(false);
    setFocusPolicy(Qt::NoFocus);
}

CustButton::~CustButton()
{

}

void CustButton::enterEvent(QEvent *event)
{
    if (isEnabled() && !m_FocusIcon.isNull())
        setIcon(m_FocusIcon);
}

void CustButton::leaveEvent(QEvent *event)
{
    if (isEnabled())
        setIcon(m_NormalIcon);
}

void CustButton::mousePressEvent(QMouseEvent *event)
{
    if (isEnabled() && !m_PressIcon.isNull())
        setIcon(m_PressIcon);

    QPushButton::mousePressEvent(event);
}

void CustButton::mouseReleaseEvent(QMouseEvent *event)
{
    if (isEnabled() && m_FocusIcon.isNull())
        setIcon(m_FocusIcon);

    QPushButton::mouseReleaseEvent(event);
}

void CustButton::setButtonIcons(const QIcon &normal, const QIcon &focus, const QIcon &press)
{
    m_NormalIcon = normal;
    m_FocusIcon = focus;
    m_PressIcon = press;
    setIcon(m_NormalIcon);
}
