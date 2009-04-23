#include "dial.h"
#include <QMouseEvent>
#include <QtDebug>
#include <QPaintEvent>
#include <QPainter>
#include <QConicalGradient>
#include <math.h>

//drawstyles: 0 - piechart
//            1 - rotated dial
static int drawStyle = 1;

Dial::Dial(QWidget *parent)
	: QDial(parent),
	m_originalMouseY(-1),
	m_source(0),
	m_realtypeSource(0)
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

	float v = (float(value()) / (maximum() - minimum()));

	if (drawStyle == 0) {
		QConicalGradient grad(r.center(), 270 - 13);
		p.setBrush(QColor(Qt::white));

		p.drawEllipse(r);

		grad.setColorAt(1, Qt::yellow);
		grad.setColorAt(0.5, QColor(255, 128, 0));
		grad.setColorAt(0, Qt::red);
		p.setBrush(grad);
		p.drawPie(r, 255*16, -v * 16);
		//p.drawPoint(10 * 
	} else if (drawStyle == 1) {

		//p.setBrush(QColor(Qt::white));

		//center circle
		p.drawEllipse(r);

		p.translate(r.center());

		for (float i = -PI/4; i <= (PI+PI/4); i+=PI/6) {

			//draw lots of markers
			p.drawLine(
					r.width() * 0.4 * cos(i), -r.height() * 0.4 * sin(i),
					r.width() * 0.5 * cos(i), -r.height() * 0.5 * sin(i));

			qDebug() << r.size();

		}

		QRect smallRect = r;
		smallRect.setSize(smallRect.size() * 0.6);
		smallRect.moveCenter(QPoint(0, 0));

		p.setBrush(palette().alternateBase());
		p.drawPie(smallRect, 225*16, -v * 270* 16);
		//p.rotate(v);

		//QPoint point = r.center();
		//point.setY(point.y() - r.height() / 2);

		//p.drawEllipse(QPoint(0, r.height() / 3), 4, 4);

	}

}

void Dial::setSource(unsigned char *source)
{
	m_source = source;
	setValue(*source);
	m_realtypeSource = NULL;
}

void Dial::setSource(REALTYPE *realtypeSource)
{
	m_realtypeSource = realtypeSource;
	setValue((int)(*realtypeSource * 127.0));
	m_source = NULL;
}

void Dial::slotUpdateSource()
{
	if (m_source) {
		*m_source = (unsigned char)value();
	} else if (m_realtypeSource)
		*m_realtypeSource = (REALTYPE)(value() / 127.0);
}

#include "dial.moc"
