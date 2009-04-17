#include "masterui.h"

MasterUI::MasterUI(Master *master_,int *exitprogram_)
	: QMainWindow(NULL),
	Pexitprogram(exitprogram_),
	m_master(master_)

{
	setupUi(this);
}

void MasterUI::on_quitButton_clicked()
{
	*Pexitprogram = 1;
}

void MasterUI::on_masterVolume_valueChanged(int value)
{
	m_master->setPvolume(value);
}

#include "masterui.moc"
