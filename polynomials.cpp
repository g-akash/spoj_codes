#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <math.h>
#include <map>
#include <queue>
#include <algorithm>
#include <list>

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
#define MAX 1e18+5


int main()
{
	ll n,k;
	cin>>n>>k;
	vector<ll> vec(n+1),pref(n+1),suf(n+1);
	foi(n+1)cin>>vec[i];
	ll var=0;
	foi(n+1)
	{
		pref[i]=var/2+vec[i];
		var=pref[i];
		if(var%2!=0)
		{
			for(int j=i+1;j<=n;j++)
			{
				pref[j]=MAX;
			}
			break;
		}
	}
	var=0;
	for(int i=n;i>0;i--)
	{
		suf[i-1]=var*2+vec[i];
		var=suf[i-1];
		suf[i-1]*=2;
		if(abs(suf[i-1])>=MAX)
		{
			for(int j=i-1;j>=0;j--)suf[j]=MAX;
			break;
		}
	}
	int ans=0;
	for(int i=0;i<=n;i++)
	{
		//cout<<suf[i]<<" "<<pref[i]<<endl;
		if(suf[i]!=MAX&&pref[i]!=MAX)
		{
			ll maybe = suf[i]+pref[i];
			//cout<<maybe<<" maybe"<<endl;
			if(maybe==vec[i]&&i==n)continue;
			maybe-=vec[i];
			if(abs(maybe)<=abs(k)){ans++;}
			//else cout<<i<<endl;
		}
		if(pref[i]==MAX)break;
	}
	cout<<ans<<endl;



}