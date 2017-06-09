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


int main()
{
	ll n,k,tmp;
	cin>>n>>k;
	vll vec(n+2);
	vec[0]=-1e12;
	foi(n)
	{
		cin>>vec[i];
	}
	vec[n+1]=1e12;
	sort(vec.begin(),vec.end());
	ll ans=0;
	foi1(n)
	{
		int x,y;
		tmp = vec[i]-k;
		x=0,y=n+1;
		while(y-x>1)
		{
			int mid = (x+y)/2;
			if(vec[mid]>tmp)y=mid;
			else x=mid;
		}

		ans+=x;
		// do something

		tmp = vec[i]+k;
		x=0,y=n+1;
		while(y-x>1)
		{
			int mid = (x+y)/2;
			if(vec[mid]>=tmp)y=mid;
			else x=mid;
		}

		// do something;

		ans += (n+1-y);
	}
	cout<<ans/2<<endl;
}