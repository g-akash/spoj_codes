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


class cards
{
	public:
	ll a,d;
};

bool comp(cards p, cards q)
{
	if(p.a<q.a)return true;
	return false;
}


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll n,k;
		cin>>n>>k;
		vector<cards> vec(n);
		ll tot = 0;
		foi(n)
		{
			cin>>vec[i].a;
		}
		foi(n)
		{
			cin>>vec[i].d;
			tot+=vec[i].d;
		}
		sort(vec.begin(),vec.end(),comp);
		vll b(k),bd(k);
		foi(k)cin>>b[i];
		bd[0]=tot-b[0];
		foi1(k-1)
		{
			bd[i]=b[i-1]-b[i];
		}
		ll finlef = b[k-1];
		ll lef_removed = 0;
		for(int i=0;i<k;i+=2)
		{
			lef_removed+=bd[i];
		}
		ll ans = 0;
		for(int i=0;i<n;)
		{
			if(lef_removed<=0)
			{
				if(finlef<=0)
				{
					break;
				}
				else
				{
					if(finlef>=vec[i].d)
					{
						finlef-=vec[i].d;
						ans+=(vec[i].d*vec[i].a);
					}
					else
					{
						ans+=(vec[i].a*finlef);
						finlef=0;
					}
				}
			}
			else
			{
				if(vec[i].d<=lef_removed)
				{
					lef_removed-=vec[i].d;
				}
				else
				{
					vec[i].d-=lef_removed;
					lef_removed=0;
					i-=1;
				}
			}
			i+=1;
		}
		cout<<ans<<endl;
		
	}
}
