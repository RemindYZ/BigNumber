#ifndef BIGNUMBER_H
#define BIGNUMBER_H
#include<iostream>
#include<cmath>
#include<string>
using namespace std;
class BigNumber{
private:
	int len; //�������ȣ����������len=1
	int pls;//�洢������
	int* Num; //��һλ�洢����λ������ÿһλ��ӦһλС��λ
public:
	BigNumber(){len=1;pls=1;Num=new int [1];Num[0]=0;} //���캯��
	BigNumber (const double x,int lenth);	 //��һ��double���͵ı���ת��Ϊ��len���ȵĴ���
	BigNumber(const string);				 //��һ��stringת��ΪBigNumber
	BigNumber(const BigNumber &);			 //�������캯��
	BigNumber(const BigNumber &,const int lenth);    //���Ƴ���Ϊlenth�Ĵ��� 
	~BigNumber(){len=0;pls=0;delete [] Num;}		 //��������

	BigNumber &operator=(const BigNumber &);		//���ظ�ֵ�����������֮���ֵ��
	BigNumber operator+(const BigNumber &)const;    //���ؼӷ����������������֮����������
	BigNumber operator+(const double x)const{		//���ؼӷ������������+double�͵��������
		BigNumber X(x,len);
		return (*this)+X;
	}											 
	BigNumber operator-(const BigNumber &)const;    //���ؼ������������������֮����������
	BigNumber operator-(const double x)const{		//���ؼ��������������-double�͵��������
		BigNumber X(x,len);
		return (*this)-X;
	}
	BigNumber operator*(const int)const;         //���س˷����������������һ��int
	BigNumber operator*(const BigNumber &)const; //���س˷����������������֮��ĳ˷�����
	BigNumber operator/(const int)const;		 //���س����������һ����������һ������
	BigNumber operator/(const BigNumber&)const;	 //���س������������������
	BigNumber operator^(const int)const;		 //���س˷��������������ָ��Ϊ����

	bool operator==(const BigNumber &)const;	//���رȽ������
	bool operator==(const double)const;
	bool operator>=(const BigNumber &)const;     
	bool operator>=(const double)const;     
	bool operator>(const BigNumber &)const;
	bool operator>(const double)const;
	
	BigNumber IncreaseBit(const int Len)const;	     //�ڴ������㣬ֱ��������Len�ĳ���
	BigNumber Reciprocal()const;				 //�����ĵ���
	BigNumber Abs()const;						//�����ľ���ֵ
	string BigNumber2Str();					//����ת��Ϊ�ַ���
	BigNumber LnxTaylor(const int lenth);					//taylor ln����
	BigNumber LnxNumIntegration(const int lenth);			//Numberical Integration ln����
	BigNumber LnxRationalApproximation(const int lenth);	//RationalApproximation  ln����  ѡ��
	void print();  //�������
protected:
	BigNumber _plus1(const BigNumber &) const; //�����������
	BigNumber _plus2(const BigNumber &) const;	//һ����������һ������
	BigNumber _dec(const BigNumber &)const;		//��������������Ҵ�����С��
};
BigNumber Sqrt2(const int len);			//������ŵ�ֵ�������ؽ���Ĵ���
BigNumber Ln2(const int len);			//����Ln2��ֵ�������ؽ���Ĵ���

#endif