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
	ll n;
	cin>>n;
	vll vec(n+1);
	foi(n)
	{
		cin>>vec[i+1];
	}
	vll vec1(n+1),vec2(n+1);
	for(int i=1;i<=n;i++)
	{
		ll ans = 0;
		for(int j=i;j<=n;j++)
		{
			ll var = max(vec1[j-1],vec[j]);
			ans+=var;
			vec2[j]=var;
		}
		vec1=vec2;
		cout<<ans<<endl;
	}

	
}