#include<iostream>
#define NVAL 335000
using namespace std;

long long N, C, Q, A, B, D, X;
long long getM(long long *can, long long valM);					//It searches can[k]

void fillcan(long long *skill, long long *can){
	long long min,max,m,k,i,count;
	for(k=1; k<=N;k++){
		if(k==1)
		{
			can[k]=N;
			continue;
		}
		count=0;
		for(i=1; i<=(N-k+1); i++)
		{
			min=skill[i];
			max=skill[i];
			for(m=i;m<=i+k-1;m++)
			{
				if(skill[m]>max)
					max=skill[m];
				if(skill[m]<min)
					min=skill[m];
			}
				if((min-max)>C)
					continue;
			else
				count++;
		}
		can[k]=count;
	}
}

long long getM(long long *can, long long valM){
	long long max=-1, index=0;
	for(long long i=1;i<=N;i++){
		if(can[i]<=valM && can[i]>max){
				max=can[i];
				index=i;
		}
	}
	return index;
}

int main(){
	long long skill[NVAL], can[NVAL], arrM[NVAL];
	long long T, i, temp;
	cin>>T;
	while(T--)
	{
		cin>>N>>C>>Q>>A>>B>>D;	//Accepting inputs from first line
		X=(N<10000)?N:10000;
		for(i=1; i<=X; i++){	//Accepting inputs from second line
			cin>>skill[i];
		}
		if(N>10000){
			for(i=10001; i<=N; i++){
				skill[i]=(A*skill[i-1] + B*skill[i-2] + D)%1073741824;
			}
		}
		for(i=1; i<=Q; i++)	//Accepting inputs from third line
			cin>>arrM[i];
		fillcan(skill, can);
		for(i=1;i<=Q;i++){
			temp=getM(can,arrM[i]);
			cout<<temp<<" "<<can[temp]<<endl;
		}
	}
	return 0;
}
