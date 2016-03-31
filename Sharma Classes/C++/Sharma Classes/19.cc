/*
 * Program to calculte area of the figure selected by the user.
 * The Figures are rectangle and square and calculation of area must be done using the trick of Default Function Argument
 */
#include<iostream>
using namespace std;
int getArea(int = 0 , int = 0);
int main(){
	int l,b,fig,area;
	cout<<"1. Rectangle\t2. Square\nSelect the Figure : ";
	cin>>fig;
	switch(fig){
		case 1:
			cout<<"Enter the sides of Rectangle : ";
			cin>>l>>b;
			area=getArea(l,b);
			break;
		case 2:
			cout<<"Enter the side of Square : ";
			cin>>l;
			area=getArea(l);
			break;
		default:
			cout<<"Wrong Choice";
			return 0;
		}
	cout<<"Area is "<<area;
	return 0;
}
int getArea(int l, int b){
	if ( b == 0 )
		return (l*l);
	else
		return (l*b);
}
