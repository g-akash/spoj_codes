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


/*
	ci-1 = 0 and ci = 0
	55 cases
	ci-1=0 and ci=1
	45 cases
	ci-1 = 1 and ci = 0
	45 cases
	ci-1 = 1 and ci = 1
	55 cases
*/

umm(ll,ll) m;

ll get_ans(ll a, ll b, ll c)
{
	if(c>b)return 0;
	if(b==0)return 1;
	ll var = a*100000000+b*10000+c;
	if(m.find(var)!=m.end())return m[var];
	if(a==0)
	{
		ll ans1 = get_ans(0,b-1,c)*55;
		ll ans2 = 0; 
		if(c>=1)ans2 = get_ans(1,b-1,c-1)*45;
		ans1+=ans2;
		ans1 = ans1 DIV;
		m[var] = ans1;
		return ans1;
	}
	else
	{
		ll ans1 = get_ans(0,b-1,c)*45;
		ll ans2 = 0;
		if(c>=1)ans2 = get_ans(1,b-1,c-1)*55;
		ans1+=ans2;
		ans1 = ans1 DIV;
		m[var] = ans1;
		return ans1;
	}

}


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll n,k;
		cin>>n>>k;
		cout<<get_ans(0,n,k)<<endl;
	}
}