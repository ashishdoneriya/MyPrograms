/* Not working */
#include<stdio.h>
#include<iostream>
int  isPrintable(int num){
	int a,b,c,d,temp;
	a=num/1000;
	temp=num%1000;
	b=temp/100;
	temp=temp%100;
	c=temp/10;
	d=temp%10;
	if(a==0 && b==0){
		if(c==d+1 || d==c+1 || c>d)
			return 0;
	}
	else if(a==0){
		if((b==c+1 && c==d+1) || (d==c+1 && c==b+1))
			return 0;
		else if(b>c || c >d)
			return 0;
	}
	else{
		if((a==b+1 && b==c+1 && c==d+1) || (d==c+1 && c==b+1 && b==a+1))
			return 0;
		else if(a>b || b>c || c>d)
			return 0;
	}
	return 1;
}

int main(){
	int i;/*
	for(i=30; i<=3000;i++){
		if(isPrintable(i))
			printf("%d\n",i);
	}*/
	std::cout.precision(10.6600);
	return 0;
}
