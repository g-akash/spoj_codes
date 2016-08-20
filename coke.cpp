#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		cout<<"Scenario #"<<i+1<<": ";
	int n;
	long long int mn=1000000000,var=0,vex;
	cin>>n;
	for(int j=0;j<n;j++)
	{
		cin>>vex;
		var+=vex;
		if(mn>var)mn=var;
	}
	if(mn>=0)cout<<1<<endl;
	else cout<<-1*mn+1<<endl;
	cout<<endl;

	}
}