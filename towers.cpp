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
		int n,m;
		cin>>n>>m;
		int d;
		cin>>d;
		int var;
		for(int i=0;i<n;i++)
		{
			cin>>var;
			if((var/d)*d<var)m-=(var/d);
			else m-=((var/d)-1);
		}
		if(m<=0){cout<<"YES"<<endl;}
		else cout<<"NO"<<endl;

	}
}