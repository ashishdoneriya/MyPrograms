//Encryption of File
#include<stdio.h>
#include<stdlib.h>
void encrypt(){
	FILE *fp,*ft;
	char ch;
	fp=fopen("bit1.c","r");
	ft=fopen("bit11.c","w");
	if(fp==NULL||ft==NULL){
		printf("File not opened");
		exit(1);
	}
	while((ch=getc(fp))!=EOF){
		putc(~ch,ft);
	}
	fclose(fp);
	fclose(ft);
}
int main(){
	encrypt();
	return 0;
}
