#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;

#define ll long long int

int main()
{
	vector<ll> v;
	unordered_map<ll,ll> m;
	ll x;
	int n;
	cin>>n;
	v.resize(n);
	for(int i=0;i<n;i++)cin>>v[i];

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			for(int k=0;k<n;k++)
			{
				x=v[i]*v[j]+v[k];
				m[x]=m[x]+1;
			}
		}
	}

	ll ans=0;
	for(int i=0;i<n;i++)
	{
		if(v[i]!=0){
		for(int j=0;j<n;j++)
		{
			for(int k=0;k<n;k++)
			{

				x=v[i]*(v[j]+v[k]);
				if(m.find(x)!=m.end())ans+=m[x];
			}
		}
	}
}
cout<<ans<<endl;
}