#include<iostream>
using namespace std;
class Subject{
protected:
	int p, c, m;
public:
	void get(){
		cout<<"Enter marks in Physics, Chemistry and Maths ";
		cin>>p>>c>>m;
	}
	void show(){
		cout << p << " " << c << " " << m << endl;
	}
};
class Student:public Subject{
protected:
	int roll;
	char name[20];
public:
	void get(){
		Subject::get();
		cout<<"Enter roll no. and name ";
		cin>>roll>>name;
	}
	void show(){
		cout<<roll<<" "<<name<<endl;
	}
};
class Sports{
protected:
	int spm;
public:
	void get(){
		cout<<"Enter sports marks ";
		cin>>spm;
	}
	void show(){
		cout<<spm<<endl;
	}
};
class Result:public Student, public Sports{
	int total;
public:
	Result(){
		get();
		calculate();
		show();
	}
	void get(){
		Student::get();
		Sports::get();
	}
	void calculate(){
		total = p + c + m + spm;
	}
	void show(){
		Student::show();
		Subject::show();
		Sports::show();
		cout<<"Total = "<<total<<endl;
	}
};
int main(){
	Result R;
}

