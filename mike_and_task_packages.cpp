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


class pack
{
public:
	ll hf,fl;
	bool hlfdone;
	pack(ll hfl = 0, ll fll = 0)
	{
		hf=hfl;
		fl=fll;
		hlfdone = false;
	}
};

bool comp_hlf(pack p, pack q)
{
	if(p.hf<q.hf)return true;
	if(p.hf==q.hf&&p.fl<q.fl)return true;
	return false;
}

bool comp_fll(pack p, pack q)
{
	if(p.hlfdone==true&&q.hlfdone==false)return true;
	if(p.hlfdone==false&&q.hlfdone==true)return false;
	if(p.fl<q.fl)return true;
	return false;
}


int main()
{
	ll n,x;
	cin>>n>>x;
	ll var;
	vector<ll> vec(n);
	foi(n)
	{
		cin>>vec[i];
	}
	sort(vec.begin(),vec.end());
	ll hdone = 0, fdone = 0;
	foi(n)
	{
		ll val = 0;
		if(vec[i]%2==0)
		{
			val = vec[i]/2;
		}
		else
			val = vec[i]/2 +1;
		if(x>=val)
		{
			x-=val;
			hdone+=1;
		}
		else break;
	}
	foi(hdone)
	{
		ll val = vec[i]/2;
		if(x>=val)
		{
			fdone+=1;
			x-=val;
		}
	}
	cout<<n-hdone<<" "<<fdone<<endl;

}