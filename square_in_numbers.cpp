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


vll primes;
void make_primes()
{
	vi prims(1000005);
	for(int i=2;i<1000005;i++)
	{
		if(prims[i]==1)continue;
		primes.pb((ll)i);
		for(int j=2*i;j<1000005;j+=i)prims[j]=1;
	}
	return;
}

ll get_gcd(ll a, ll b)
{
	if(a%b==0)return b;
	return get_gcd(b,a%b);
}


int main()
{
	make_primes();
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vll vec(n);
		foi(n)cin>>vec[i];
		ll ans =0,gcd;
		foi(n)
		{
			if(ans!=0)break;
			for(int j=i+1;j<n;j++)
			{
				gcd=get_gcd(vec[i],vec[j]);
				if(gcd!=1)
				{
					ans=gcd;
					break;
				}
			}
		}
		if(ans!=0)
		{
			cout<<ans<<endl;
		}
		else
		{
			foi(n)
			{
				if(ans!=0)break;
				foj(primes.size())
				{
					if(vec[i]%(primes[j]*primes[j])==0)
					{
						ans=primes[j];
						break;
					}
					else if(vec[i]%primes[j]==0)vec[i]/=primes[j];
				}
			}
			if(ans!=0)
			{	
				cout<<ans<<endl;
			}
			else
			{
				foi(n)
				{
					ll srt = (ll)(sqrt(vec[i]));
					if(srt*srt==vec[i] && srt!=1)
					{
						ans=srt;
						break;
					}
				}
				cout<<ans<<endl;
			}
		}
	}
}