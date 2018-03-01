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


umm(int,int) um;
vi vec;


bool check_cond1l(int a, int b, int c)
{
	int elem = vec[b];
	int lef = vec[a];
	if(c%2==0)
	{
		return elem<lef;
	}
	else return elem>lef;
}

bool check_cond1r(int a, int b, int c)
{
	int elem = vec[a];
	int rig = vec[b];
	if(c%2==0)
	{
		return elem<rig;
	}
	else return elem>rig;
}



int make_great1(int a, int b, int typ)
{
	if(a==b)
	{
		if(a%2==0)
		{
			if(vec[a]<vec[a-1]&&vec[a]<vec[a+1])return 0;
			else return 10000000;
		}
		else
		{
			if(vec[a]>vec[a-1]&&vec[a]>vec[a+1])return 0;
			else return 10000000;
		}
	}
	if(a>b)
	{
		return 0;
	}
	if(um.find(a*10+typ)!=um.end())return um[a*10+typ];
	int lef,rig;
	if(typ==0)
	{
		lef=a-1;
		rig=b+1;
	}
	else
	{
		lef=b+1;
		rig=a-1;
	}
	int ans1=10000000,ans2=10000000;
	if(check_cond1l(lef,a,a)&&check_cond1r(b,rig,b))
	{
		ans1 = make_great1(a+1,b-1,0);
		if(a+1==b)
		{
			if(a%2==0&&!(vec[a]<vec[b]))
			{
				ans1=10000000;
			}
			else if(a%2==1&&!(vec[a]>vec[b]))ans1=10000000;
		}
	}
	if(check_cond1l(lef,b,a)&&check_cond1r(a,rig,b))
	{
		ans2 = make_great1(a+1,b-1,1)+1;
		if(a+1==b)
		{
			if(a%2==0&&!(vec[b]<vec[a]))ans2=10000000;
			else if(a%2==1&&!(vec[b]>vec[a]))ans2=10000000;
		}
		
	}
	um[a*10+typ]=min(ans1,ans2);
	return min(ans1,ans2);
}



bool check_cond2l(int a, int b, int c)
{
	int elem = vec[b];
	int lef = vec[a];
	if(c%2==0)
	{
		return elem>lef;
	}
	else return elem<lef;
}

bool check_cond2r(int a, int b, int c)
{
	int elem = vec[a];
	int rig = vec[b];
	if(c%2==0)
	{
		return elem>rig;
	}
	else return elem<rig;
}


int make_great2(int a, int b, int typ)
{
	if(a==b)
	{
		if(a%2==0)
		{
			if(vec[a]>vec[a-1]&&vec[a]>vec[a+1])return 0;
			else return 10000000;
		}
		else
		{
			if(vec[a]<vec[a-1]&&vec[a]<vec[a+1])return 0;
			else return 10000000;
		}
	}
	if(a>b)
	{
		return 0;
	}
	if(um.find(a*10+typ)!=um.end())return um[a*10+typ];
	int lef,rig;
	if(typ==0)
	{
		lef=a-1;
		rig=b+1;
	}
	else
	{
		lef=b+1;
		rig=a-1;
	}
	int ans1=10000000,ans2=10000000;
	if(check_cond2l(lef,a,a)&&check_cond2r(b,rig,b))
	{
		ans1 = make_great2(a+1,b-1,0);
		if(a+1==b)
		{
			if(a%2==0&&!(vec[a]>vec[b]))
			{
				ans1=10000000;
			}
			else if(a%2==1&&!(vec[a]<vec[b]))ans1=10000000;
		}
	}
	if(check_cond2l(lef,b,a)&&check_cond2r(a,rig,b))
	{
		ans2 = make_great2(a+1,b-1,1)+1;
		if(a+1==b)
		{
			if(a%2==0&&!(vec[b]>vec[a]))ans2=10000000;
			else if(a%2==1&&!(vec[b]<vec[a]))ans2=10000000;
		}
	}
	um[a*10+typ]=min(ans1,ans2);
	return min(ans1,ans2);
}


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vec.resize(n+1);
		um.clear();
		foi1(n)cin>>vec[i];
		int ans;
		if(n==1)
		{
			ans=0;
		}
		else if(n==2)
		{
			if(vec[1]!=vec[2])ans=0;
			else ans=10000000;
		}
		else
		{
			int ans1 = min(make_great1(2,n-1,0),make_great1(2,n-1,1)+1);
			um.clear();
			int ans2 = min(make_great2(2,n-1,0),make_great2(2,n-1,1)+1);
			ans = min(ans1,ans2);
		}
		//cout<<ans1<<" "<<ans2<<endl;

		if(ans>n/2+5)
		{
			cout<<-1<<endl;
		}
		else cout<<ans<<endl;

	}
}