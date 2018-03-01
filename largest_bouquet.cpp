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
		vvll vec(3);
		foi(3)vec[i].resize(3);
		foi(3)foj(3)cin>>vec[i][j];
		ll ans = 0;
		ll curr = 0;
		ll cl = 0;
		for(int i=0;i<3;i++)
		{
			curr=0;
			cl=0;
			foj(3){curr+=vec[i][j];cl+=vec[j][i];}
			if(curr>0&&curr%2==0)curr-=1;
			if(cl>0&&cl%2==0)cl-=1;
			ans=max(curr,ans);
			ans=max(cl,ans);
		}
		cout<<ans<<endl;
	}
}