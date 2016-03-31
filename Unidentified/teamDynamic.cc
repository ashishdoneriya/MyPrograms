#include<iostream>
using namespace std;

int N, C, Q, A, B, D, X;
int getMin(int *skill, int i, int j);
int getMax(int *skill, int i, int j);
int isTeam(int *skill, int i, int j);
int getTotalTeam(int *skill, int k);
void fillcan(int *skill, int *can);
int getM(int *can, int valM);					//It searches can[k]

int getMin(int *skill, int i, int j){
	int min=skill[i];
	for(int k=i; k<=j; k++){
		if(skill[k]<min)
			min = skill[k];
	}
	return min;
}

int getMax(int *skill, int i, int j){
	int max=skill[i];
	for(int k=i; k<=j; k++){
		if(skill[k]>max)
			max = skill[k];
	}
	return max;
}

int isTeam(int *skill, int i, int j){
	int max = getMax(skill,i,j);
	int min = getMin(skill,i,j);
	X = max-min;
	if(X>C)
		return 0;
	else
		return 1;
}

int getTotalTeam(int *skill, int k){
	if(k==1)
		return N;
	int count = 0;
	for(int i=1; i<=(N-k+1); i++){
		if(isTeam(skill,i,i+k-1))
			count++;
	}
	return count;
}

void fillcan(int *skill, int *can){
	for(int i=1; i<=N;i++){
		can[i]=getTotalTeam(skill,i);
	}
}

int getM(int *can, int valM){
	int max=-1, index=0;
	for(int i=1;i<=N;i++){
		if(can[i]<=valM){
			if(can[i]>max){
				max=can[i];
				index=i;
			}
		}
	}
	return index;
}

int main(){
	int *skill, *can, *arrM;
	int T, i, maxM;
	cin>>T;
	while(T--)
	{
		cin>>N>>C>>Q>>A>>B>>D;	//Accepting inputs from first line
		X=(N<10000)?N:10000;
		skill = new int[N+1];
		for(i=1; i<=X; i++){	//Accepting inputs from second line
			cin>>skill[i];
		}
		if(N>10000){
			for(i=10001; i<=N; i++){
				skill[i]=(A*skill[i-1] + B*skill[i-2] + D)%1073741824;
			}
		}
		
		arrM = new int[Q+1];
		maxM=0;
		for(i=1; i<=Q; i++){	//Accepting inputs from third line
			cin>>arrM[i];
			if(arrM[i] > maxM)
				maxM = arrM[i];
		}
		can=new int[N+1];
		fillcan(skill, can);
		int temp;
		for(i=1;i<=Q;i++){
			temp=getM(can,arrM[i]);
			cout<<temp<<" "<<can[temp]<<endl;
		}
		delete []can;
		delete []arrM;
		delete []skill;
	}
	return 0;
}
