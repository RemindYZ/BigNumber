#include "lnx_numana2nd.h"
#include<time.h>
#include <sstream>

string DoubleToString(double d){
	string str;
	stringstream ss;
	ss<<d;
	ss>>str;
	return str;
}

Lnx_NumAna2nd::Lnx_NumAna2nd(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	//设置按钮组，保证每次只能选择其中一个
	//初始选择Taylor展开
	ui.buttonGroup->setId(ui.Taylor,0);
	ui.buttonGroup->setId(ui.NumIntegration,1);
	ui.buttonGroup->setId(ui.RationalApproximation,2);
	ui.Taylor->setChecked(true);
}

Lnx_NumAna2nd::~Lnx_NumAna2nd()
{

}

void Lnx_NumAna2nd::Caculate(){
	int CaculateType=ui.buttonGroup->checkedId();
	QString input=ui.Input->text();
	BigNumber Input(input.toStdString().c_str());
	Input=Input.IncreaseBit(8);//拓展初始位数，保证计算精度和速度
	int lenth=ui.lenth->value()+1;
	BigNumber Result;
	string out;
	QString Output;
	clock_t start_time=clock();
	//方法选择
	switch(CaculateType){
	case 0:Result=Input.LnxTaylor(lenth);out="Taylor: ";break;
	case 1:Result=Input.LnxNumIntegration(lenth);out="NumberIntegration: ";break;
	case 2:Result=Input.LnxRationalApproximation(lenth);out="RationalApproximation: ";break;
	}
	clock_t end_time=clock();
	double t=static_cast<double>(end_time-start_time)/CLOCKS_PER_SEC*1000;
	string R="TimeCost: "+DoubleToString(t)+"ms";
	//输出
	Output=QString::fromStdString(out);
	ui.textBrowser->append(Output);
	Output=QString::fromStdString(Result.BigNumber2Str());
	ui.textBrowser->append(Output);
	Output=QString::fromStdString(R);
	ui.textBrowser->append(Output);
}

void Lnx_NumAna2nd::Clear(){
	ui.Input->clear();
	ui.lenth->setValue(1);
	ui.textBrowser->clear();
}
