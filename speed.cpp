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




ll gcd(int a, int b)
{
	if(a%b==0)return b;
	return gcd(b,a%b);
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll a,b;
		cin>>a>>b;
		if(a*b<0)
		{
			ll x = abs(a-b);
			ll y = gcd(x,abs(a));
			y = abs(a*x)/y;
			cout<<y/abs(a)<<endl;
		}
		else
		{
			ll x = abs(a-b);
			ll y = gcd(x,abs(a));
			y = abs(a*x)/y;
			cout<<abs(y)/abs(a)<<endl;
		}

	}
}