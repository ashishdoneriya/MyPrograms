#include<iostream>
using namespace std;

class Date{
	int day,month,year;
public:
	void setDate(int, int, int);
	void showDate();
};

void Date::setDate(int d, int m, int y){
	day=d;
	month=m;
	year=y;
}
void Date::showDate(){
	cout<<"Day = "<<day<<"\tMonth = "<<month<<"\tYear = "<<year<<endl;
}

int main(){
	Date A,B;
	return 0;
}


