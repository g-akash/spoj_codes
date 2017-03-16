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


vector<ll> vec(1000005);

void getsums()
{
	for(ll i=1;i<vec.size();i++)
	{
		//cout<<i<<endl;
		for(ll j=2*i;j<vec.size();j+=i)
		{
			vec[j]+=i;
		}
	}
	return;
}

int main()
{
	getsums();
	int t;
	cin>>t;
	while(t--)
	{
		ll a,b,an=0;
		ll ans=1000000000000;
		cin>>a>>b;
		for(int i=a;i<=b;i++)
		{
			if(vec[i]*an<ans*i)
			{
				ans=vec[i];
				an=i;
			}
		}
		//cout<<vec[8]/double(8)<<endl;
		cout<<an<<endl;

	}
}