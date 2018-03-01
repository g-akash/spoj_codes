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

vll vec;
ll ans = 0;


ll make_ans(int a, int b)
{
	ll mx = 0;
	int ind;
	for(int i=a;i<=b;i++)
	{
		if(vec[i]>mx)
		{
			ind = i;
			mx = vec[i];
		}
	}
	if(ind-1>=a)
	{
		ll lm = make_ans(a,ind-1);
		ans+=mx;
	}
	if(ind+1<=b)
	{
		ll rm = make_ans(ind+1,b);
		ans+=mx;
	}
	return mx;
}


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vec.resize(n);
		foi(n)cin>>vec[i];
		ans = 0;
		ll mx = make_ans(0,n-1);
		cout<<ans<<endl;

	}
}