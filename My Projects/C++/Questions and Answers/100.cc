#include<fstream.h>
#include<process.h>
void main()
{
	ifstream que,ans,ops;
	que.open("questions.txt");
	ans.open("answers.txt");
	ops.open("options.txt");
	char q,o,a;
	if (!que||!ops||!ans)
	{
		cout<<"File can't be opened";
		exit(1);
	}
	int flag=1,c=0;
	do
	{	
		flag=0;
		do
		{
			if(que.get(q))
				cout<<q;
		}while(q!='\n'&&que.eof()==0);
		if(que.eof()==1)
			cout<<"\n";
		do
		{
			if(ops.get(o))
				cout<<o;
		}while(o!='\n'&&ops.eof()==0);
		if(ops.eof()==1)
			cout<<"\n";
		do
		{
			if(ans.get(a))
				cout<<a;
		}while(a!='\n'&&ans.eof()==0);
		if(!ans.eof())
		{
			flag=1;
			c++;
			if(c%5==0)
				getchar();
			else
				cout<<"\n";
		}
	}while(flag);
	getch();
}
