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
	int q;
	cin>>q;
	vll sums,tims;
	tims.pb(0);
	sums.pb(0);
	ll typ,x,t;
	while(q--)
	{
		cin>>typ>>x>>t;
		if(typ==1)
		{
			tims.pb(t);
			sums.pb(sums[sums.size()-1]+x);
		}
		else
		{
			tims.pb(1e11);
			ll x=0,y=tims.size()-1;
			while(y-x>1)
			{
				int mid=(x+y)/2;
				if(tims[mid]>t)y=mid;
				else x=mid;
			}
			ll s2=sums[x];
			t=t-x-1;
			x=0;y=tims.size()-1;
			while(y-x>1)
			{
				int mid=(x+y)/2;
				if(tims[mid]>t)y=mid;
				else x=mid;
			}
			ll s1=sums[x];
			cout<<s2-s1<<endl;
			tims.resize(tims.size()-1);
		}
	}
}