#include<stdio.h>
#include<math.h>
#include<cmath>
int main(){
	float dy,k,y,A,D;
	printf("Enter the value of  ⃤ y+, k, y+, A+\n");
	scanf("%f %f %f %f",&dy, &k, &y, &A);
	D=1-exp((-dy)/A);
	return 0;
}
