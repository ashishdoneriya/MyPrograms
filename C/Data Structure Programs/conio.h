#include<stdio.h>
void hold()
{
	char a;
	scanf("%c",&a);
}

void flush()
{
	scanf ( "%*[^\n]" );
	scanf ( "%*c" );
}

char getch()
{
char c;
char test;
scanf("%c",&c);
scanf("%c",&test);
return (c);
}

void clrscr()
{
	system("clear");
}

//Command :- sudo cp ~/conio.h /usr/include

