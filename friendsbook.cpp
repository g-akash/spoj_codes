#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	vector<int> v;
	v.resize(100000);
	int n,var,m,vex;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>var>>m;
		v[var]=1;
		for(int i=0;i<m;i++)
		{
			cin>>vex;
			if(v[vex]!=1)v[vex]=2;
		}

	}
	int ans=0;
	for(int i=0;i<100000;i++)
		if(v[i]==2)ans++;
	cout<<ans<<endl;

}