<<<<<<< HEAD
#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <math.h>
#include <map>
#include <queue>

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

umm(long long int, long long int) um;
vector<ll> v;
ll gcd(int x, int y)
{
	if(x%y==0)return y;
	return gcd(y,x%y);
}
int main()
{
	long long int n,var,t,p,q,count;
	cin>>n;
	
	v.resize(10000000);
	foi(n)
	{
		cin>>var;
		v[var]+=1;
	}
	for(ll i=1;i<=200000;i++)
	{
		var=0;
		count=0;
		while(var<=200000)
		{
			if(v[var]>=1)count+=v[var];
			var+=i;
		}
		um[i]=count;
	}
	cin>>t;
	foi(t)
	{
		count=0;
		cin>>p>>q;
		ll ans=0;
		ans+=um[p];
		if(q!=p)
		{
			ans+=um[q];
			ll gd = gcd(p,q);
			ll lm = (p*q)/gd;
			if(lm<=200000)ans-=um[lm];
		}
		cout<<ans<<endl;
	}

=======
#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		string s;
		cin>>s;
		int r2=0,r5=0;
		for(int j=0;j<s.length();j++)
		{
			r2=(r2*10+int(s[j])-48)%252;
			r5=(r5*10+int(s[j])-48)%525;
		}
		if(r2==0)cout<<"Yes ";
		else cout<<"No ";
		if(r5==0)cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
>>>>>>> 605cad988f52511160a1c156a1f635a23974d531
}