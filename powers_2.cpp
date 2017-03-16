#include <bits/stdc++.h>

using namespace std;

#define ll long long int

int main()
{
	ll n;
	cin>>n;
	vector<ll> vec;
	unordered_map<ll,ll> um;
	ll temp;
	vector<ll> power;
	power.resize(32);
	power[0]=1;
	for(int i=1;i<32;i++)
	{
		power[i]=2*power[i-1];
	}
	ll ans=0;
	for(int i=0;i<n;i++)
	{
		cin>>temp;
		for(int j=0;j<32;j++)
		{
			if(um.find(power[j]-temp)!=um.end())ans+=um[power[j]-temp];
		}
		if(um.find(temp)!=um.end())um[temp]++;
		else um[temp]=1;
	}
	cout<<ans<<endl;
}
