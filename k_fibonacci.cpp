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
	vll vec(1000000);
	ll x,y;
	cin>>x>>y;
	foi(y+1)
	{
		vec[i]=(ll)1;
	}
	ll curr = y;
	int pos = 1;
	for(int i=y+1;i<=x;i++)
	{
		vec[i]=curr;
		curr+=vec[i];
		curr-=vec[pos];
		curr = curr%1000000007;
		pos+=1;
	}
	cout<<vec[x]<<endl;
}