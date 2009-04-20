#include <QDialog>
#include "../Misc/Master.h"
#include "ui_addnoteui.h"

#ifndef _ADDNOTEUI_H_
#define _ADDNOTEUI_H_

class AddNoteUi : public QDialog, Ui::addnoteui
{
	Q_OBJECT

	public:
		AddNoteUi(Master *master, int partIndex, int kitIndex);

	private slots:
		//void simpleRefresh();

	private:
		int *Pexitprogram;
		Master *master;
};


#endif /* include _ADDNOTEUI_H_ */
