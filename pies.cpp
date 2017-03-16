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
#define vll vector<ll>
#define vvll vector<vll >
#define si size()



int main()
{
	ll t;
	cin>>t;
	for(ll k=1;k<=t;k++)
	{
		ll n,m;
		cin>>n>>m;
		vvi costs;
		costs.resize(n);
		for(ll i=0;i<n;i++)
		{
			costs[i].resize(m);
			for(ll j=0;j<m;j++)
			cin>>costs[i][j];
			sort(costs[i].begin(),costs[i].end());
		}
		vll pos(n);
		vll add(n);
		for(ll i=0;i<n;i++)
		{
			pos[i]=0;
			add[i]=1;
		}
		ll tot=0,count=0;
		while(count<n)
		{
			ll minp=0,minval=100000000000;
			for(ll i=0;i<count+1;i++)
			{
				if(pos[i]<m)
				{
					if(minval>costs[i][pos[i]]+add[i])
					{
						minp=i;
						minval=costs[i][pos[i]]+add[i];
					}
				}
			}
			count++;
			tot+=minval;
			add[minp]+=2;
			pos[minp]+=1;
		}

	cout<<"Case #"<<k<<": "<<tot<<endl;
	}
}