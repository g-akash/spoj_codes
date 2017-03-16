#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <math.h>


using namespace std;


#define ll long long int
#define ull unsigned long long int
#define umm(x,y) unordered_map<x,y >
#define pb push_back
#define foi(n) for(int i=0;i<n;i++)
#define foj(n) for(int j=0;j<n;j++)
#define foi1(n) for(int i=1;i<=n;i++)
#define foj1(n) for(int j=1;j<=n;j++)
#define vi vector<int>
#define vvi vector<vi >
#define si size()
#define MOD 1000000007

class pl{
public:
	ll x,y,r1,r2,mr2;
};

bool comp(pl p, pl q){
	if(p.r1<q.r1)return true;
	if(p.r1==q.r1&&p.r2>q.r2)return true;
	return false;
}

int main()
{
	ll n,x1,y1,x2,y2,x,y;
	cin>>n>>x1>>y1>>x2>>y2;
	vector<pl> v(n);
	foi(n){
		cin>>v[i].x>>v[i].y;
		x=v[i].x;
		y=v[i].y;
		v[i].r1=(x-x1)*(x-x1)+(y-y1)*(y-y1);
		v[i].r2=(x-x2)*(x-x2)+(y-y2)*(y-y2);
	}
	sort(v.begin(),v.end(),comp);
	ll mr=0;
	for(int i=n-1;i>=0;i--)
	{
		mr=max(mr,v[i].r2);
		v[i].mr2=mr;
	}
	ll ans=v[0].mr2;
	foi(n-1)
	{
		ans=min(ans,v[i].r1+v[i+1].mr2);
	}
	ans=min(ans,v[n-1].r1);
	cout<<ans<<endl;
}

