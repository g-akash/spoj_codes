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
#define REM 1000000007

ll gcd(ll a, ll b)
{
	if(a%b==0)return b;
	return gcd(b,a%b);
}

ll getpw(ll a, ll b)
{
	vector<ll> vec(70);
	vec[0]=a%REM;;
	foi1(69)
	{
		vec[i]=vec[i-1]*vec[i-1];
		vec[i]%=REM;
	}
	ll ans=1,curr=0;
	while(b>0)
	{
		if(b%2==1)ans*=vec[curr];
		b/=2;
		curr++;
		ans%=REM;
	}
	return ans;
}

int main()
{
	int t;
	//cout<<getpw(2,10)<<endl;
	cin>>t;
	while(t--){
		ll w,m,a,gd,ans;
		cin>>w>>m>>a;
		gd=gcd(w,m);
		ans=getpw(a+1,gd);
		ans--;
		if(ans<0)ans+=1000000007;
		cout<<ans<<endl;
	}
}