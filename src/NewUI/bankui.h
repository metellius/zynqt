#include "../Misc/Master.h"
#include <QDialog>

#ifndef _BANK_H_
#define _BANK_H_

class BankUI : public QDialog
{
	Q_OBJECT
	public:
		BankUI(QWidget *parent, Master *master, int *npart);
		virtual ~BankUI();


	private slots:
		void slotCurrentCellChanged(int, int, int row, int column);
		void refreshCurrentBank();

	signals:
		void changedInstrument();

	private:
		int *npart;
		Master *master;
		Bank *currentBank;
		class QTableWidget *table;

};

#endif /* include _BANK_H_ */
