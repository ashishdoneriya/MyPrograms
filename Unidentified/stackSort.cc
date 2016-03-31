#include<iostream>
#define N 20
using namespace std;
class Stack{
	int tos;
	int stk[N];
	int size;
public:
	Stack(int s){
		tos=-1;
		size=s;
	}
	
	bool push(int x){
		if(tos==(size-1))
			return false;
		stk[++tos]=x;
		return true;
	}
	int pop(){
		if(tos==-1)
			return -1;
		return stk[tos--];
	}
	void print(){
		for(int i=tos;i>=0;i--){
			cout<<stk[i]<<"\t";
		}
	}
};

int main(){
	int n, i, temp, x, y, z, w, r;
	cout<<"Enter the size of stack : ";
	cin>>n;
	Stack initial(n), final(n);
	cout<<"Enter the numbers"<<endl;
	for(i=0;i<n;i++){
		cin>>temp;
		initial.push(temp);
	}
	for(i=0;i<n;i++)
	{
		x=initial.pop();
		r=initial.pop();
		if(x==-1)
			break;
		initial.push(r);
		cout<<endl;
		y=final.pop();
		if(y==-1){
			final.push(x);
			continue;
		}
		if(y!=-1){
			final.push(y);
			
			while(true){
				z=final.pop();
				if(z==-1)
					break;
				if(z>x){
					final.push(z);
					break;
				}
				initial.push(z);
			
			}
			
			final.push(x);
			
			while(true){
				w=initial.pop();
				if(w==r){
					if(w!=-1)
						initial.push(w);
					break;
				}
				if(w==-1)
					break;
				final.push(w);
			}
		}
	}
	return 0;
}
