/* Not works */
#include<iostream>
#include<math.h>
using namespace std;

float getReverse(float num){
	cout<<"received="<<num<<endl;
	float mo,temp1;
	static int flag=1;
	if(flag==1){
		temp1=num-(int)num;
		flag=0;
		mo=getReverse(temp1);
		mo=mo-(int)mo;
		mo=mo+(int)num;
		return mo;
	}
	else{
		if(ceil(num)==0)
			return 0.0;
		num=num*10;
		int getDigit=(int)num;
		num=num-(int)num;
		mo=getReverse(num);
		int temp2=(int)mo;
		mo=mo+getDigit/pow(10,temp2);
		return (mo+1);
	}
}

int main(){
	cout<<getReverse(5.12345);
	return 0;
}
