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

vi tmp,prims;

void make_prims()
{
	tmp[0]=1;
	tmp[1]=1;
	for(int i=2;i<tmp.size();i++)
	{
		if(tmp[i]==1)continue;
		for(int j=2*i;j<tmp.size();j+=i)tmp[j]=1;
	}
	prims.pb(-1);
	for(int i=2;i<tmp.size();i++)
	{
		if(tmp[i]==0)prims.pb(i);
	}
}


int main()
{
	tmp.resize(1000005);
	make_prims();
	prims.pb(1000005);
	vi ans(1000001);
	ans[0]=0;
	ans[1]=0;
	int curr=1;
	for(int i=2;i<ans.size();i++)
	{
		if(i==prims[curr])
		{
			ans[i]=ans[i-1]+1;
			curr++;
		}
		else ans[i]=ans[i-1];
	}
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int a,b,l,r;
		scanf("%d %d",&a,&b);
		l = min(a,b);
		r = max(a,b);
		printf("%d\n",ans[r]-ans[l-1]);//<<endl;
	}
}