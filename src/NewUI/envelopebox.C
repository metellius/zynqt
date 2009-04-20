#include "envelopebox.h"

EnvelopeBox::EnvelopeBox(QWidget *parent)
	: UnitBox(parent)
{
	setupUi(this);
}

void EnvelopeBox::setSources(EnvelopeParams *params)
{
	this->a_dt->setSource(&params->PA_dt);
	this->d_dt->setSource(&params->PD_dt);
	this->s_val->setSource(&params->PS_val);
	this->r_dt->setSource(&params->PR_dt);
}

#include "envelopebox.moc"
