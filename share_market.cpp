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

int n,k;
vi w(50),x(500),c(500);
umm(int,bool) um;
bool pos(int ps,int itm, int cst)
{
	//cout<<ps<<" "<<itm<<" "<<cst<<endl;
	int var ;
	for(int vr=ps;vr<n;vr++)
	{
		var = vr*1+itm*100+cst*10000;
		if(um.find(var)!=um.end())return um[var];
	}
	var = ps*1+itm*100+cst*10000;
	if(cst==0)return true;
	if(ps>=n)return false;
	if(itm<=0)return false;
	if(cst<0)return false;
	bool ans = pos(ps+1,itm-1,cst-w[ps]);
	if(ans){
		um[var]=ans;
		return ans;
	}
	else ans=pos(ps+1,itm,cst);
	um[var]=ans;
	return ans;
}


int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		um.clear();
		scanf("%d",&n);
		
		foi(n)scanf("%d",&w[i]);
		scanf("%d",&k);
		
		foi(k)scanf("%d",&x[i]);
		foi(k)scanf("%d",&c[i]);
		foi(k)
		{
			//cout<<i<<" I am i"<<endl;
			if(pos(0,x[i],c[i]))printf("Yes\n");
			else printf("No\n");
		}
	}
}