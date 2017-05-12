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
	int n,mm,k,st;
	cin>>n>>mm>>k;
	int ans=0;
	map<int,int> m;
	foi1(mm)
	{
		m[i]=k;
	}
	foi(n)
	{
		cin>>st;
		if(m.find(st)!=m.end())
		{
			m[st]-=1;
			if(m[st]==0)m.erase(st);
		}
		else if(m.begin()==m.end())
		{
			ans++;
		}
		else 
		{
			map<int,int>::iterator it = m.upper_bound(st);
			if(it!=m.end())
			{
				int ver = it->first;
				m[ver]-=1;
				if(m[ver]==0)
				{
					m.erase(ver);
				}
			}
			else
			{
				it = m.upper_bound(-1);
				int ver = it->first;
				m[ver]-=1;
				if(m[ver]==0)
				{
					m.erase(ver);
				}
			}
			ans++;
		}
	}
	cout<<ans<<endl;
}