#include<iostream>
using namespace std;
class sum
{
    int a;
    int b;
    int c;
public:
    void get();
    void add();
    void display();
};

void sum::get()
{
  cout<<"Enter the two numbers : ";
  cin>>a>>b;
}

void sum::add()
{
  c=a+b;
}

void sum::display()
{
  cout<<"Sum of "<<a<<" and "<<b<<" is "<<c;
}

int main()
{
  sum s;
  s.get();
  s.add();
  s.display();
  return 0;
}
