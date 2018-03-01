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


class buc
{
public:
	ll pos;
	char typ;
};

bool comp(buc p, buc q)
{
	if(p.pos<q.pos)return true;
	return false;
}


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll n,m;
		cin>>n>>m;
		vector<buc> vec(m);
		foi(m)
		{
			cin>>vec[i].typ>>vec[i].pos;
		}
		sort(vec.begin(),vec.end(),comp);
		ll ans = 1;
		for(int i=0;i<vec.size()-1;i++)
		{
			if(vec[i].typ!=vec[i+1].typ)
			{
				ans*=(vec[i+1].pos-vec[i].pos);
				ans%=1000000009;
			}
		}
		cout<<ans<<endl;
	}
}