/* not working */
#include<iostream>
#include<math.h>
using namespace std;

float getReverse(float num){
	float temp1,temp2;
	int temp3,temp4;
	static int flag=1;
	if(flag==1){
		temp3=(int)num;
		num=num-(int)num;
		temp1=getReverse(num);
		while(floor(temp1)!=0){
			temp1=temp1/10;
		}
		temp1=temp1+temp3;
		return temp1;
	}
	else{
		if(ceil(num)==0){
			return 0;
		}
		num=num*10;
		temp3=num;
		num=num-(int)num;
		temp4=getReverse(num);
		return (temp4*10+temp3);
	}
}

int main(){
	cout<<getReverse(5.12345);
	return 0;
}

