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
#define DIV %1000000007



ll get_power(ll a, ll b)
{
	ll tmp = a,ans=1;
	while(b>0)
	{
		if(b%2==1)
		{
			ans*=tmp;
			ans=ans DIV;
		}
		tmp = tmp * tmp;
		tmp = tmp DIV;
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
		ll a,b,c,d,n,m;
		cin>>n>>m;
		cin>>a>>b>>c>>d;
		c-=a;
		ll ans = get_power(m,abs(c));
		cout<<ans<<endl;
	}
}