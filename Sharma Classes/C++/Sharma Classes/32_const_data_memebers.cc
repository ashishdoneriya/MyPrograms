#include<iostream>
using namespace std;
class Circle{
	int rad;
	const float pie;
public:
	Circle();
	void show();
};
Circle::Circle():pie(3.14),rad(5)
{
}
void Circle::show(){
	cout<<rad<<" "<<pie;
}

int main(){
	Circle c;
	c.show();
}
