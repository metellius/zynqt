#ifndef _DIAL_H_
#define _DIAL_H_

#include <QDial>
#include "../globals.h"

class Dial : public QDial
{
	Q_OBJECT
	public:
		Dial(QWidget *parent);
		void setSource(unsigned char* source);
		void setSource(REALTYPE* source);

	private slots:
		void slotUpdateSource();

	private:
		void mousePressEvent(class QMouseEvent* event);
		void mouseReleaseEvent(class QMouseEvent* event);
		void mouseMoveEvent(class QMouseEvent* event);
		void paintEvent(class QPaintEvent *event);

		int m_originalMouseY;
		int m_originalValueOnPress;
		unsigned char *m_source;
		REALTYPE *m_realtypeSource;

};

#endif /* #ifndef _DIAL_H_ */
