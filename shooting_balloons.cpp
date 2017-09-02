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

vll vec;
ll n,k;

ll get_less_seq(ll sum)
{
	ll curr_sum=0,ans=0;
	ll x=0;
	for(ll i=0;i<n;i++)
	{
		curr_sum+=vec[i];
		while(curr_sum>sum)
		{
			curr_sum-=vec[x];
			x++;
		}
		ans+=(i-x+1);

	}
	//cout<<sum<<" get_seq "<<ans<<endl;
	return ans;
}

int main()
{
	
	cin>>n>>k;
	vec.resize(n);
	foi(n)
	{
		cin>>vec[i];
	}
	ll x=-1,y=1e14;
	while(y-x>1)
	{
		ll mid = (x+y)/2;
		ll less_seq = get_less_seq(mid);
		if(less_seq<k)
		{
			x=mid;
		}
		else
		{
			y=mid;
		}

	}
	cout<<y<<endl;
	
}