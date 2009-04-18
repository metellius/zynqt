#include <QMainWindow>
#include "../Misc/Master.h"
#include "ui_masterUI.h"

#ifndef _MASTERUI_H_
#define _MASTERUI_H_

class MasterUI : public QMainWindow, Ui::MainWindow
{
	Q_OBJECT

	public:
		MasterUI(Master *master_,int *exitprogram_);

	private slots:
		void on_action_Quit_triggered();
		void on_masterVolume_valueChanged(int value);
		void on_partSelector_valueChanged(int value);

		void on_selectInstrument_clicked();

	private:
		void simpleRefresh();
		void clearAllParameters();


		int *Pexitprogram;
		Master *m_master;

		int ninseff,npart;
		int nsyseff;
		//SysEffSend *syseffsend[NUM_SYS_EFX][NUM_SYS_EFX];
		//VirKeyboard *virkeyboard;
		//ConfigUI *configui;
		int swapefftype;
		char masterwindowlabel[100];
		//Panellistitem *panellistitem[NUM_MIDI_PARTS];
		
		class BankUI *m_bankUI;
};


#endif /* include _MASTERUI_H_ */
