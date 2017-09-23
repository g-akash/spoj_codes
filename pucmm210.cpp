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
#define DIV 1000000003



int main()
{
	vll terms(1000005),ans(1000005);
	terms[1]=1;
	ans[1]=1;
	for(ll i=2;i<1000005;i++)
	{
		terms[i] = terms[i-1]+i*i*i;
		terms[i] %= DIV;
		ans[i] = ans[i-1]+terms[i];
		ans[i] %= DIV;
	}
	int t,var;
	cin>>t;	
	foi(t)
	{
		cin>>var;
		cout<<ans[var]<<endl;
	}
}