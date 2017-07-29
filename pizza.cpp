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
	int n;
	cin>>n;
	int a=0,b=0,c=0,d=0;
	d=1;
	string str;
	foi(n)
	{
		cin>>str;
		if(str=="1/4")a++;
		else if(str=="1/2"||str=="2/4")b++;
		else c++;
	}
	int ans=0;
	if(c>=a)
	{
		ans+=c;
		c=0;
		a=0;
	}
	else
	{
		ans+=c;
		a-=c;
		c=0;
		ans+=(a/4);
		a%=4;
	}
	ans+=d;
	ans+=(b/2);
	b%=2;
	if(b==0)
	{
		if(a!=0)ans++;

	}
	else if(b!=0)
	{
		if(a<=2)ans++;
		else ans+=2;
	}
	cout<<ans<<endl;
}