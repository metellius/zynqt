#include "lfobox.h"

LFOBox::LFOBox(QWidget *parent)
	: UnitBox(parent)
{
	setupUi(this);
}

void LFOBox::setSources(LFOParams *params)
{
	//this->freq->setSource(&params->Pfreq);
	this->intensity->setSource(&params->Pintensity);
	this->start->setSource(&params->Pstartphase);
	this->delay->setSource(&params->Pdelay);
	this->stretch->setSource(&params->Pstretch);
	//this->ar->setSource(&params->
	//this->fr->setSource(&params->
}

#include "lfobox.moc"
