#include "masterui.h"

MasterUI::MasterUI(Master *master_,int *exitprogram_)
	: QMainWindow(NULL),
	Pexitprogram(exitprogram_),
	m_master(master_)

{
	setupUi(this);
}

void MasterUI::on_action_Quit_triggered()
{
	*Pexitprogram = 1;
}

void MasterUI::on_masterVolume_valueChanged(int value)
{
	m_master->setPvolume(value);
}

#include "masterui.moc"
