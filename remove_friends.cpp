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
		list<int> l;
		int n,k,var;
		cin>>n>>k;
		foi(n)
		{
			cin>>var;
			l.push_back(var);
		}
		list<int>::iterator it=l.begin(),tmp;
		int removed = 0;
		while(it!=l.end()&&removed<k)
		{
			tmp = ++it;
			it--;
			if(*it<*tmp)
			{
				l.erase(it);
				removed++;
				if(it!=l.begin())it--;
			}
			else
			{
				it++;
			}
		}
		if(removed<k)
		{
			it = l.end();
			it--;
			while(removed<k)
			{
				l.erase(it);
				it=l.end();
				it--;
				removed++;
			}
		}
		it = l.begin();
		while(it!=l.end())
		{
			cout<<*it<<" ";it++;
		}
		cout<<endl;
	}
}