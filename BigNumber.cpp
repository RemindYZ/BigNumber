#include"BigNumber.h"

//计算根号2的值，保留到len-1位小数
//采用方程求根
BigNumber Sqrt2(const int len){
	BigNumber Result(1.5,len+5);
	BigNumber R(1.6,len+5);
	BigNumber x5(0.5,len+5);
	double AcquireError=0.5*pow(10,-len);
	//方程求根数值计算
	//x(n+1)=-x(n)^2/4+x(n)+0.5
	while((R-Result)>AcquireError){
		R=Result;
		Result=(Result-(Result^2)/4+x5).IncreaseBit(len+1);
	}
	return Result.IncreaseBit(len);
}
//计算ln(2)的值，保留到len-1位小数
//y=2ln(sqrt(2))
BigNumber Ln2(const int len){
	BigNumber x2=Sqrt2(len);
	BigNumber y=x2.LnxTaylor(len);
	return y*2;
}

BigNumber::BigNumber(const double x,int lenth){
	len=lenth;
	pls=x>=0?1:-1;
	Num=new int [lenth];
	double temp = x>0?x:-x;
	int i=0;
	for(i=0;i<len-1;i++){
		Num[i]=(int)temp;
		temp=(temp-Num[i])*10;
	}
	//截断时四舍五入
	Num[i]=(int)temp+(int)(temp-(int)temp>=0.5);
	for(i=len-1;i>=1;i--){
		if(Num[i]>=10){
			Num[i]=Num[i]%10;
			Num[i-1]++;
		}
	}
}

BigNumber::BigNumber(const string s){
	if(s[0]!='-'){
		pls=1;
		int i=1;
		int Int=s[0]-'0';
		for(;i<s.length();i++){
			if(s[i]!='.')
				Int=Int*10+(s[i]-'0');
			else
				break;
		}
		len=s.length()-i;
		if(len!=0){
			Num=new int [len];
			for(int j=0;j<len;j++){
				if(j==0)	Num[j]=Int;
				else Num[j]=s[i+j]-'0';
			}
		}
		else{
			len=1;
			Num=new int [1];
			Num[0]=Int;
		}
	}
	else{
		pls=-1;
		int i=2;
		int Int=s[1]-'0';
		for(;i<s.length();i++){
			if(s[i]!='.')
				Int=Int*10+(s[i]-'0');
			else
				break;
		}
		len=s.length()-i;
		if(len!=0){
			Num=new int [len];
			for(int j=0;j<len;j++){
				if(j==0)	Num[j]=Int;
				else Num[j]=s[i+j]-'0';
			}
		}
		else{
			len=1;
			Num=new int [1];
			Num[0]=Int;
		}
	}
}

BigNumber::BigNumber(const BigNumber & BN){
	len=BN.len;
	pls=BN.pls;
	Num=new int [len];
	for(int i=0;i<len;i++){
		Num[i]=BN.Num[i];
	}
}

BigNumber::BigNumber(const BigNumber& B,const int lenth){
	BigNumber BN=B.IncreaseBit(lenth);
	pls=BN.pls;
	len=lenth;
	Num=new int [lenth];
	int i=0;
	//截断
	if(lenth<BN.len){
		for(;i<=lenth-1;i++)
			Num[i]=BN.Num[i];
	}
	//延长
	else{
		for(;i<lenth;i++)
			Num[i]=i<BN.len?BN.Num[i]:0;
	}
}

BigNumber BigNumber::IncreaseBit(const int Len)const{
	BigNumber Result;
	Result.len=Len;
	Result.pls=pls;
	delete [] Result.Num;
	Result.Num=new int [Len];
	int i=0;
	if(Len>=len){
		for(i=0;i<Len;i++){
			Result.Num[i]=i<len?Num[i]:0;
		}
	}
	else{
		int flag=0;
		if(Num[Len]>=5)
			flag=1;
		for(i=Len-1;i>=1;i--){
			Result.Num[i]=Num[i]+flag;
			if(Result.Num[i]>=10){
				flag=Result.Num[i]/10;
				Result.Num[i] %= 10;
			}
			else{
				flag=0;
			}
		}
		Result.Num[0]=Num[0]+flag;
	}
	return Result;
}

BigNumber& BigNumber::operator=(const BigNumber& Equal){
	if(this==&Equal)
		return *this;
	delete [] Num;
	len=Equal.len;
	pls=Equal.pls;
	Num=new int [len];
	for(int i=0;i<len;i++){
		Num[i]=Equal.Num[i];
	}
	return *this;
}

BigNumber BigNumber::operator+(const BigNumber& Add)const{
	int Len=Add.len>len?Add.len:len;
	BigNumber Result;
	BigNumber ad=(*this).IncreaseBit(Len);
	BigNumber add=Add.IncreaseBit(Len);
	if(ad.pls==1&&add.pls==1)//两个正数相加
		Result=ad._plus1(add);
	else if(ad.pls==1&&add.pls==-1)//正数加上负数
		Result=ad._plus2(add);
	else if(add.pls==1&&ad.pls==-1)//负数加上正数
		Result=add._plus2(ad);
	else{	             //负数加上负数
		ad.pls=1;
		add.pls=1;
		Result=ad._plus1(add)*(-1);
	}
	return Result;
}

BigNumber BigNumber::operator-(const BigNumber& Dec)const{
	return (*this)+Dec*(-1);
}

BigNumber BigNumber::operator*(const int x)const{
	int y=x<0?-x:x;
	BigNumber Result;
	Result.len=len;
	delete [] Result.Num;
	Result.Num=new int [len];
	int temp=0;
	for(int i=len-1;i>=1;i--){
		Result.Num[i]=y*Num[i]+temp;
		temp=Result.Num[i]<10?0:Result.Num[i]/10;
		Result.Num[i]=Result.Num[i]%10;
	}
	Result.Num[0]=y*Num[0]+temp;
	Result.pls=(x*pls>=0)?1:-1;
	return Result;
}

BigNumber BigNumber::operator*(const BigNumber& Mul)const{
	BigNumber Result;
	Result.len=len+Mul.len-1;
	delete [] Result.Num;
	Result.Num=new int [Result.len];
	BigNumber Mul1(*this);
	BigNumber Mul2(Mul);
	int x=Mul1.Num[0],y=Mul2.Num[0];
	Mul1.Num[0]=0;
	Mul2.Num[0]=0;
	int i=Mul1.len-1,j=Mul2.len-1,m=Result.len-1;
	for(;m>=0;m--){
		Result.Num[m]=0;
		for(j=Mul2.len-1;j>=0;j--){
			i=m-j;
			if(i>=0&&i<=Mul1.len-1){
				Result.Num[m]=Result.Num[m]+Mul1.Num[i]*Mul2.Num[j];
			}
		}
	}
	BigNumber R=Result+Mul1*y+Mul2*x;
	int temp=0;
	for(m=R.len-1;m>=1;m--){
		R.Num[m]=R.Num[m]+temp;
		if(R.Num[m]<10)
			temp=0;
		else{
			temp=R.Num[m]/10;
			R.Num[m]=R.Num[m]%10;
		}
	}
	R.Num[0]=R.Num[0]+x*y+temp;
	R.pls=pls*Mul.pls<0?-1:1;
	return R;
}   

BigNumber BigNumber::operator/(const int x)const{
	int y=x<0?-x:x;
	BigNumber Result;
	Result.len=len+5;
	delete [] Result.Num;
	Result.Num=new int [Result.len];
	BigNumber D((*this).IncreaseBit(Result.len));
	int temp=0;
	int i=0;
	for(;i<Result.len;i++){
		Result.Num[i]=(D.Num[i]+10*temp)/y;
		temp=(D.Num[i]+10*temp)%y;
	}
	if(2*temp>=y)
		Result.Num[Result.len-1]=Result.Num[Result.len-1]+1;
	Result.pls=x*pls<0?-1:1;
	return Result;
}

BigNumber BigNumber::operator/(const BigNumber& X)const{
	int a1[20]={0};
	int L1=0;  //L1=lenth of int
	a1[0]=Num[0];
	for(;L1<19;L1++){
		a1[L1+1]=a1[L1]/10;
		a1[L1] %= 10;
		if(a1[L1]==0&&a1[L1+1]==0) break;
	}
	int a2[20]={0};
	int L2=0;  //L1=lenth of int
	a2[0]=X.Num[0];
	for(;L2<19;L2++){
		a2[L2+1]=a2[L2]/10;
		a2[L2] %= 10;
		if(a2[L2]==0&&a2[L2+1]==0) break;
	}
	int x1=L1+len-1;
	int x2=L2+X.len-1;
	int x=x1>x2?x1:x2;
	int *A1=new int [x];
	int *A2=new int [x];
	for(int i=0;i<x;i++){
		if(i<L1){
			A1[i]=a1[L1-1-i];
		}
		else{
			A1[i]=i>=x1?0:Num[i+1-L1];
		}
	}
	for(int i=0;i<x;i++){
		if(i<L2){
			A2[i]=a2[L2-1-i];
		}
		else{
			A2[i]=i>=x2?0:X.Num[i+1-L2];
		}
	}
	int L3=x+6+L1-L2;  //商的长度
	int *A3=new int [L3];
	for(int i=0;i<L3;i++){
		A3[i]=A1[0]/A2[0];
		while(true){
			if(A3[i]==0){
				A1[0]=10*A1[0]+A1[1];
				for(int j=1;j<x-1;j++){
					A1[j]=A1[j+1];
				}
				A1[x-1]=0;break;
			}
			else{
				//计算除数x商
				int *temp=new int [x];
				int flag=0;
				for(int j=x-1;j>=1;j--){
					temp[j]=A2[j]*A3[i]+flag;
					if(temp[j]>=10){
						flag=temp[j]/10;
						temp[j] %= 10;
					}
					else{
						flag=0;
					}
					temp[j]=A1[j]-temp[j];
					if(temp[j]<0){
						temp[j]+=10;
						flag++;
					}
				}
				temp[0]=A1[0]-(A2[0]*A3[i]+flag);
				if(temp[0]<0){
					A3[i]--;
					delete [] temp;
					continue;
				}
				else{
					A1[0]=10*temp[0]+temp[1];
					for(int j=1;j<x-1;j++){
						A1[j]=temp[j+1];
					}
					delete[] temp;
					A1[x-1]=0;
					break;
				}
			}  //else
		}	//while
	}	//for
	BigNumber R;
	R.pls=pls*X.pls;
	R.len=L3-L1+L2;
	delete [] R.Num;
	R.Num=new int [R.len];
	if(L1-L2>=0){
		for(int i=1;i<R.len;i++){
			R.Num[i]=A3[L1-L2+i];
		}
		R.Num[0]=0;
		for(int i=L1-L2;i>=0;i--){
			R.Num[0] += (A3[i]*pow(10,L1-L2-i));
		}
	}
	else{
		R.Num[0]=0;
		for(int i=1;i<R.len;i++){
			R.Num[i]=i+L1-L2<0?0:A3[i+L1-L2];
		}
	}
	delete [] A1;
	delete [] A2;
	delete [] A3;
	return R;
}

BigNumber BigNumber::operator^(const int x)const{
	if(x>=0){
		int i=1;
		BigNumber Result(1.0,1);
		for(;i<=x;i++){
			Result=Result*(*this);
		}
		return Result;
	}
	else
		return ((this->Reciprocal())^(-x)).IncreaseBit(len+5);
}

bool BigNumber::operator==(const BigNumber& X)const{
	if(pls!=X.pls) return false;
	else{
		int x=len>X.len?len:X.len;
		BigNumber x1=this->IncreaseBit(x);
		BigNumber x2=X.IncreaseBit(x);
		for(int i=0;i<x;i++){
			if(x1.Num[i]!=x2.Num[i]) return false;
			else continue;
		}
		return true;
	}
}

bool BigNumber::operator==(const double x)const{
	BigNumber X(x,len+1);
	return *this==X;
}

bool BigNumber::operator>=(const BigNumber& X)const{
	if(pls>X.pls) return true;
	else if(pls<X.pls) return false;
	else{
		int x=len>X.len?len:X.len;
		BigNumber x1=this->IncreaseBit(x);
		BigNumber x2=X.IncreaseBit(x);
		if(pls==1){
			for(int i=0;i<x;i++){
				if(x1.Num[i]>x2.Num[i]) return true;
				else if(x1.Num[i]<x2.Num[i]) return false;
				else continue;
			}
			return true;
		}
		else{
			for(int i=0;i<x;i++){
				if(x1.Num[i]>x2.Num[i]) return false;
				else if(x1.Num[i]<x2.Num[i]) return true;
				else continue;
			}
			return true;
		}
	}
}

bool BigNumber::operator>=(const double x)const{
	BigNumber X(x,len+1);
	return (*this)>=X;
}

bool BigNumber::operator>(const BigNumber& X)const{
	if(*this>=X){
		if(*this==X) return false;
		else return true;
	}
	else return false;
}

bool BigNumber::operator>(const double x)const{
	BigNumber X(x,len+1);
	return *this>X;
}

BigNumber BigNumber::LnxTaylor(const int lenth){
	BigNumber X(*this);
	int L=lenth;
	double AcquireError=0.5*pow(10,-L-1);
	int num=0;
	while(X>1.5){
		num++;
		X=X/2;
	}
	BigNumber x(1.0,1);
	X=X-x;
	int i=1;
	BigNumber Y;
	for(i=1;;i++){
		BigNumber last=Y;
		BigNumber y=(X^i).IncreaseBit(L+2)/i;
		Y=(i%2==0)?Y-y:Y+y;
		if((Y-last).Abs()>AcquireError) continue;
		else break;
	}
	if(num!=0){
		Y=Ln2(L+2)*num+Y;
	}
	return Y.IncreaseBit(lenth);
}

BigNumber BigNumber::LnxNumIntegration(const int lenth){
	int n=1;
	double AcquireError=0.5*pow(10,-lenth-1);
	BigNumber X((*this).IncreaseBit(lenth+2));
	BigNumber x(1,1);
	int num=0;
	while(X>x){
		X=X/2;
		num++;
	}
	BigNumber h=x-X;
	BigNumber error(1,1);
	BigNumber *T=new BigNumber [20];
	T[0]=(h*((X^(-1))+1)/2).IncreaseBit(lenth+3);
	while(error>AcquireError&&n<20){
		BigNumber SumNewPoint;
		for(int i=0;i<pow(2,n-1);i++){
			BigNumber m(0.5+i,lenth);
			BigNumber mm=(x-h*m).IncreaseBit(lenth+3);
			SumNewPoint=(SumNewPoint+(mm.Reciprocal())).IncreaseBit(lenth+3);
		}
		BigNumber last=(T[0]+(h*SumNewPoint)).IncreaseBit(lenth+3)/2;
		for(int i=1;i<=n;i++){
			int para=pow(4,i);
			BigNumber Step=((last*para)-T[i-1]).IncreaseBit(lenth+3)/(para-1);
			T[i-1]=last.IncreaseBit(lenth+3);
			last=Step.IncreaseBit(lenth+3);
		}
		error=(last-T[n-1]).Abs();
		T[n]=last;
		n++;
		h=(h/2).IncreaseBit(lenth+3);
	}
	return ((Ln2(lenth+3)*num)-T[n-1]).IncreaseBit(lenth);
}

BigNumber BigNumber::LnxRationalApproximation(const int lenth){
	BigNumber X(*this);
	double AcquireError=0.5*pow(10,-lenth-1);
	int num=0;
	while(X>2){
		num++;
		X=X/2;
	}
	BigNumber x(1,1);
	X=X-x;
	int n=2*lenth;
	BigNumber Y=X*(pow(n/2,2));
	Y=(Y/n).IncreaseBit(lenth+2);
	for(int i=n-1;i>1;i--){
		Y=(X*(pow(i/2,2)))/(Y+i);
		Y=Y.IncreaseBit(lenth+2);
	}
	Y=(X/(Y+1)).IncreaseBit(lenth+2);
	if(num!=0){
		Y=Ln2(lenth+2)*num+Y;
	}
	return Y.IncreaseBit(lenth);
}

BigNumber BigNumber::Abs() const{
	BigNumber X(*this);
	X.pls=1;
	return X;
}

BigNumber BigNumber::Reciprocal()const{
	BigNumber X(*this);
	BigNumber x(1,1);
	return x/X;
}

void BigNumber::print(){
	if(pls==-1)
		cout<<"-";
	cout<<Num[0];
	if(len>1)
	cout<<".";
	for(int i=1;i<len;i++){
		cout<<Num[i];
	}
	cout<<endl;
}

string BigNumber::BigNumber2Str(){
	string R;
	int i=1;
	char *t=new char [100];
	sprintf(t,"%d",Num[0]);
	R=t;
	delete [] t;
	if(len>1)
	R += '.';
	for(;i<len;i++){
		char t=Num[i]+'0';
		R += t;
	}
	string Result;
	if(pls==-1) Result='-'+R;
	else Result=R;
	return Result;
}

BigNumber BigNumber::_plus1(const BigNumber & Add)const{
	int Len=Add.len>len?Add.len:len;
	BigNumber Result;
	Result.len=Len;
	delete [] Result.Num;
	Result.Num=new int [Len];
	BigNumber ad=(*this).IncreaseBit(Len);
	BigNumber add=Add.IncreaseBit(Len);
	int flag=0;
	for(int i=Len-1;i>=1;i--){
		Result.Num[i]=ad.Num[i]+add.Num[i]+flag;
		flag=Result.Num[i]<10?0:Result.Num[i]/10;
		Result.Num[i]=Result.Num[i]%10;
	}
	Result.Num[0]=ad.Num[0]+add.Num[0]+flag;
	Result.pls=1;
	return Result;
}

BigNumber BigNumber::_plus2(const BigNumber & Add)const{
	int Len=Add.len>len?Add.len:len;
	BigNumber Result;
	Result.len=Len;
	delete [] Result.Num;
	Result.Num=new int [Len];
	BigNumber ad=(*this).IncreaseBit(Len);
	BigNumber add=Add.IncreaseBit(Len);
	add.pls=1;
	if(ad>=add)
		Result=ad._dec(add);
	else{
		Result=add._dec(ad);
		Result.pls=-1;
	}
	return Result;
}

BigNumber BigNumber::_dec(const BigNumber & Dec)const{
	BigNumber Result;
	Result.len=Dec.len;
	delete [] Result.Num;
	Result.Num=new int [Dec.len];
	Result.pls=1;
	int flag=0;
	for(int i=Result.len-1;i>=0;i--){
		Result.Num[i]=Num[i]-Dec.Num[i]+flag;
		if(Result.Num[i]<0){
			Result.Num[i] += 10;
			flag=-1;
		}
		else flag=0;
	}
	return Result;
}

