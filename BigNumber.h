#ifndef BIGNUMBER_H
#define BIGNUMBER_H
#include<iostream>
#include<cmath>
#include<string>
using namespace std;
class BigNumber{
private:
	int len; //大数长度，如果是整数len=1
	int pls;//存储正负号
	int* Num; //第一位存储整数位，后面每一位对应一位小数位
public:
	BigNumber(){len=1;pls=1;Num=new int [1];Num[0]=0;} //构造函数
	BigNumber (const double x,int lenth);	 //将一个double类型的变量转化为有len长度的大数
	BigNumber(const string);				 //将一个string转换为BigNumber
	BigNumber(const BigNumber &);			 //拷贝构造函数
	BigNumber(const BigNumber &,const int lenth);    //复制长度为lenth的大数 
	~BigNumber(){len=0;pls=0;delete [] Num;}		 //析构函数

	BigNumber &operator=(const BigNumber &);		//重载赋值运算符，大数之间幅值。
	BigNumber operator+(const BigNumber &)const;    //重载加法运算符，两个大数之间的相加运算
	BigNumber operator+(const double x)const{		//重载加法运算符，大数+double型的相加运算
		BigNumber X(x,len);
		return (*this)+X;
	}											 
	BigNumber operator-(const BigNumber &)const;    //重载减法运算符，两个大数之间的相减运算
	BigNumber operator-(const double x)const{		//重载减法运算符，大数-double型的相加运算
		BigNumber X(x,len);
		return (*this)-X;
	}
	BigNumber operator*(const int)const;         //重载乘法运算符，大数乘上一个int
	BigNumber operator*(const BigNumber &)const; //重载乘法运算符，两个大数之间的乘法运算
	BigNumber operator/(const int)const;		 //重载除法运算符，一个大数除以一个整数
	BigNumber operator/(const BigNumber&)const;	 //重载除法运算符，大数除法
	BigNumber operator^(const int)const;		 //重载乘方运算符，允许幂指数为负数

	bool operator==(const BigNumber &)const;	//重载比较运算符
	bool operator==(const double)const;
	bool operator>=(const BigNumber &)const;     
	bool operator>=(const double)const;     
	bool operator>(const BigNumber &)const;
	bool operator>(const double)const;
	
	BigNumber IncreaseBit(const int Len)const;	     //在大数后补零，直到大数有Len的长度
	BigNumber Reciprocal()const;				 //大数的倒数
	BigNumber Abs()const;						//大数的绝对值
	string BigNumber2Str();					//大数转换为字符串
	BigNumber LnxTaylor(const int lenth);					//taylor ln函数
	BigNumber LnxNumIntegration(const int lenth);			//Numberical Integration ln函数
	BigNumber LnxRationalApproximation(const int lenth);	//RationalApproximation  ln函数  选做
	void print();  //输出大数
protected:
	BigNumber _plus1(const BigNumber &) const; //两个正数相加
	BigNumber _plus2(const BigNumber &) const;	//一个正数加上一个负数
	BigNumber _dec(const BigNumber &)const;		//两个正数相减，且大数减小数
};
BigNumber Sqrt2(const int len);			//计算根号的值，并返回结果的大数
BigNumber Ln2(const int len);			//计算Ln2的值，并返回结果的大数

#endif