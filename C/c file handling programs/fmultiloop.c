#include<stdio.h>
#include<miss.h>
struct student
{
	int roll;
	float per;
	char grade;
};

void main()
{
	struct student s;
	FILE *fp;
	char choice;
	system("clear");
	fp=fopen("ashish.txt","w+");
	do
	{
	while (line!=EOF);
	printf("Enter your roll no. , percentage and grade\n");
	scanf("%d %f %c",&s.roll,&s.per,&s.grade);
	flush();
	fprintf(fp,"%d %f %c\n",s.roll,s.per,s.grade);
	rewind(fp);
	printf("Do you want to continue (Y/N) : ");
	flush();
	scanf("%c",&choice);
	system("clear");
	}while(choice=='Y'||choice=='y');
	fclose(fp);
	hold();
}
