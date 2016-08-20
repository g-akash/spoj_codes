#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

#define ll long long int

int main()
{
	ll n;
	cin>>n;
	ll m;
	cin>>m;
	vector<ll> v;
	v.resize(n);
	for(ll i=0;i<n;i++)
	{
		cin>>v[i];
	}
	ll hf=n/2;
	while(hf*2<n)hf++;
	hf--;
	ll ans=0;
	sort(v.begin(),v.end());
	for(ll i=0;i<=hf;i++)v[i]-=m;
		for(ll i=hf+1;i<n;i++)v[i]+=m;
	for(ll j=0;j<(ll)(n-1);j++)
	{
		ans+=(((j+1)*(n-1-j))*(v[j+1]-v[j]));
	}
	cout<<ans<<endl;

}