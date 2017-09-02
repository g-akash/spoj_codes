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

vll fact(100005),inv_fact(100005);


ll power(ll a, ll b)
{
	ll ans=1,var=a;
	while(b!=0)
	{
		if(b%2==1)
		{
			ans*=var;
			ans = ans DIV;
		}
		b/=2;
		var*=var;
		var = var DIV;
	}
	return ans;
}

void pre_calculate()
{
	fact[0]=1;
	foi1(100004)
	{
		fact[i]=fact[i-1]*i;
		fact[i]=fact[i] DIV;
	}
	foi(100005)
	{
		inv_fact[i]=power(fact[i],1000000005) DIV;
	}
	return;

}


int main()
{
	ll t;
	scanf("%lld",&t);
	pre_calculate();
	//cout<<"done"<<endl;
	
	while(t--)
	{
		ll n,b,p,v;
		scanf("%lld %lld",&n,&b);
		vi vec(105);
		foi(n)
		{
			scanf("%lld %lld",&p,&v);
			if(v==1)
			{
				vec[p]+=1;
			}
		}
		ll ans = 1,x=104;
		//foi(105)cout<<vec[i]<<" ";cout<<endl;
		while(b>0&&x>=0)
		{
			if(b>vec[x])
			{
				b-=vec[x];
			}
			else if(b==vec[x])
			{
				b-=vec[x];
			}
			else
			{
				int a=vec[x],c=vec[x]-b;
				//cout<<fact[a]<<" "<<inv_fact[b]<<" "<<inv_fact[c]<<endl;
				ans*=((((fact[a]*inv_fact[b]) DIV)*inv_fact[c]) DIV);
				b=0;
			}
			x--;
		}
		//cout<<b<<" b is here"<<endl;
		if(b==0)printf("%lld\n",ans);
		else printf("0\n");
	}
}