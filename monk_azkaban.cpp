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


int main()
{
	ll n;
	cin>>n;
	vll vec(n);
	foi(n)cin>>vec[i];
	vll indl(n),indr(n);
	foi(n)
	{
		indl[i]=-1;
		indr[i]=-1;
	}
	stack<ll> val,ind;
	val.push(vec[0]);
	ind.push(0);
	for(ll i=1;i<n;i++)
	{
		while(!val.empty())
		{
			if(vec[i]<=val.top())
			{
				val.push(vec[i]);
				ind.push(i);
				break;
			}
			else
			{
				indr[ind.top()]=i+1;
				val.pop();
				ind.pop();
			}
		}
		if(val.empty())
		{
			val.push(vec[i]);
			ind.push(i);
		}
	}
	while(!val.empty())
	{
		val.pop();
		ind.pop();
	}
	val.push(vec[n-1]);
	ind.push(n-1);
	for(ll i=n-2;i>=0;i--)
	{
		while(!val.empty())
		{
			if(vec[i]<=val.top())
			{
				val.push(vec[i]);
				ind.push(i);
				break;
			}
			else
			{
				indl[ind.top()]=i+1;
				val.pop();
				ind.pop();
			}
		}
		if(val.empty())
		{
			val.push(vec[i]);
			ind.push(i);
		}
	}

	foi(n)cout<<indr[i]+indl[i]<<" ";
	cout<<endl;

}