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
		cout<<feet<<" "<<inches;
	}
	int operator == ( Distance );
	int operator > (Distance );
};
int Distance::operator == ( Distance Q){
	int x, y;
	x = feet * 12 + inches;
	y = Q.feet * 12 + Q.inches;
	if( x == y)
		return 1;
	else
		return 0;
}
int Distance::operator > ( Distance Q){
	int x, y;
	x = feet * 12 + inches;
	y = Q.feet * 12 + Q.inches;
	if( x > y)
		return 1;
	else
		return 0;
}
int main(){
	Distance D1, D2;
	D1.get();
	D2.get();
	if( D1 == D2)
		cout<<"Distances are equal";
	else if ( D1 > D2 )
		D1.show();
	else
		D2.show();
	cout<<" is greater";
	return 0;
}
