#include<bits/stdc++.h>

using namespace std;

#define ll long long

int main()
{
	vector<ll int> v;
	v.resize(1000005);
	//unordered_map<ll int,ll int> m;

	for(ll int i=1;i<1000005;i++)
	{
		v[i]=v[i-1]+2*i-1;
	//	m[v[i]]=1;
	}
	int c;
	cin>>c;
	for(ll int i=0;i<c;i++)
	{
		ll int var;
		//cin>>var;
		scanf("%lld",&var);
		string ans="No";
		for(int j=0;j<1000005&&v[j]<=var/2;j++)
		{	
			ll int x=sqrt(var-v[j]);
			if(x*x==var-v[j])
			{
				ans="Yes";
				break;
			}
		}
		cout<<ans<<endl;
	}
}