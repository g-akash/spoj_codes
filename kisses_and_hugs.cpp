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
#define MAX 1000000007


ll get_pow(ll a, ll b)
{
	ll ans = 1;
	ll curr = a;
	while(b!=0)
	{
		if(b%2==1)
		{
			ans*=curr;
		}
		ans=ans%(MAX);
		curr=curr*curr;
		curr=curr%(MAX);
		b/=2;
	}
	return ans;
}


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		if(n%2==0)
		{
			ll var = n/2;
			var = get_pow(2,var);
			var*=3;
			var%=(MAX);
			var-=2;
			if(var<0)var+=(MAX);
			cout<<var<<endl;
		} else {
			ll var = n/2+2;
			var = get_pow(2,var);
			var-=2;
			if(var<0)var+=(MAX);
			cout<<var<<endl;
		}
	}
}