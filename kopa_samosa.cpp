#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

#define ll long long int

int main()
{
	int t;
	cin>>t;
	for(int count=0;count<t;count++)
	{
		ll n;
		cin>>n;
		vector<ll> v;
		v.resize(n);
		ll ans=0,cs=0;
		cin>>v[0];
		cs=v[0];
		for(ll i=1;i<n;i++)
		{
			cin>>v[i];
			ans+=(v[i]*i-cs);
			cs+=v[i];
		}
		cout<<ans<<endl;
	}
}