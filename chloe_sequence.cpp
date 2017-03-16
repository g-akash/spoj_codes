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
	ll n,k,var=1;
	cin>>n>>k;
	foi(n)var*=2;
	var-=1;
	int ans=0;
	while(var/2+1!=k)
	{
		//cout<<var<<" "<<k<<endl;
		if(var/2+1<k)
		{
			var/=2;
			k-=var;
			k-=1;
		}
		else
			var/=2;
		ans++;
	}
	cout<<n-ans<<endl;
}