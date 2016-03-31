//	Nearest Neighbour Algorithm
#include<iostream>
#define N 40
using namespace std;
class NNP{
	int adj[N][N];
	int n;
	int bucket[N], bs, optPathLen;
public:
	NNP(){
		optPathLen=bs=n=0;
	}
	void getSize(){
		cout<<"Enter the number of vertices present in the graph : ";
		cin>>n;
	}
	void getData(){
		int i,j;
		cout<<"Enter the data"<<endl;
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				cin>>adj[i][j];
			}
		}
	}
	bool checkBucket(int x){	//bs means bucket size currently
		for(int i=0; i<bs; i++){
			if(bucket[i]==x)
				return true;
		}
		return false;
	}
	void calculatePath(){
		int v=0, e=9999, i=0, j=0;
		bool change=true;
		while(change){
			bucket[bs]=i;
			bs++;
			change=false;
			e=9999;
			for(j=0;j<n;j++){
				if(i==j || checkBucket(j)==true)
					continue;
				if(adj[i][j]<e){
					v=j;
					e=adj[i][j];
					change=true;
				}
			}
			i=v;
			if(change!=false)
				optPathLen+=e;
		}
		optPathLen+=adj[bucket[bs-1]][0];
		bucket[n]=0;
		bs++;
	}
	void showPath(){
		cout<<"\nOptimatal Path"<<endl;
		for(int i=0; i<bs;i++)
			cout<<bucket[i]<<"\t";
		cout<<"\nTotal Path length = "<<optPathLen;
	}
	void showAdjMat(){
		int i,j;
		for(i=0;i<n;i++){
			for(j=0;j<n;j++)
				cout<<adj[i][j]<<"\t";
			cout<<endl;
		}
	}
};

int main(){
	NNP mat;
	mat.getSize();
	mat.getData();
	mat.calculatePath();
	mat.showAdjMat();
	mat.showPath();
	return 0;
}
