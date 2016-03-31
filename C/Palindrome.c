//Name 		: ASHISH DONERIYA
//COLLEGE	: MANIT (BHOPAL, INDIA)
#include<stdio.h>
#include<string.h>
int count=0;
int charLast(char str[], char ch, int limit1,int limit2){
	int i;
	for(i=limit2;i>=limit1;i--){
		if(str[i]==ch)
			return i;
	}
	return -1;
}
void sendToLast(char str[], int limit1, int limit2){
	int i;
	char ch;
	ch=str[limit1];
	for(i=limit1;i<limit2;i++)
		str[i]=str[i+1];
	str[i]=ch;
	count=count+(limit2-limit1);
}

int makePalindrome(char str[]){
	int i,l,j;
	l = strlen( str );
	for( i=0; i <= (l/2-1); i++ ) {
		j = charLast( str, str[i], i+1, l-i-1 );
		if(j==-1){
			sendToLast(str,i,l/2);
			return 0;
		}
		if(i!=(l-j-1))
			sendToLast(str,j,l-i-1);
	}
	return 1;
}
int checkPalindrome(char str[]){
	int i,l=strlen(str);
	for(i=0;i<=(l/2-1);i++){
		if(str[i]!=str[l-i-1])
		return 0;
	}
	return 1;
}

int main(){
	char str[101];
	do{
		count=0;
		scanf( "%s", str );
		if(((str[0]=='0')&&(str[1]==0)))
			break;
		if(makePalindrome(str)==0)
			makePalindrome(str);
		if(checkPalindrome(str))
			printf("%d\n",count);
		else
			printf("Impossible\n");
	}while((str[0]!='0')&&(str[1]!=0));
	return 0;
}
