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

umm(ll,ll) um;

ll get_num(ll x)
{
	if(um.find(x)==um.end())return 0;
	return um[x];
}

int main()
{
	ll t,var;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		vi vec(n);
		foi(n)cin>>vec[i];
		um.clear();
		ll ans=0,beg=0,curr=0;
		for(ll i=0;i<n;i++)
		{
			curr=i;
			um[vec[curr]]++;
			while(um[vec[curr]]>1)
			{
				um[vec[beg]]-=1;
				beg++;
			}
			var = (curr-beg+1);
			ans+=(var*(var+1))/2;
		}
		cout<<ans<<endl;
	}
	
}