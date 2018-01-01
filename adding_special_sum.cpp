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

vi sums;
int n;

int get_sum(int a, int b)
{
	if(a==0)return sums[b];
	return sums[b]-sums[a-1];
}

ll get_sum(vector<ll> vec)
{
	ll n = (ll)(vec.size());
	sort(vec.begin(),vec.end());
	sums.resize(vec.size());
	sums[0]=vec[0];
	for(int i=1;i<vec.size();i++)
	{
		sums[i]=sums[i-1]+vec[i];
	}
	ll ans = 0;
	for(ll i=0;i<n;i++)
	{
		if(i==0)
		{
			ans-=(ll)2*(n-(ll)1-i)*vec[i];
		}
		else if(i==n-1)
		{
			ans+=(ll)2*(i)*vec[i];
		}
		else 
		{
			ans+=(ll)2*((i)*vec[i]-(n-i-(ll)1)*vec[i]);
		}
	}
	return ans;

}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n;
		vll vec(n);
		foi(n)cin>>vec[i];
		vll vec1;
		foi(n)
		{
			for(int j=i+1;j<n;j++)vec1.pb(vec[i]+vec[j]);
		}
	// cout<<vec1.size()<<endl;
	// cout<<get_sum(vec)<<endl;
	// cout<<get_sum(vec1)<<endl;
	cout<<get_sum(vec1)-(n-2)*get_sum(vec)<<endl;
	}
}