#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <math.h>
#include <map>
#include <queue>
#include <algorithm>
#include <list>

using namespace std;


#define ll long long int
#define umm(x,y) unordered_map<x,y >
#define pb push_back
#define foi(n) for(int i=0;i<n;i++)
#define foj(n) for(int j=0;j<n;j++)
#define foi1(n) for(int i=1;i<=n;i++)
#define vi vector<int>
#define vvi vector<vi >
#define vll vector<ll>
#define vvll vector<vll >
#define si size()

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,a,b;
		map<int,int> m;
		//cin>>n;
		scanf("%d",&n);
		vector<int> pop(n+1);
		vvi edges(n+1);
		foi1(n)
		{
			//cin>>pop[i];
			scanf("%d",&pop[i]);
			m[pop[i]]=i;
		}
		foi(n-1)
		{
			//cin>>a>>b;
			scanf("%d",&a);
			scanf("%d",&b);
			edges[a].pb(b);
			edges[b].pb(a);
		} 
		foi1(n)
		{
			vector<int> popu,cities;
			popu.pb(pop[i]);
			foj(edges[i].size())
			{
				popu.pb(pop[edges[i][j]]);
			}
			foi(popu.size())
			{
				cities.pb(m[popu[i]]);
				m.erase(popu[i]);
			}
			map<int,int>::iterator it=m.end();
			if(it!=m.begin())
			{
				it--;
				//cout<<it->second<<endl;
				printf("%d\n",it->second);
			}
			foi(popu.size())
			{
				m[popu[i]]=cities[i];
			}
		}
		
	}
}