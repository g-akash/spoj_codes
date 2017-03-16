#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <math.h>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;


#define ll long long int
#define umm(x,y) unordered_map<x,y >
#define pb push_back
#define foi(n) for(int i=0;i<n;i++)
#define foj(n) for(int j=0;j<n;j++)
#define foi1(n) for(int i=1;i<=n;i++)
#define vi vector<int>
#define vvi vector<vi >
#define si size()
vector<ll> prm;

void mk()
{
	vector<ll> v;
	v.resize(1000005);
	for(int i=2;i<1000005;i++)
	{
		for(int j=2*i;j<1000005;j+=i)
			v[j]=1;
	}
	for(int i=2;i<1000005;i++)
	{
		if(v[i]==0)prm.pb((ll)i);
	}
	
}

vector<ll> v1,v2;

ll gp(ll x, ll y)
{
	ll var=x;
	var%=1000000007;
	ll ans=1;
	while(y>0)
	{
		if(y%2==1)ans*=var;
		ans%=1000000007;
		var*=var;
		var%=1000000007;
		y/=2;
	}
	return ans;
}


ll get_num()
{
	ll ans=1,var;
	foi(v1.size())
	{
		var=gp(v1[i],v2[i]);
		while(var<0)var+=1000000007;
		ans*=var;
		ans%=1000000007;
	}
	return ans;
}

int main()
{
	int t;
	mk();
	cin>>t;
	foj(t)
	{
		ll a,b,c;
		v1.resize(0);
		v2.resize(0);
		cin>>a>>b>>c;
		
		umm(ll,ll) u1,u2;
		for(int i=0;i<prm.size();i++)
		{
			
			while(a>1&&a%prm[i]==0)
			{
				a/=prm[i];
				u1[prm[i]]++;
				
			}
		}
		if(a!=1)u1[a]++;
		for(int i=0;i<prm.size();i++)
		{
			while(b>1&&b%prm[i]==0)
			{

				b/=prm[i];
				u2[prm[i]]+=c;
				
			}
		}
		if(b!=1)u2[b]+=c;

		umm(ll,ll)::iterator it=u2.begin();
		while(it!=u2.end())
		{
			if(u1.find(it->first)!=u1.end())
				v2.pb(max((it->second)-u1[it->first],(ll)0));
			else v2.pb((it->second));
			v1.pb(it->first);
			it++;
		}

		cout<<get_num()<<endl;

	}
}