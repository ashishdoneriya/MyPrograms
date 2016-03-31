#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
char A[20000], B[20000];
int numA[10],numB[10], finalA[10], finalB[10];
int aL,bL;
void cutFromB(){
	if(numB[6]=>numA[7]){
		numB[6]=numB[6]-numA[7];
		finalA[7]=numA[7];
		numA[7]=0;
	}
	else{
		numA[7]=numA[7]-numB[6];
		
		numB[6]=0;
	}
	
}

void cutFromA(){
	
}

int main(){
	int T,i;
	cin>>T;
	while(T--){
		for(i=0;i<=9;i++)
			numA[i]=numB[i]=finalA[i]=finalB[i]=0;
		gets(A);
		gets(B);
		for(i=0;A[i]!=0;i++){
			numA[A[i]-48]++;
			numB[B[i]-48]++;
		}
		aL=bL=i;
		cutFromA();
		cutFromB();
		
	}
	return 0;
}
