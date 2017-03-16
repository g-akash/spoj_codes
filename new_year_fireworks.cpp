#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <math.h>
#include <map>
#include <queue>
#include <algorithm>
#include <list>

using namespace std;


#define ll long long int
#define umm(x,y) unordered_map<x,y >
#define pb push_back
#define foi(n) for(int i=0;i<n;i++)
#define foj(n) for(int j=0;j<n;j++)
#define foi1(n) for(int i=1;i<=n;i++)
#define vi vector<int>
#define vvi vector<vi >
#define vll vector<ll>
#define vvll vector<vll >
#define si size()


class blast
{
public:
	ll t,chx,chy;

bool operator ==(blast b)
{
	if(t==b.t&&chx==b.chx&&chy==b.chy)return true;
	return false;
}
};

umm(ll,ll) ps;
umm(ll,ll) bl;

class loc
{
public:
	ll x, y;
	ll chx,chy;

	bool operator==(loc p)
	{
		if(p.x==x&&p.y==y&&p.chx==chx&&p.chy==chy)return true;
		return false;
	}
};

vector<loc> curr,nex;

bool find(loc ans)
{
	
	return false;
}





void transform(loc var, ll t)
{
	blast bb;
	bb.chx=var.chx;
	bb.chy=var.chy;
	bb.t=t;
	
	ll x=var.x+(t-1)*var.chx;
	ll y=var.y+(t-1)*var.chy;
	loc ans;
	ans.chx=var.chx-var.chy;
	ans.chy=var.chx+var.chy;
	if(ans.chx<-1)ans.chx=-1;
	if(ans.chx>1)ans.chx=1;
	if(ans.chy<-1)ans.chy=-1;
	if(ans.chy>1)ans.chy=1;
	ans.x=x+ans.chx;
	ans.y=y+ans.chy;
	ll pos = ans.x*1000000+ans.y*1000+ans.chx*100+ans.chy;
	if(bl.find(pos)==bl.end())
	nex.pb(ans);
	bl[pos]=1;
	ans.chx=var.chx+var.chy;
	ans.chy=-var.chx+var.chy;
	if(ans.chx<-1)ans.chx=-1;
	if(ans.chx>1)ans.chx=1;
	if(ans.chy<-1)ans.chy=-1;
	if(ans.chy>1)ans.chy=1;
	ans.x=x+ans.chx;
	ans.y=y+ans.chy;
	pos = ans.x*1000000+ans.y*1000+ans.chx*100+ans.chy;
	if(bl.find(pos)==bl.end())
	nex.pb(ans);
	bl[pos]=1;
	return;
	
}
int main()
{	
	
	loc var;
	var.x=0;var.y=0;
	var.chx=0;var.chy=1;
	curr.pb(var);
	ll n,t;
	cin>>n;
	foi(n)
	{
		cin>>t;
		bl.clear();
		foj(curr.size())
		{
			for(ll k=0;k<t;k++)
			{
				//cout<<"hello"<<endl;
				ps[(curr[j].x+k*curr[j].chx)*1000000+curr[j].y+k*curr[j].chy]=1;
			}
			transform(curr[j],t);
		}
		curr=nex;
		nex.clear();

	}
	//umm(ll,int)::iterator it=ps.begin();
	//while(it!=ps.end()){cout<<it->first<<endl;it++;}
	cout<<ps.size()<<endl;
}