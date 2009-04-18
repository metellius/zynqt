#include "bankui.h"

#include <QtDebug>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QTableWidget>

static const int verticalSlots = 32;
static const int horizontalSlots = 5;

BankUI::BankUI(QWidget *parent, Master *master, int *npart)
	: QDialog(parent),
	master(master),
	npart(npart)
{
	currentBank = new Bank();
	currentBank->rescanforbanks();

	for (int i=1;i<MAX_NUM_BANKS;i++) {
		if (currentBank->banks[i].name!=NULL)  {
			const char* dir = currentBank->banks[i].dir;

			int ret = currentBank->loadbank(dir);

			qDebug() << "Loading " << currentBank->banks[i].name << " returned " << ret;
			break;
		}
	}

	table = new QTableWidget(this);
	table->setColumnCount(horizontalSlots);
	table->setRowCount(verticalSlots);
	for (int x = 0; x < horizontalSlots; x++) {
		for (int y = 0; y < verticalSlots; y++) {
			table->setItem(y, x, new QTableWidgetItem("hei"));
		}
	}
	connect(table, SIGNAL(currentCellChanged(int, int, int, int)),
			this, SLOT(slotCurrentCellChanged(int, int, int, int)));
	table->setSelectionMode(QAbstractItemView::SingleSelection);

	QVBoxLayout *vlayout = new QVBoxLayout(this);
	vlayout->addWidget(table);
	setLayout(vlayout);

	refreshCurrentBank();


#if 0
	QPushButton *bankSlots[horizontalSlots][verticalSlots];

	QHBoxLayout *hlayout = new QHBoxLayout(this);

	for (int x = 0; x < horizontalSlots; x++) {

	QVBoxLayout *vlayout = new QVBoxLayout(this);
		vlayout->setSpacing(0);

		for (int y = 0; y < verticalSlots; y++) {

			bankSlots[x][y] = new QPushButton(this);
			bankSlots[x][y]->setContentsMargins(0, 0, 0, 0);
			vlayout->addWidget(bankSlots[x][y]);

		}

		hlayout->addLayout(vlayout);
	}
	setLayout(hlayout);
#endif

}

void BankUI::slotCurrentCellChanged(int, int, int row, int column)
{
	int id = column * verticalSlots + row;
	if (id < 0) return;
	qDebug() << "Loading from " << id;

    pthread_mutex_lock(&master->mutex);
	currentBank->loadfromslot(id,master->part[*npart]);
    pthread_mutex_unlock(&master->mutex);
    master->part[*npart]->applyparameters();
	emit changedInstrument();
}

void BankUI::refreshCurrentBank()
{
	for (int x = 0; x < horizontalSlots; x++) {
		for (int y = 0; y < verticalSlots; y++) {
			const char *name = currentBank->getname(x * verticalSlots + y);
			table->setItem(y, x, new QTableWidgetItem(name));
		}
	}

}

BankUI::~BankUI()
{
	delete currentBank;
}

#include "bankui.moc"
