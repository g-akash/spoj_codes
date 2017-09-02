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
	int t;
	cin>>t;
	while(t--)
	{
		int n,var,mx=0,ans=1000000001,mn=0;
		cin>>n;
		vi vec(n),lsum(n),rsum(n);
		foi(n)
		{
			cin>>vec[i];
//			vec.pb(var);
		}
		lsum[0]=vec[0];
		foi1(n-1)
		{
			lsum[i]=lsum[i-1]+vec[i];
		}
		rsum[n-1]=vec[n-1];
		for(int i=n-2;i>=0;i--)
		{
			rsum[i]=rsum[i+1]+vec[i];
		}
		ans=min(rsum[1],lsum[n-2]);
		for(int i=1;i<n-1;i++)
		{
			mn = min(2*lsum[i-1]+rsum[i+1],lsum[i-1]+2*rsum[i+1]);
			//cout<<ans<<" ans and mn "<<mn<<" val "<<vec[i]<<endl;
			ans = min(mn,ans);
		}
		cout<<ans<<endl;


		//cout<<ans<<endl;
	}
}