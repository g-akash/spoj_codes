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


ll gcd(ll a, ll b)
{
	if(a%b==0)return b;
	return gcd(b,a%b);
}


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		ll ans = 0;
		ll srt = sqrt(n);
		if(n==1)
		{
			cout<<"1/1"<<endl;
			continue;
		}
		for(ll i=1;i<=srt;i++)
		{
			ans+=n/i;
		}
		ll lim=srt;
		if(srt*srt==n)lim = srt-1;
		for(ll i=1;i<=lim;i++)
		{
			ll tp = (ll)floor(double(n)/double(i));
			ll st;
			if(n%(i+1)==0)
			{
				st=n/(i+1)+1;
			}
			else
			{
				st = ceil(double(n)/double(i+1));
			}
			ans+=i*(tp-st+1);
		}
		ll mx = n*n;
		ll gd = gcd(mx,ans);
		cout<<ans/gd<<"/"<<(n*n)/gd<<endl;
	}
}