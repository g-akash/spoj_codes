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
#include <set>

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
	int n,q,var,typ;
	scanf("%d %d",&n,&q);
	set<int> s1,s2;
	s2.insert(100000000);
	set<int>::iterator it; 
	foi1(n)
	{
		s1.insert(i);
	}
	foi(q)
	{
		scanf("%d %d",&typ,&var);
		if(typ==1)
		{
			if(s1.find(var)!=s1.end())
			{
				s1.erase(var);
				s2.insert(var);
			}
		}
		else
		{
			
			it = s2.find(var);
			if(it!=s2.end())
			{
				printf("%d\n",*it);
				continue;
			}
			it = s2.upper_bound(var);
			if(*it == 100000000)printf("-1\n");
			else printf("%d\n",*it);//<<endl;
		}
	}
}