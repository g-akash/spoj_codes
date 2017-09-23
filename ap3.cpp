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
	int t;
	cin>>t;
	foi(t)
	{
		double x,y,z;
		cin>>x>>y>>z;
		double w = (y-x), u = (x+y);
		double a = u, b = (-6.0*u+w-2.0*z), c = 12.0*z;
		double d = sqrtl((ll)(b*b-4.0*a*c));
		double n = (-b+d)/(2.0*a), n2 = (-b-d)/(2.0*a);
		double cd_d = w/(n-6.0);
		double f = x-2.0*cd_d;
		ll cd = ceil(cd_d);
		cout<<ceil(n)<<endl;
		ll ans = ceil(f);
		for(ll j=0;j<n;j++){cout<<ans<<" ";ans+=cd;}cout<<endl;
	}
}