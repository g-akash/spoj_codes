#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		int a,b;
		cin>>a>>b;
		if(a<=2||b<=2)
		{
			for(int j=0;j<a;j++)
			{
				for(int k=0;k<b;k++)cout<<"*";cout<<endl;
			}
		}
		else
		{
			for(int j=0;j<b;j++)cout<<"*";cout<<endl;
			for(int j=1;j<a-1;j++)
			{
				cout<<"*";
				for(int k=1;k<b-1;k++)cout<<".";cout<<"*"<<endl;
			}
			for(int j=0;j<b;j++)cout<<"*";cout<<endl;
		}
	}
}
