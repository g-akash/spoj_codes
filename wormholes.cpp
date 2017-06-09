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
	int n,x,y;
	cin>>n>>x>>y;
	vi strt(n),ed(n),v(x+1),w(y+1);
	//strt[0]=-1000000000;
	foi(n)cin>>strt[i]>>ed[i];
	//ed[y]=1000000000;
	v[0]=-1000000000;
	foi(x)cin>>v[i+1];
	w[y]=1000000000;
	foi(y)cin>>w[i];
	sort(v.begin(),v.end());
	sort(w.begin(),w.end());
	int ans=100000000;
	foi(n)
	{
		int a=0,b=x;
		while(b-a>1)
		{
			int mid = (a+b)/2;
			if(v[mid]>strt[i])b=mid;
			else a=mid;
		}
		int c=0,d=y;
		while(d-c>1)
		{
			int mid = (c+d)/2;
			if(w[mid]<ed[i])c=mid;
			else d=mid;
		}
		if(w[d]-v[a]+1<ans)ans=w[d]-v[a]+1;

	}
	cout<<ans<<endl;
}