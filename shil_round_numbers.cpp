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

ll n,q;
vector<ll> vec,orig;

ll is_round(ll x)
{
	if(x<0)return 0;
	if(x<10)return 1;
	ll frst = x%10;
	x/=10;
	ll sec;
	while(x!=0)
	{
		sec = x%10;
		x/=10;
	}
	if(frst==sec)return 1;
	return 0;
}


void insert(ll ind, ll val)
{
	while(ind<n+1)
	{
		//cout<<ind<<endl;
		vec[ind]+=val;
		ind += (ind&-ind);
	}
	return;
}

ll get_sum(ll ind)
{
	ll ans = 0;
	while(ind>0)
	{
		//cout<<ind<<endl;
		ans+=vec[ind];
		ind-=(ind&-ind);
	}
	return ans;
}

ll get_ans(ll a, ll b)
{
	if(a==1)return get_sum(b);
	return get_sum(b)-get_sum(a-1);
}



int main()
{
	
	cin>>n>>q;

	vec.resize(n+1);
	orig.resize(n+1);
	ll var;
	foi(n)
	{
		cin>>var;
		if(is_round(var))
		{
			orig[i+1]=1;
			insert(i+1,1);
		}
		else
		{
			orig[i+1]=0;
			insert(i+1,0);
		}
	}
	//cout<<get_ans(4,4)<<orig[5]<<vec[5]<<endl;
	foi(q)
	{
		ll a,b,c;
		cin>>a>>b>>c;
		if(a==1)
		{
			cout<<get_ans(b,c)<<endl;
		}
		else
		{
			int rnd = is_round(c);
			if(rnd==0&&orig[b]==1)
			{
				orig[b]=0;
				insert(b,-1);
			}
			else if(rnd==1&&orig[b]==0)
			{
				orig[b]=1;
				insert(b,1);
			}
		}
	}


}