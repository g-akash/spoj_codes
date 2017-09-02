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


vll days;
ll k,n;



ll get_eggs(ll x, ll d)
{
	ll i=0,j=1e9;
	while(j-i>1)
	{
		ll mid = (i+j)/2;
		ll days_needed = mid*days[x]+(mid*(mid-1))/2;
		if(days_needed<=d)i=mid;
		else j=mid;
	}
	//cout<<days[x]<<" "<<d<<" "<<i<<endl;
	return i;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n>>k;
		days.resize(n);
		foi(n)cin>>days[i];
		ll x=0,y=1e18;
		while(y-x>1)
		{
			ll mid = (x+y)/2;
			ll tot_eggs=0;
			foi(n)
			{
				tot_eggs+=get_eggs(i,mid);
			}
			//cout<<tot_eggs<<endl;
			if(tot_eggs>=k)y=mid;
			else x=mid;
		}
		cout<<y<<endl;
	}
}