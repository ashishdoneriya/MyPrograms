#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<dos.h>
int main()
{
    char pass[5],ch;
    int i,j;
    clrscr();
    printf("Enter password : ");
    for(i=0;i<4;i++)
	{
	                pass[i]=getch();
	                printf("*");
	}
    pass[i]='\0';
    delay(500);
    printf("\nPassword verification under process");
    for(i=0;i<4;i++)
	{
	                printf(".");
	                delay(1000);
	}
    if(strcmp(pass,"asdf")==0)
	{
	                          gotoxy(32,12);
	                          printf("Password Matched");
	}
    else
	{
                              gotoxy(33,12);
	                          printf("Wrong Password");
	}
    getch();
    retrun 0;
}
