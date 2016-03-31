#include<iostream>
using namespace std;
int main(){
	cout<<"Hello\n";
	
	cout<<"Hello\n User\n";
	cout<<"Hello"<<endl<<"User"<<endl;
	
	int a = 10;
	cout<<a<<endl;;
	
	char ch='A';
	cout<<ch<<"\t"<<(int)ch<<endl;
	
	int b = 12;
	char c='x';
	float d = 13.5;
	cout<<b<<c<<d<<endl;			//OUTPUT :: 12x13.5
	cout<<b<<" "<<c<<" "<<d<<endl;	//OUTPUT :: 12 x 13.5
	
	cout<<"Enter value :: ";
	cin>>a;
	
	cout<<"Enter int float and char values :: ";
	cin>>b>>d>>c;
	
	int as=10,bs=32;
	float fs=float(bs)/as;
	float fss=(float)bs/as;
	cout<<fs<<"\t"<<fss;
	return 0;
}
