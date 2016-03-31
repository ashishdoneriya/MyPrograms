#include<iostream>
using namespace std;
void printline(char = '*', int = 10);

void printline(char ch, int n){
	for(int i=1; i<=n; i++)
		cout<<ch;
	cout<<endl;
}
int main(){
	printline('#',5);
	printline('?');
	printline();
	return 0;
}
