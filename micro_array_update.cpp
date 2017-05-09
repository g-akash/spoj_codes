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
	int t;
	cin>>t;
	while(t--)
	{
		int n,k,var,ans=100000000;
		cin>>n>>k;
		foi(n)
		{
			cin>>var;
			ans=min(ans,var);
		}
		//cout<<ans<<" "<<k<<endl;
		if(ans<=k)
		{
			cout<<k-ans<<endl;
		}
		else cout<<0<<endl;
	}
}