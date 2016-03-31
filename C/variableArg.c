#include<stdio.h>
#include<stdarg.h>
int findmax(int,...);
int main(){
	int max;
	printf("Maximum = %d\n",findmax(5,23,15,1,92,50));
	printf("Maximum = %d\n",findmax(3,100,300,29));
	return 0;
}
int findmax(int total_num,...){
	int max, count, num;
	va_list ptr;
	va_start(ptr,total_num);
	max=va_arg(ptr,int);
	for(count = 1;count<total_num;count++){
		num=va_arg(ptr,int);
		if(num>max)
			max=num;
	}
	return (max);
}
