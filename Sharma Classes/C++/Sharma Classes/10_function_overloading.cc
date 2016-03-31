#include<iostream>
using namespace std;
class Volume{
public:
	void volume(int s);
	void volume(int l, int b, int h);
};
void Volume::volume(int s){
	cout<<"Volume of Cube is "<<(s*s*s)<<endl;
}
void Volume::volume(int l, int b, int h){
	cout<<"Volume of cuboid is "<<l*b*h<<endl;
}

int main(){
	Volume V;
	int ch;
	cout<<"Select a figure\n1.Cube\t2.Cuboid\nEnter your choice : ";
	cin>>ch;
	switch(ch)
	{
		case 1:
				int s;
				cout<<"Enter side of cube : ";
				cin>>s;
				V.volume(s);
				break;
		case 2:
				int l,b,h;
				cout<<"Enter sides of cuboid : ";
				cin>>l>>b>>h;
				V.volume(l,b,h);
				break;
		default:
				cout<<"Wrong choice";
	}
}
