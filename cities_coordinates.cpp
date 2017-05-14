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
		ll n,x,y;
		ll mxx=-1e10,mnx=1e10,mxy=-1e10,mny=1e10;
		cin>>n;
		foi(n)
		{
			cin>>x>>y;
			mxx=max(x,mxx);
			mnx=min(x,mnx);
			mxy=max(y,mxy);
			mny=min(y,mny);
		}
		ll var = max((mxx-mnx),(mxy-mny));
		cout<<var*var<<endl;
	}
}