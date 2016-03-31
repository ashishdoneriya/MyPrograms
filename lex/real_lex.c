%{
#include<stdio.h>
%}
dig		[0-9]
alpha	[A-Za-z]
%%
([1-9])+"."([0-9])*	{
	printf("Accepted\n");
	exit(0);
}
({alpha}|{dig}|\$)({alpha}|{dig}|[_.\-/$])*	{
	printf("Not Accepted\n");
	exit(0);
}
%%
main()
{
	system("clear");
	yylex();
}

