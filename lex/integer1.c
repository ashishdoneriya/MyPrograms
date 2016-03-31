%{
#include<stdio.h>
%}
%%
[0-9]*	{
	printf("Accepted\n");
	exit(0);
}
([a-zA-Z0-9]|\$)([a-zA-Z0-9]|[_.\-/$])*	{
	printf("Not Accepted\n");
	exit(0);
}
%%
main(){
	system("clear");
	yylex();
}


