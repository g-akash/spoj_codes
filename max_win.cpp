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
		int n;
		cin>>n;
		string s1,s2;
		cin>>s1>>s2;
		vector<int> v;
		v.resize(n+1);
		for(int j=0;j<=n;j++)cin>>v[j];
		int cor=0,incor=0;
		for(int j=0;j<n;j++)if(s1[j]==s2[j])cor++;else incor++;
		int maxx_val=-10000000;
		for(int j=0;j<=cor;j++)maxx_val=max(maxx_val,v[j]);
		if(incor>0)cout<<maxx_val<<endl;
		else cout<<v[n]<<endl;
	}
}
