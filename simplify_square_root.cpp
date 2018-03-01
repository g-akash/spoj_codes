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

vll primes;
vll ans;


void make_primes()
{
	vi prims(10000005);
	for(int i=2;i<10000005;i++)
	{
		if(prims[i])continue;
		//cout<<i<<endl;
		primes.pb((ll)i*(ll)i);
		for(int j=2*i;j<10000005;j+=i)prims[j]=1;
	}
	return;
}

void make_multiples()
{
	vi tmp(5*1e7);
	for(int i=0;i<primes.size();i++)
	{
		ll curr = primes[i];
		while(curr<5*1e7)
		{
			tmp[curr]=1;
			curr+=primes[i];
		}
	}
	foi(5*1e7)
	{
		if(tmp[i])
		{
			ans.pb(i);
		}
	}
	return;
}

double pi = 3.14159265358979323;


ll get_num(ll mid)
{
	double tmp = ((double)(1.0)-(double)(6.0)/(pi*pi))*(double)(mid);
	return (ll)tmp;
}

bool sqful(ll val)
{
	foi(primes.size())
	{
		if(val%(ll)primes[i]==0)return true;
	}
	return false;
}

int main()
{
	ll n;
	cin>>n;
	make_primes();
	make_multiples();
	n-=1;
	//cout<<get_num(25505464)<<endl;
	//cout<<sqful(25505464)<<endl;
	// if(n<(ll)(ans.size()))
	// {
	// 	cout<<ans[n]<<endl;
	// } else {
		n+=1;
		ll x = 0;
		ll y =  4*1e15;
		while(y-x>1)
		{
			//cout<<x<<" "<<y<<endl;
			ll mid = (x+y)/2;
			if(get_num(mid)<(ll)n)
			{
				x=mid;
			}
			else {
				y = mid;
			}
		}
		//cout<<y<<endl;
		if(sqful(y))cout<<y<<endl;
		else if(sqful(y+(ll)1))cout<<y+(ll)1<<endl;
		else if(sqful(y+(ll)2))cout<<y+(ll)2<<endl;
		else if(sqful(y+(ll)3))cout<<y+(ll)3<<endl;

	//}
}