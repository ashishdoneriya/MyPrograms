#include<stdio.h>
int main(){
	int i,j;
	char str[20];
	printf("Enter the string : ");
	scanf("%s",str);
	for(i=0; str[i]!='\0';i++){
		for(j=0;j<i;j++){
			if(str[i]==str[j]) {break;}
		}
		if(i==j||i==0)
			printf("%c",str[i]);
	}
	return 0;
}
