//Input:	My name is
//Output:	is name My
#include<stdio.h>
#include<string.h>
int main(){
	char arr[40],temp[20];
	int len,i,j=0;
	printf("Enter the string : ");
	gets(arr);
	len=strlen(arr);
	for(i=len-1;i>=0;i--){
		if(arr[i]==' '){
			temp[j]=0;
			for(j=j-1;j>=0;j--)
				printf("%c",temp[j]);
			printf(" ");
			j=0;
		}
		else
			temp[j++]=arr[i];
	}
	temp[j]=0;
	for(j=j-1;j>=0;j--)
		printf("%c",temp[j]);
	return 0;
}
