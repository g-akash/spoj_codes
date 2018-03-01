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


bool div3(ll a, ll b, ll c)
{
	if(c<=100)
	{
		vll vec(c);
		vec[0]=a;
		vec[1]=b;
		vec[2] = (a+b)%10;
		ll sum = a+b+vec[2];

		for(ll i=3;i<c;i++)
		{
			vec[i]=(vec[i-1]*2)%10;
			sum+=vec[i];
		}
		if(sum%3==0)
		{
			return true;
		}
		return false;
	}
	vll vec(100);
	vec[0]=a;
	vec[1]=b;
	vec[2] = (a+b)%10;
	vll pos(10);
	foi(10)
	{
		pos[i]=-1;
	}
	ll strt,period;
	//pos[a]=0;
	//pos[b]=1;
	pos[vec[2]]=2;
	for(ll i=3;i<c;i++)
	{
		//cout<<i<<endl;
		vec[i]=(vec[i-1]*2)%10;
		if(pos[vec[i]]==-1)
		{
			pos[vec[i]]=i;
		}
		else
		{
			strt = pos[vec[i]];
			period = (ll)i-pos[vec[i]];
			break;
		}
	}
	ll sum=0;
	foi(strt)
	{
		sum+=vec[i];
	}
	ll sump = 0;
	for(ll i=strt;i<period+strt;i++)sump+=vec[i];
	c-=strt;
	sum+=(c/period)*sump;
	c%=period;
	for(ll i=strt;i<strt+c;i++)
	{
		sum+=vec[i];
	}
	if(sum%3==0)return true;
	return false;
}


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll k,d0,d1;
		cin>>k>>d0>>d1;
		if(k==1)
		{
			if(d0%3==0)
			{
				cout<<"YES"<<endl;
			}
			else
			{
				cout<<"NO"<<endl;
			}
		}
		else if(k==2)
		{
			if((d0+d1)%3==0)
			{
				cout<<"YES"<<endl;
			}
			else
			{
				cout<<"NO"<<endl;
			}
		}
		else
		{
			if(div3(d0,d1,k))
			{
				cout<<"YES"<<endl;
			}
			else cout<<"NO"<<endl;
		}
	}
}