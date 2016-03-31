#include<stdio.h>
void showbits(int);
int main(){
	int j;
	for(j=0;j<6;j++){
		printf("\nDecimal %d is same as binary ",j);
		showbits(j);
	}
	return 0;
}
