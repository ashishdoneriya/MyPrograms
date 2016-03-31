#include<iostream>
using namespace std;
struct val1{
	int age;
	char grade;
};
struct val2{
	int age;
	char per;
};
template <class str> void getAge(str &a){
	cout<<"Enter age ";
	cin>>a.age;
}
int main(){
	struct val1 qw;
	struct val2 we;
	qw.grade='a';
	we.per='2';
	getAge(qw);
	getAge(we);
	cout<<qw.age<<" "<<qw.grade<<endl;
	cout<<we.age<<" "<<we.per<<endl;
	return 0;
}
