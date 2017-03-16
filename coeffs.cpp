#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

#define ll long long int

vector<ll> v;

int main()
{
	v.resize(15);
	v[0]=1;
	for(ll i=1;i<15;i++)v[i]=i*v[i-1];
	ll n,k;
	while(cin>>n>>k)
	{
		ll ans=v[n];
		ll var;
		for(int j=0;j<k;j++)
		{
			cin>>var;
			ans/=v[var];
		}
		cout<<ans<<endl;
	}
}
