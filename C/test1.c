#include<stdio.h>
#include<conio.h>
struct nitin
{
	int sch;
	char name[30];
};
void get(struct nitin *a);
int main(){
	struct nitin a;
	int i;
	get(&a);
	printf("%d %s\n",a.sch,a.name);
	getch();
	return 0;
}
	
void get(struct nitin *d)
{
	int i;
	scanf("%d %s",&(d->sch),(d->name));
}
