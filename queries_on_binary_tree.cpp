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


vll p2;

void make_powers()
{
	p2.pb((ll)1);
	foi1(50)
	{
		p2.pb(p2[i-1]*(ll)2);
	}
	return;

}

void change_max(ll &u, ll &v)
{
	if(v>=u)return;
	ll tmp = u;
	u=v;
	v=tmp;
	return;
}


ll get_ances_ans(ll u, ll v, ll &lv)
{
	vll v1,v2;
	while(u>0)
	{
		v1.pb(u);
		u/=2;
	}
	while(v>0)
	{
		v2.pb(v);
		v/=2;
	}
	int i,j;
	for(i=(int)v1.size()-1,j=(int)v2.size()-1;i>=0&&j>=0;i--,j--)
	{
		if(v1[i]!=v2[j])
		{
			i++;
			j++;
			break;
		}
	}
	while(i<0||j<0){i+=1;j+=1;}
	
	lv = j;
	//cout<<"ances "<<vl<<" "<<v2[j]<<endl;
	ll ans = 0;
	return v2[j];
}


int main()
{

	make_powers();
	int q;
	cin>>q;
	while(q--)
	{
		ll u,v,n;
		cin>>n>>u>>v;
		change_max(u,v);
		ll ans = 0;
		ll lv;
		ll ances = get_ances_ans(u,v,lv);
		//cout<<lv<<endl;
		ll cnt = 0;
		while(lv>0)
		{
			if(n%2==0&&v%2==1)
			{
				cnt=-1;
			}
			else if(n%2==1&&v%2==0)cnt=0;
			n/=2;
			v/=2;
			lv-=1;
		}
		cout<<n+cnt<<endl;
	

	}
}