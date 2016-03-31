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
	system("clear");
	fp=fopen("ashish.txt","a+");
	printf("Enter your roll no. , percentage and grade\n");
	scanf("%d %f %c",&s.roll,&s.per,&s.grade);
	fprintf(fp,"%d %f %c\n",s.roll,s.per,s.grade);
	rewind(fp);
	system("clear");
	fscanf(fp,"%d %f %c",&s.roll,&s.per,&s.grade);
	printf("\nroll=%d\npercentage=%f\ngrade=%c\n",s.roll,s.per,s.grade);
	fclose(fp);
	hold();
}
