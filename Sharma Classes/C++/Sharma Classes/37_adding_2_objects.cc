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
	void add(Distance, Distance);
};
void Distance::add(Distance P, Distance Q){
	feet=P.feet+Q.feet;
	inches=P.inches+Q.inches;
	if(inches>=12){
		feet=feet+inches/12;
		inches=inches%12;
	}
}
int main(){
	Distance D1, D2, D3;
	D1.get();
	D2.get();
	D3.add(D1, D2);
	D1.show();
	D2.show();
	D3.show();
	return 0;
}
