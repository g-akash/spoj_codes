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
	int n;
	cin>>n;
	vll x(n),y(n);
	foi(n)
	{
		cin>>x[i]>>y[i];
	}
	sort(x.begin(),x.end());
	sort(y.begin(),y.end());
	ll ans=0;
	ll currx=x[0],curry=y[0];
	for(int i=1;i<n;i++)
	{
		ans+=(x[i]*i-currx);
		currx+=x[i];
		ans+=(y[i]*i-curry);
		curry+=y[i];
		ans=ans%(1000000007);
	}
	cout<<ans<<endl;

}