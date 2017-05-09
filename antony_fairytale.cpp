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


int main()
{
	ll n,k;
	cin>>n>>k;
	k=min(n,k);
	ll ans=k;
	ll val=n-k;
	ll x=-1,y=4000000000;
	while(y-x>1)
	{
		ll mid=(x+y)/2;
		if((mid*(mid+1))>=2*val)y=mid;
		else x=mid;
	}
	ans+=y;
	cout<<ans<<endl;

}