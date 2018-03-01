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

ll l,t,d;

ll gcd(ll a, ll b)
{
	if(a==0&&b!=0)return b;
	else if(b==0&&a!=0)return a;
	else if(a==0&&b==0)return (ll)1;
	if(a%b==0)return b;
	return gcd(b,a%b);
}


void do_add(ll &a, ll &b, ll x, ll y)
{
	//cout<<a<<" "<<b<<" "<<x<<" "<<y<<endl;
	ll tmpa = (b*b-a*a)*(y*y-x*x);
	ll tmpb = b*y;
	ll tmpc = a*x;
	//cout<<tmpa<<" "<<"tmpa"<<endl;
	tmpa = (ll)sqrt(tmpa);
	tmpc-=tmpa;
	ll gd = gcd(tmpc,tmpb);
	tmpc/=gd;
	tmpb/=gd;
	a=tmpc;
	b=tmpb;
	//cout<<a<<" "<<b<<endl;
	return;
}

bool check_power(ll x)
{
	while(x>0)
	{
		if(x%2==1&&x!=1)return false;
		x/=2;
	}
	return true;
}

vll get_cos(ll x)
{
	if(!check_power(x))
	{
		vll tans(2);
		tans[1]=1;
		return tans;
	}
	ll a=d,b=l;
	ll gd = gcd(a,b);
	a/=gd;
	b/=gd;
	ll ans1=1,ans2=1;
	while(x!=0)
	{
		if(x%2==1)
		{
			do_add(ans1,ans2,a,b);
		}
		a = ((ll)2*a*a-b*b)%1000000007;
		b=(b*b)%1000000007;
		//gd = gcd(a,b);
		//a/=gd;
		//b/=gd;
		x/=2;
	}

	vll ans(2);
	//cout<<ans1<<" "<<ans2<<" kk"<<endl;
	ans[0]=ans1;
	ans[1]=ans2;
	return ans;
}


ll poww(ll a, ll b)
{
	ll curr = a;
	ll ans = 1;
	while(b>0)
	{
		if(b%2==1)
		{
			ans*=curr;
		}
		curr=curr*curr;
		curr=(curr)%1000000007;
		ans%=1000000007;
		b/=2;
	}
	return ans;
}

int main()
{
	int test;
	cin>>test;
	while(test--)
	{
		//t-=1;
		//cout<<t<<endl;
		cin>>l>>d>>t;
		if(t>3)
		{
			cout<<0<<endl;
			continue;
		}
		if(t==1)
		{
			cout<<d<<endl;
			continue;
		}
		vll ans(2);
		if(t==2)
		{
			ans[0]=2*d*d-l*l;
			ans[1]=l*l;
			ll gd = abs(gcd(ans[0],ans[1]));
			ans[0]/=gd;
			ans[1]/=gd;
		}
		else if(t==3)
		{
			ll tmp1,tmp2;
			tmp1 = 4*d*d-3*l*l;
			tmp2 = l*l;
			ll gd = abs(gcd(tmp1,tmp2));
			tmp1/=gd;
			tmp2/=gd;
			tmp1*=d;
			tmp2*=l;
			gd = abs(gcd(tmp1,tmp2));
			tmp1/=gd;
			tmp2/=gd;
			ans[0]=tmp1;
			ans[1]=tmp2;
		}
		//cout<<ans[0]<<" "<<ans[1]<<endl;
		ans[0]*=l;
		ll gd = abs(gcd(ans[0],ans[1]));
		ans[0]/=gd;
		ans[1]/=gd;
		//while(ans[0]<0)ans[0]+=1000000007;
		ans[1] = poww(abs(ans[1]),1000000005);
		//cout<<ans[1]<<endl;
		ll fin_ans = (ans[0]*ans[1])%1000000007;
		while(fin_ans<0)fin_ans+=1000000007; 
		cout<<fin_ans<<endl;

	}
}