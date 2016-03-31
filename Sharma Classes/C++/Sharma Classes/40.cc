//Adding 2 objects of a class
#include<iostream>
using namespace std;
class Distance{
	int feet;
	int inches;
public:
	void get(){
		cout<<"Enter feet and inches ";
		cin>>feet>>inches;
	}
	void show(){
		cout<<feet<<" "<<inches<<endl;
	}
	friend void add( Distance, Distance, Distance & );
};
void add( Distance P, Distance Q, Distance &R ){
	R.feet = P.feet + Q.feet;
	R.inches = P.inches + Q.inches;
	if( R.inches >= 12 ){
		R.feet = R.feet + R.inches / 12;
		R.inches = R.inches % 12;
	}
}
int main(){
	Distance D1, D2, D3;
	D1.get();
	D2.get();
	add( D1, D2, D3 );
	D1.show();
	D2.show();
	D3.show();
	return 0;
}

