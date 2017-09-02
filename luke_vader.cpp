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
#define MX 200005
#define DIV %1000000007
#define MAX 1000000007

vll facts,inv_facts;

void make_facts()
{
	facts[0]=1;
	for(ll i=1;i<MX;i++)
	{

		facts[i]=facts[i-1]*i;
		facts[i]= facts[i] DIV;

	}
	return;
}

ll get_power(ll a, ll b)
{
	ll tmp=a,ans=1;
	while(b>0)
	{
		if(b%2==1)
		{
			ans=ans*tmp;
			ans = ans DIV ;
		}
		tmp = tmp * tmp;
		tmp = tmp DIV;
		b/=2;

	}
	return ans;
}


void calc_inv_facts()
{
	inv_facts[0]=1;
	for(int i=1;i<MX;i++)
	{
		inv_facts[i] = get_power(facts[i],MAX-2);
	}
	return;
}

ll ncr(ll a, ll b)
{
	ll ans = 1;
	ans = ans*facts[a];
	ans = ans * inv_facts[b];
	ans = ans DIV;
	ans = ans * inv_facts[a-b];
	ans = ans DIV;
	return ans;
}




int main()
{
	facts.resize(MX);
	inv_facts.resize(MX);
	make_facts();
	calc_inv_facts();
	int t;
	cin>>t;
	for(int k=1;k<=t;k++)
	{
		ll a,b,c,d;
		cin>>a>>b>>c>>d;
		a = c-a;
		b = d-b;
		ll sm = a+b, mn = min(a,b);
		ll ans = 0;
		for(int i=0;i<=mn;i++)
		{
			ans+=(ncr(sm-i,i)*ncr(sm-i-i,mn-i));
			ans = ans DIV;

		}
		cout<<"Case "<<k<<": "<<ans<<endl;
	}
}