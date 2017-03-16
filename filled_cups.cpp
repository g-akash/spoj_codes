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
	int n,k,var=0,ans=0;
	cin>>n;
	foi(n)
	{
		cin>>k;
		if(k==1)var++;
	}
	if(n>1)
	{
		if(var<n)
		{
			if(var%2==0)
			{
				ans=var/2+1;
			}
			else
			{
				ans=var/2+2;
			}
			if(ans%2==0)cout<<ans/2<<endl;
			else cout<<ans/2+1<<endl;
		}
		else
		{
			if(var%2==0)
			{
				ans=var/2+1;
				if(ans%2==0)cout<<ans/2<<endl;
				else cout<<ans/2+1<<endl;
			}
			else
			{
				ans=var/2+2;
				if(ans%2==0)cout<<ans/2<<endl;
				else cout<<ans/2+1<<endl;
			}
		}
	}
	else
	{
		cout<<1<<endl;
	}
}