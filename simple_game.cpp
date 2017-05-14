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
	int n,m;
	cin>>n>>m;
	vll a(n+2),b(m+2);
	a[0]=-1;a[n+1]=1e11;
	b[0]=-1;b[m+1]=1e11;
	foi1(n)cin>>a[i];
	foi1(m)cin>>b[i];
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	ll score1=0,score2=0;
	foi1(n)
	{
		ll lef,rig,x,y;
		x=0;y=m+1;
		while(y-x>1)
		{
			ll mid=(x+y)/2;
			if(b[mid]>a[i])y=mid;
			else x=mid;
		}
		rig = m-y+1;
		x=0;y=m+1;
		while(y-x>1)
		{
			ll mid=(x+y)/2;
			if(b[mid]>=a[i])y=mid;
			else x=mid;
		}
		lef = x;
		score1+=(lef*rig);
	}
	foi1(m)
	{
		ll lef,rig,x,y;
		x=0;y=n+1;
		while(y-x>1)
		{
			ll mid=(x+y)/2;
			if(a[mid]>b[i])y=mid;
			else x=mid;
		}
		rig = n-y+1;
		x=0;y=n+1;
		while(y-x>1)
		{
			ll mid=(x+y)/2;
			if(a[mid]>=b[i])y=mid;
			else x=mid;
		}
		lef = x;
		score2+=(lef*rig);
	}
	//cout<<score1<<" "<<score2<<endl;
	if(score1>score2)cout<<"Monk "<<score1-score2<<endl;
	else if(score2>score1)cout<<"!Monk "<<score2-score1<<endl;
	else cout<<"Tie"<<endl;
}