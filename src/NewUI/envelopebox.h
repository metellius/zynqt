#ifndef _ENVELOPEBOX_H_
#define _ENVELOPEBOX_H_

#include "unitbox.h"
#include "ui_envelopebox.h"
#include "../Misc/Master.h"

class EnvelopeBox : public UnitBox, Ui::EnvelopeBox
{
	Q_OBJECT

	public:
		EnvelopeBox(QWidget *parent=NULL);
		void setSources(EnvelopeParams* params);

};

#endif /* ifndef _ENVELOPEBOX_H_ */
