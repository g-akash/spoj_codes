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

ll n,m;
vll xx,yy;
vll sx,sy;

void make_sum()
{
	sx.resize(xx.size());
	sy.resize(yy.size());
	sx[0]=xx[0];
	sy[0]=yy[0];
	foi1(xx.size()-1)
	{
		sx[i]=sx[i-1]+xx[i];
		sy[i]=sy[i-1]+yy[i];
	}
	return;
}

ll get_sumxx(int a, int b)
{
	if(a==0)return sx[b];
	return sx[b]-sx[a-1];
}

ll get_sumyy(int a, int b)
{
	if(a==0)return sy[b];
	return sy[b]-sy[a-1];
}

ll get_ans(ll cx, ll cy)
{
	ll ansx=0;
	if(cx<=xx[0])
	{
		ansx = get_sumxx(0,n-1)-n*cx;
	} else if(cx>=xx[n-1]) {
		ansx = n*cx-get_sumxx(0,n-1);
	} else {
		int x=0,y=n-1;
		while(y-x>1)
		{
			int mid = (x+y)/2;
			if(xx[mid]<=cx)x=mid;
			else y = mid;
		}
		ansx = ((x+1)*cx-get_sumxx(0,x))+(get_sumxx(x+1,n-1)-(n-x-1)*cx);
	}



	//----------------
	ll ansy=0;

	if(cy<=yy[0])
	{
		ansy = get_sumyy(0,n-1)-n*cy;
	} else if(cy>=yy[n-1]) {
		ansy = n*cy-get_sumyy(0,n-1);
	} else {
		int x=0,y=n-1;
		while(y-x>1)
		{
			int mid = (x+y)/2;
			if(yy[mid]<=cy)x=mid;
			else y=mid;
		}
		ansy = ((x+1)*cy-get_sumyy(0,x))+(get_sumyy(x+1,n-1)-(n-1-x)*cy);
	}


	//----------
	return ansx+ansy;
}




int main()
{
	
	cin>>n>>m;
	ll x,y;
	
	foi(n)
	{
		cin>>x>>y;
		xx.pb(x);
		yy.pb(y);
	}
	sort(xx.begin(),xx.end());
	sort(yy.begin(),yy.end());
	make_sum();
	ll cx=0,cy=0;
	string path;
	cin>>path;
	foi(m)
	{
		if(path[i]=='D')
		{
			cy-=1;
		} else if(path[i]=='R')
		{
			cx+=1;
		} else if(path[i]=='U')
		{
			cy+=1;
		} else {
			cx-=1;
		}
		cout<<get_ans(cx,cy)<<endl;
	}
}