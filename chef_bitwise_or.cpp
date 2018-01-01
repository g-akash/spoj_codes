#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <math.h>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <list>
#include <stdio.h>

using namespace std;


#define ll long long int
#define ull unsigned ll
#define umm(x,y) unordered_map<x,y >
#define mm(x,y) map<x,y >
#define pb push_back
#define foi(n) for(int i=0;i<n;i++)
#define foj(n) for(int j=0;j<n;j++)
#define foi1(n) for(int i=1;i<=n;i++)
#define foj1(n) for(int j=1;j<=n;j++)
#define vi vector<int>
#define vb vector<bool>
#define vvi vector<vi >
#define vvb vector<vb >
#define vll vector<ll>
#define vvll vector<vll >
#define si size()

ll n,k;
umm(ll,ll) um;
vvll ors(5001);
vvll sps(5001);
ll vec[5001];

void make_ors()
{
	foi(n){ors[i].resize(5001);sps[i].clear();}
	foi(n)ors[i][i]=vec[i];

	
	foi(n)
	{
		sps[i].pb(i);
		umm(ll,bool) um;
		um[ors[i][i]]=true;
		for(int j=i+1;j<n;j++)
		{
			ors[i][j]=ors[i][j-1]|vec[j];
			if(um.find(ors[i][j])==um.end())
			{
				um[ors[i][j]]=true;
				sps[i].pb(j);
			}
		}
	}
	return;
}

// void make_sps(ll vec[])
// {
// 	sps.resize(n);
// 	foi(n)sps[i].clear();
// 	foi(n)
// 	{
// 		umm(ll,bool) um;
// 		for(int j=i;j<n;j++)
// 		{
// 			if(um.find(ors[i][j])==um.end())
// 			{
// 				um[ors[i][j]]=true;
// 				sps[i].pb(j);
// 			}
// 		}
// 	}
// 	return;
// }






ll get_ans(ll a, ll lef)
{
	if(lef<=0||a>=n)return 0;
	ll val = a*(ll)100000+lef;
	if(um.find(val)!=um.end())return um[val];
	ll curr;
	ll ans = 0;
	ll curr_ans = 0;
	if(lef>1)
	{
		for(ll i=0;i<min((int)(sps[a].size()),30);i++)
		{
			ll ind = sps[a][i];
			curr = ors[a][ind];
			ll got = 0;
			if(n-(ind+1)>=lef-1)
			{
				got = get_ans((ind+1),lef-1);
				curr_ans = curr+got;
				ans = curr_ans>ans?curr_ans:ans;
			}
		}
	} else {
		ans = ors[a][n-1];
	}
	um[val]=ans;
	return ans;

}


int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld %lld",&n,&k);
		um.clear();
		foi(n)scanf("%lld",&vec[i]);
		make_ors();
		//make_sps(vec);
		ll ans = get_ans((ll)0,k);
		printf("%lld\n",ans);

	}
}