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
	friend Distance add(Distance, Distance);
};
Distance add(Distance P, Distance Q){
	Distance temp;
	temp.feet=P.feet+Q.feet;
	temp.inches=P.inches+Q.inches;
	if(temp.inches>=12){
		temp.feet=temp.feet+temp.inches/12;
		temp.inches=temp.inches%12;
	}
	return temp;
}
int main(){
	Distance D1, D2, D3;
	D1.get();
	D2.get();
	D3=add(D1, D2);
	D1.show();
	D2.show();
	D3.show();
	return 0;
}

