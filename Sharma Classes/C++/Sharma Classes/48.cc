//Overloading operator + on string
#include<iostream>
#include<string.h>
using namespace std;
class String{
	char str[20];
public:
	String ( const char *p ){
		strcpy( str , p );
	}
	String(){
	}
	void show(){
		cout<<str<<endl;
	}
	String operator + ( String S ){
		String Temp;
		strcpy( Temp.str , str );
		strcat( Temp.str, S.str );
		return Temp;
	}
};
int main(){
	String S1 = "Hello ";
	String S2 = "how r u?";
	String S3;
	S3 = S1 + S2;
	S1.show();
	S2.show();
	S3.show();
	return 0;
}
