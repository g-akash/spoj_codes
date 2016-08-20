#include <bits/stdc++.h>

using namespace std;

#define ll long long int


int main()
{
	ll n,m;
	cin>>n>>m;
	vector<ll> peop,twer;
	peop.resize(n);
	twer.resize(m+2);
	for(int i=0;i<n;i++)
	{
		cin>>peop[i];
	}
	twer[0]=-100000000000;
	for(int i=1;i<=m;i++)
	{
		cin>>twer[i];
	}
	twer[m+1]=100000000000;
	ll ans=0;
	ll pos=0;
	for(int i=0;i<=m;i++)
	{
		while(peop[pos]<=twer[i+1])
		{
			if(pos>=n)break;
			ans=max(ans,min(twer[i+1]-peop[pos],peop[pos]-twer[i]));
			pos++;
			if(pos>=n)break;
		}
	}
	cout<<ans<<endl;
}