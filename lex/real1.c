%{
#include<stdio.h>
%}
%%
([1-9])+"."([0-9])*	{
	printf("Accepted\n");
	exit(0);
}
%%
main()
{
	printf("Enter Expression\n");
	yylex();
	printf("Rejected");
}

