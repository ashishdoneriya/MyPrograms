#include<stdio.h>
void display(){
	printf("In display()\n");
}
int main(){
	void (*fun_ptr)();
	fun_ptr=display;
	(*fun_ptr)();
	fun_ptr();
	return 0;
}
