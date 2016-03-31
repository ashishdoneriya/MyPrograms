#include<stdio.h>
#include<fcntl.h>
char buffer[1000000];
int version=1;
void copy(int old, int new){
	int count;
	while((count=read(old,buffer,sizeof(buffer)))>0){
		write(new,buffer,count);
	}
}
int main(int argc, char *argv[]){
	int fdold, fdnew;
	if(argc!=3){
		printf("Less Arguments\n");
		return 0;
	}
	fdold=open(argv[1],O_RDONLY);
	if(fdold==-1){
		printf("Error while opening file\n");
		return 0;
	}
	fdnew=creat(argv[2],0666);
	if(fdnew==-1){
		printf("Error while creating file\n");
		return 0;
	}
	copy(fdold,fdnew);
	return 0;
}
