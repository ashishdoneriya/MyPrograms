#include<stdio.h>
void compress(char arr[], char res[]){
	int count=1,i,j;
	char ch=arr[0];
	for(i=1, j=0; arr[i]!='\0'; i++){
		if(ch!=arr[i]){
			res[j++]=ch;
			res[j++]=count+48;
			ch=arr[i];
			count=1;
		}
		else
			count++;
	}
	res[j++]=ch;
	res[j++]=count+48;
	res[j]=0;
}

void correction(char arr[], char res[]){
	int i=0, j=0;
	while( arr[i]!='\0'){
		if((arr[i]>='a' && arr[i]<='z') || (arr[i]>='A' && arr[i]<='Z') || (arr[i]>='0' && arr[i]<='9')){
			res[j]=arr[i];
			j++;
		}
		i++;
	}
	res[j]=0;
}
int main(){
	char brr[30],arr[]="a4asasas23213j!@#$%^&*wdksn##";
	correction(arr,brr);
	printf("%s",brr);
	return 0;
}
