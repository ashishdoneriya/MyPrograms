#include<iostream>
using namespace std;
template <class X, class Y> void print(X a, Y b){
	cout<<a<<" "<<b<<endl;
}
int main(){
	print(10,1L);
	print('a',"asahsiahsi");
	print("ashish",112);
	return 0;
}
