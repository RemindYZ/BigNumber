#ifndef LNX_NUMANA2ND_H
#define LNX_NUMANA2ND_H

#include <QtWidgets/QMainWindow>
#include "ui_lnx_numana2nd.h"
#include "BigNumber.h"
#include<string>
#include<QString>
using namespace std;
class Lnx_NumAna2nd : public QMainWindow
{
	Q_OBJECT

public:
	Lnx_NumAna2nd(QWidget *parent = 0);
	~Lnx_NumAna2nd();

private:
	Ui::Lnx_NumAna2ndClass ui;

private slots:
	void Caculate();
	void Clear();
};

#endif // LNX_NUMANA2ND_H
