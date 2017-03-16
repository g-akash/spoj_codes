#include<iostream>


using namespace std;

int main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		int a,b;
		int n,var;
		char ch;
		cin>>n>>b;
		for(int i=0;i<n;i++)
		{
			cin>>ch;
			if(ch=='P'){cin>>var;a=b;b=var;}
			else {var=b;b=a;a=var;}
		}
		cout<<b<<endl;
	}
}
