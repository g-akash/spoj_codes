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
	ll n,m;
	cin>>n>>m;
	vector<ll> vec(n);
	foi(n)
	{
		cin>>vec[i];
	}
	ll str=-1,end=0,currsum=0,ans=0;
	for(end=0;end<n;end++)
	{
		currsum+=vec[end];
		if(currsum<=m)ans+=(end-str);
		else
		{
			while(currsum>m)
			{
				str++;
				currsum-=vec[str];
			}
			ans+=(end-str);
		}
	}
	cout<<double(ans)/double(double(n*(n+1))/2.0)<<endl;
}