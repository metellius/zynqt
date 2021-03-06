#include "masterui.h"
#include "bankui.h"
#include "addnoteui.h"
#include <QtDebug>

MasterUI::MasterUI(Master *master_,int *exitprogram_)
	: QMainWindow(NULL),
	Pexitprogram(exitprogram_),
	master(master_),
	m_bankUI(NULL)

{
	setupUi(this);


	ninseff=0;
	nsyseff=0;
	npart=0;
	swapefftype=0;

	QList<Dial*> autoConnectDials =
		QList<Dial*>()
		<< partVolume
		<< partPan
		<< masterVolume;

	foreach(Dial* dial, autoConnectDials) {
		connect(dial, SIGNAL(valueChanged(int)),
				this, SLOT(slotDialChanged(int)));
	}

	simpleRefresh();

	//FIXME
	on_editInstrument_clicked();

}

void MasterUI::on_partSelector_valueChanged(int value)
{
	npart = value;
	simpleRefresh();
}

void MasterUI::simpleRefresh()
{
	partEnabled->setChecked(master->part[npart]->Penabled);
	partFrame->setEnabled(master->part[npart]->Penabled);

	partVolume->setValue(master->part[npart]->Pvolume);
	partPan->setValue(master->part[npart]->Ppanning);
	partChannelReceiver->setCurrentIndex(master->part[npart]->Prcvchn);

	if (master->part[npart]->Pname[0]!=0) currentInstrument->setText((char *)master->part[npart]->Pname);
	else currentInstrument->setText("Click here to load an instrument");

	//simplelistitemgroup->redraw();
	//simplepartportamento->value(master->part[npart]->ctl.portamento.portamento);
	//simpleminkcounter->value(master->part[npart]->Pminkey);
	//simplemaxkcounter->value(master->part[npart]->Pmaxkey);

	//simplepartkeyshiftcounter->value(master->part[npart]->Pkeyshift-64);
	//simplesyseffsend->value(master->Psysefxvol[nsyseff][npart]);}

}
void MasterUI::on_editInstrument_clicked()
{
	(new AddNoteUi(master, npart, 0))->show();
}

void MasterUI::on_selectInstrument_clicked()
{
	if (!m_bankUI) {
		m_bankUI = new BankUI(this, master, &npart);
		connect(m_bankUI, SIGNAL(changedInstrument()),
				this, SLOT(simpleRefresh()));
	}
	m_bankUI->show();

#if 0
	int n=o->value();
	char *dirname=bank->banks[n].dir;
	if (dirname==NULL) return;

	if (bank->loadbank(dirname)==2)
		fl_alert("Error: Could not load the bank from the directory\\n%s.",dirname);
	for (int i=0;i<BANK_SIZE;i++) bs[i]->refresh();
	refreshmainwindow();
#endif

#if 0
	if ((int)bankui->cbwig->value()!=(npart+1)){
		bankui->cbwig->value(npart+1);
		bankui->cbwig->do_callback();
	};
	bankui->show();
#endif
}

void MasterUI::clearAllParameters()
{

}

void MasterUI::on_action_Quit_triggered()
{
	*Pexitprogram = 1;
}

void MasterUI::on_masterVolume_valueChanged(int value)
{
}

void MasterUI::slotDialChanged(int value)
{
	if (sender() == partVolume)
		master->part[npart]->setPvolume(value);
	else if (sender() == partPan)
		master->part[npart]->setPpanning(value);
	else if (sender() == masterVolume)
		master->setPvolume(value);
	else
		qDebug() << "Unknown widget triggered slotDialChanged slot.";

}

#include "masterui.moc"
