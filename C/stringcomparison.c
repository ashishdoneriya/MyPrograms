#include<stdio.h>
#include<string.h>
#include<conio.h>
int strcmpAdvance(const char *str1, const char *str2);
int strcmpAdvance(const char *str1, const char *str2){
	int i;
	for(i=0;;i++){
		if(str1[i]=='\0'&&str2[i]=='\0')
			return 0;
		if(tolower(str1[i])<tolower(str2[i]))
				return 1;
		if(tolower(str1[i])>tolower(str2[i]))
				return -1;
		
		}
}

int main(){
	printf("%d\n",strcmpAdvance("ashish","ashish"));
	printf("%d\n",strcmpAdvance("ashis","ashish"));
	printf("%d\n",strcmpAdvance("ashish","doneriya"));
	printf("%d\n",strcmpAdvance("ashish","ashish1"));
	printf("%d\n",strcmpAdvance("apple","applf"));
	printf("%d\n",strcmpAdvance("apple","appld"));
	printf("%d\n",strcmpAdvance("applew","applaw"));
	printf("%d\n",strcmpAdvance("tamrakar","sourabh"));
	printf("%d\n",strcmpAdvance("prashant","kumar"));
	printf("%d\n",strcmpAdvance("bananas","banana"));
	getch();
	return 0;
}
