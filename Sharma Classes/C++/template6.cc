#include<iostream>
using namespace std;
template <class stack_type=int, int N=10>
class Stack{
	stack_type arr[N];
	int tos;
public:
	Stack(){tos=-1;}
	void push(stack_type num);
	stack_type pop();
};

template <class stack_type, int N> void Stack<stack_type, N>::push(stack_type num){
	if(tos==N-1){
		cout<<"Stack is full"<<endl;
		return;
	}
	arr[++tos]=num;
}
template <class stack_type, int N> stack_type Stack<stack_type, N>::pop(){
	if(tos==-1){
		cout<<"Stack is empty"<<endl;
		return 0;
	}
	stack_type x = arr[tos--];
	return x;
}

int main(){
	Stack<const char *,5> s1;
	char str[15];
	for(int i=1; i<6; i++){
		cout<<"Enter the string : ";
		cin>>str;
		s1.push(str);
	}
	cout<<"poped element = "<<s1.pop()<<endl;
	cout<<"poped element = "<<s1.pop()<<endl;
	cout<<"poped element = "<<s1.pop()<<endl;
	cout<<"poped element = "<<s1.pop()<<endl;
	cout<<"poped element = "<<s1.pop()<<endl;
	return 0;
}
