#include<stdio.h>
#include<string.h>
void danagram(char c[]){
	int i,j,k,temp;
	int n=strlen(c);
	for(i=0;i<n-1;i++){
		k=i;
		for(j=i+1; j<n; j++){
			if(c[k]>c[j])
				k=j;
		}
		if(k!=i){
			temp=c[i];
			c[i]=c[k];
			c[k]=temp;
		}
	}
}

void merge(char c[], char d[], char e[]){
	int c1=strlen(c), c2=strlen(d);
	int i=0, j=0, k=0;
	while(i<c1 && j<c2){
		if(c[i]<d[j]){
			e[k]=c[i];
			i++;
		}
		else{
			e[k]=d[j];
			j++;
		}
		k++;
	}
	
	if(i==c1){
		while(j<c2){
			e[k]=d[j];
			k++;
			j++;
		}
	}
	else if(j==c1){
		while(i<c1){
			e[k]=c[i];
			k++;
			i++;
		}
	}
	e[k]='\0';
}
int main(){
	char c[]="ashish",d[]="doneriya",e[30];
	danagram(c);
	danagram(d);
	printf("%s\n",c);
	printf("%s\n",d);
	merge(c,d,e);
	printf("%s\n",e);
	return 0;
}

