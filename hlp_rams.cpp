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
#include <stdio.h>

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



int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		ll var,orig_val;
		scanf("%lld",&var);
		if(var==0)
		{
			cout<<0<<" "<<1<<endl;
			continue;
		}
		orig_val=var;
		ll num_ones=0;
		while(var!=0)
		{
			if(var%2==1)num_ones+=1;
			var/=2;
		}
		ll ans = 1;
		while(num_ones!=0)
		{
			ans*=2;
			num_ones-=1;
		}
		cout<<orig_val+1-ans<<" "<<ans<<endl;
	}
}