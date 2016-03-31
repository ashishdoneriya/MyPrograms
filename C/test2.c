#include<stdio.h>
#include<conio.h>
typedef struct crickter
{
	char name[30];
	int age,notp;
	float avg;
}data;
void add(data qw);
int main()
{
	typedef struct crickter as;
	as record[20];
	
	int i;
	for(i=0;i<20;i++){
		printf("Enter name age notp, avg ");
		scanf("%s %d %d %f",record[i].name,&(record[i].age),&(record[i].notp),&(record[i].avg));
	}
	for(i=0;i<20;i++){
		printf("%s %d %d %f\n",record[i].name,(record[i].age),(record[i].notp),(record[i].avg));
	}
	return 0;
}
