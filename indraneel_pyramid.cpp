#include <iostream>
#include <vector>
//#include <unordered_map>
#include <string>
#include <math.h>
//#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <list>
#include <stdio.h>

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


class sq
{
public:
	int a,b;

};

bool comp(sq p, sq q)
{
	if(p.b>q.b)return true;
	return false;

}

int main()
{
	int n,a,b;
	scanf("%d",&n);
	vector<sq> vec(n);
	foi(n)
	{
		scanf("%d %d",&a, &b);
		vec[i].a=max(a,b);
		vec[i].b=min(a,b);
	}
	sort(vec.begin(),vec.end(),comp);
	int ans=0,currh=vec[0].b;
	foi(n)
	{
		if(currh>0)
		{
			if(vec[i].b>0)
			{
				ans++;
				if(vec[i].b<currh)
				{
					currh=vec[i].b-1;
				}
				else currh--;
				
			}
		}
		continue;
	}
	cout<<ans<<endl;

}