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
#define foi(n) for(ll i=0;i<n;i++)
#define foj(n) for(ll j=0;j<n;j++)
#define foi1(n) for(ll i=1;i<=n;i++)
#define vi vector<int>
#define vvi vector<vi >
#define vll vector<ll>
#define vvll vector<vll >
#define si size()


vector<int> vec,var;
umm(ll,int) um;
int n,k;


int maxi(int x, int y)
{

	if(x<y)return 0;
	ll ver=(ll)x*1000000000+(ll)y;
	if(um.find(ver)!=um.end())return um[ver];
	vi mv(23);
	int pw,lb;
	foi(23)
	{
		mv[i]=vec[i]*y;
		if(mv[i]>x)
		{
			lb=mv[i-1];
			pw=i-1;
			break;
		}
	}
	if(x<mv[1])return 1;
	ll add=(y-1)*(vec[pw]);
	//cout<<x<<endl;
	x-=lb;
	x-=add;
	
	if(x>=0)
	{
		um[ver]=vec[pw]+x;
		return vec[pw]+x;
	}
	else 
	{	
		um[ver]=vec[pw];
		return vec[pw];
	}

	
}
bool poss(ll x)
{
	int i=0,num=0;
	while(i<var.size())
	{
		int ansi=maxi(var[i],x);
		num+=ansi;
		if(num>=k)return true;
		i++;
	}
	
	return false;
}

int main()
{
	
	cin>>n>>k;
	var.resize(n);
	vec.resize(23);
	vec[0]=1;
	foi1(22)vec[i]=2*vec[i-1];
	foi(n)
	{
		scanf("%d",&var[i]);
	}
	sort(var.begin(),var.end());
	
	int x=0,y=var[var.size()-1]+1;
	while(y-x>1)
	{
		int mid=(x+y)/2;
		if(poss(mid))x=mid;
		else y=mid;
		
	}
	if(x==0)printf("-1\n");
	else printf("%d\n",x);
}