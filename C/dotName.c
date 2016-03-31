#include<stdio.h>
int main(){
	int i,j,nos;
	int space[10];		//for entry of the postion of spaces occur in string
	char str[30];
	printf("Enter the string : ");
	gets(str);
	
	//Entry of index of space in array space[]
	for(i=0,j=0; str[i]!='\0'; i++){
		if(str[i]==' '){
			space[j]=i;
			j++;
		}
	}
	nos=j; //nos means number of spaces
	
	if(nos==0){		//case if string contains no space ie single word
		printf("%s",str);
	}
	else{
		//printing the first character
		printf("%c. ",str[0]);
		
		for(j=0;j<(nos-1);j++){
			//printing the character next to space with appending '.'
			printf("%c. ",str[space[j]+1]);
		}
		
		//printing the last string
		printf("%s",&str[space[j]]);
	}
	return 0;
}

//Time complexity O(n)
