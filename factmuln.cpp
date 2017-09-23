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



ll get_ans(ll x, ll count)
{
	//cout<<x<<" "<<count<<endl;
	ll ans = x-1;
	while(count>0)
	{
		ans+=1;
		ll var = ans;
		while(var/x>0)
		{
			var/=x;
			count-=var;
		}

	}
	return ans;
}

ll fact(ll x)
{
	if(x==1)return 1;
	ll srt = sqrt(x);
	for(ll i=2;i<=srt;i++)
	{
		if(x%i==0)
		{
			ll var1 = x/i, count = 1;
			while(var1%i==0)
			{
				var1/=i;
				//var2*=x;
				count++;
			}
			return max(fact(var1),get_ans(i,count));
		}
	}
	return x;
}


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll x;
		cin>>x;
		if(x==1)
		{
			cout<<1<<endl;
			continue;
		}
		cout<<fact(x)<<endl;
	}
}