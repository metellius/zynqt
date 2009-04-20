#include "dial.h"
#include <QMouseEvent>
#include <QtDebug>
#include <QPaintEvent>
#include <QPainter>
#include <QConicalGradient>

Dial::Dial(QWidget *parent)
	: QDial(parent),
	m_originalMouseY(-1),
	m_source(0)
{
	setMouseTracking(false);
	connect(this, SIGNAL(valueChanged(int)),
			this, SLOT(slotUpdateSource()));
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

void Dial::paintEvent(class QPaintEvent *event)
{
	QPainter p(this);

	QRect r = rect();
	if (r.width() < r.height())
		r.setHeight(r.width());
	else if (r.height() < r.width())
		r.setWidth(r.height());

	r.setSize(r.size() * 0.9);

	r.moveCenter(rect().center());
	p.setBrush(QColor(Qt::white));

	p.drawEllipse(r);

	float v = (float(value()) / (maximum() - minimum())) * 330 * 16 + 15*16;

	QConicalGradient grad(r.center(), 270 - 13);
	grad.setColorAt(1, Qt::yellow);
	grad.setColorAt(0.5, QColor(255, 128, 0));
	grad.setColorAt(0, Qt::red);
	p.setBrush(grad);
	p.drawPie(r, 255*16, -v);

	//p.drawPoint(10 * 

}

void Dial::setSource(unsigned char *source)
{
	m_source = source;
	setValue(*source);
}

void Dial::slotUpdateSource()
{
	if (m_source) {
		*m_source = (unsigned char)value();
	}
}

#include "dial.moc"
