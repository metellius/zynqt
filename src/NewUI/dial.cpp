#include "dial.h"
#include <QMouseEvent>
#include <QtDebug>

Dial::Dial(QWidget *parent)
	: QDial(parent),
	m_originalMouseY(-1)
{
	setMouseTracking(false);
}

void Dial::mousePressEvent(QMouseEvent* event)
{
	m_originalMouseY = event->y();
	m_originalValueOnPress = value();
	//event->accept();
	//QDial::mousePressEvent(event);
}

void Dial::mouseReleaseEvent(QMouseEvent* event)
{
	//event->accept();
	//QDial::mouseReleaseEvent(event);
}

void Dial::mouseMoveEvent(QMouseEvent* event)
{
	event->accept();
	if (m_originalMouseY != -1) {
		setValue(m_originalValueOnPress + 
				float( m_originalMouseY - event->y())
				* 0.5
				);
	}
}
