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
		int n,m,var;
		cin>>n>>m;
		int ng=-10000,nm=-10000;
		for(int j=0;j<n;j++)
		{
			cin>>var;
			ng=max(ng,var);
		}
		for(int j=0;j<m;j++)
		{
			cin>>var;
			nm=max(nm,var);
		}
		if(nm>ng)cout<<"MechaGodzilla"<<endl;
		else cout<<"Godzilla"<<endl;

	}
}