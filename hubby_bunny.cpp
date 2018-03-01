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
		ll a,b,c,d,e,f;
		cin>>a>>b>>c>>d>>e>>f;
		ll r = c+f;
		ll dist = (d-a)*(d-a)+(e-b)*(e-b);
		if(r*r>dist)
		{
			cout<<"overlapping"<<endl;
		}
		else if(r*r<dist)
		{
			cout<<"not overlapping"<<endl;
		}
		else
		{
			cout<<"tangential"<<endl;
		}
	}
}