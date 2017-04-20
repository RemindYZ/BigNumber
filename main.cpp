//*****************************************/
//                                        */
//        自43 赵洋 2014011487            */
//                                        */
//*****************************************/
//readme.txt
//
//环境：
//win10+VS2012+Qt5.2.0 C++
//
//输入：按照助教的要求，可以输入[1,100]之间
//任意五位有效数字的实数，linedit设定为6位长度
//精度：设定为1到25之间任意值
//方法：泰勒展开，龙贝格算法，有理逼近
//速度：基本都是秒出，龙贝格在数据较大时会出现1s不到的延迟
//输出：方法+结果，会累积输出，即下次的输出不会覆盖上一次的结果
//操作方法：输入数据，选择算法，点击计算。
//可以重复输入
//clear键可以清空全部输入输出
//
//没了。。
//
#include "lnx_numana2nd.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Lnx_NumAna2nd w;
	w.show();
	return a.exec();
}
