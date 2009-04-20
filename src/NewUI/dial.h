#include <QDial>

class Dial : public QDial
{
	public:
		Dial(QWidget *parent);

	private:
		void mousePressEvent(class QMouseEvent* event);
		void mouseReleaseEvent(class QMouseEvent* event);
		void mouseMoveEvent(class QMouseEvent* event);
		void paintEvent(class QPaintEvent *event);

		int m_originalMouseY;
		int m_originalValueOnPress;

};
