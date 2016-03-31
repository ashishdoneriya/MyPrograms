#include<stdio.h>
#include<malloc.h>
#include<string.h>
int count=0;
char arr1[80], arr2[80], start[400][80];
int row=0;
int numOfString=0;
void slideDD(int pos){
	int i;
	for(i=row;i>pos;i--){
		strcpy(&(start[i][0]),&(start[i-1][0]));
	}
	row++;
}
int strcomp(const char *str1, const char *str2){
	int i;
	for(i=0;;i++){
		if(str1[i]=='\0'&&str2[i]=='\0')
			return 0;
		if(str1[i]=='\0'&&str2[i]!='\0')
			return -1;
		if(str1[i]!='\0'&&str2[i]=='\0')
			return 1;
		if(str1[i]!=str2[i]){
			if(str1[i]<str2[i])
				return -1;
			else
				return 1;
		}
	}
}
void insertInStart(const char str[]){
	int i,len=strlen(str);
	if(len<count)
		return;
	if(len>count)
		count=len;
	for(i=0;i<row;i++){
		if(strcomp(str,&start[i][0])==0)
			return;
		else if(strcomp(str,&start[i][0])==1)
			continue;
		else{
			slideDD(i);
			strcpy(&start[i][0],str);
			return;
		}
	}
	strcpy(&(start[row][0]),str);
	row=row+1;
}
void displayStart(){
	int i;
	for(i=0;i<row;i++){
		if(strlen(&start[i][0])==count)
			printf("%s\n",&start[i][0]);
	}
}
int getIndex(char str[], char ch, int startFrom ){
	int i;
	for(i=startFrom; str[i]!=0; i++){
		if(str[i]==ch)
			return i;
	}
	return -1;
}

void copyUpto(char arr[], char temp1[], char temp2[], int i){
	int j;
	for(j=0; j<=i; j++)
		temp1[j]=temp2[j]=arr[j];
}

void generateNext(char myString[], int i, int ptr1, int ptr2){
	int j;
	char temp1[80],temp2[80];
	if(arr1[ptr1]==arr2[ptr2]){
		myString[i]=arr1[ptr1];
	}
	
	if ( ( arr1[ptr1+1] == 0 ) || ( arr2[ptr2+1] == 0 ) ) {
		myString[i+1]='\0';
		insertInStart(myString);
		return;
	}
	else{
		copyUpto(myString,temp1,temp2,i);
		j=getIndex(arr2, arr1[ptr1+1], ptr2+1);
		if(j!=-1){
			generateNext(temp1, i+1, ptr1+1, j);
		}
		else
			generateNext(temp1, i, ptr1+1, ptr2+1);
			
		j=getIndex(arr1, arr2[ptr2+1], ptr1+1);
		if(j!=-1){
			generateNext(temp2, i+1, j, ptr2+1);
		}
		else
			generateNext(temp2, i, ptr1+1, ptr2+1);
	}
}
void letsStartRecursion(){
	int j,i=0;
	char temp1[80],temp2[80],myString[80];
	if(arr1[0]==arr2[0]){
		generateNext(myString,0,0,0);
	}
	else{
		do{
			if(arr1[i]==0)
				return;
			j=getIndex(arr2, arr1[i], 0);
			if(j!=-1){
				generateNext(temp1, 0, 0, j);
			}
			i++;
		}while(j==-1);
		i=0;
		do{
			if(arr2[i]==0)
				return;
			j=getIndex(arr1, arr2[i], 0);
			if(j!=-1){
				generateNext(temp2, 0, j, 0);
			}
			i++;
		}while(j!=-1);
	}
}

int main(){
	int i,testCases;
	scanf("%d",&testCases);
	for(i=0;i<testCases;i++){
		scanf("%s",arr1);
		scanf("%s",arr2);
		letsStartRecursion();
		displayStart();
	}
	return 0;
}
