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

class neighbour
{
public:
	int neigh,passen;
};

class node
{
public:
	int parent,cst;
};

int main()
{
	int n,r,a,b,c;
	neighbour ne;
	cin>>n>>r;
	vector<vector<neighbour> > neg(n+1);
	foi(r)
	{
		cin>>a>>b>>c;
		ne.neigh = b;
		ne.passen = c;
		neg[a].pb(ne);
		ne.neigh = a;
		neg[b].pb(ne);
	}
	int s,d,t;
	cin>>s>>d>>t;
	vector<node> curr(n+1);
	
	foi1(n)
	{
		curr[i].parent = i;
		curr[i].cst = -1;

	}
	curr[s].cst = 100000000;
	stack<int> st;
	st.push(s);
	while(!st.empty())
	{
		a=st.top();
		st.pop();
		//cout<<a<<" "<<neg[a].size()<<endl;
		foi(neg[a].size())
		{
			//cout<<neg[a][i].neigh<<endl;
			b = min(curr[a].cst,neg[a][i].passen);
			//cout<<b<<" between "<<curr[neg[a][i].neigh].cst<<endl;
			if(curr[neg[a][i].neigh].cst<b&&neg[a][i].neigh!=s)
			{
				//cout<<"pushing"<<endl;
				st.push(neg[a][i].neigh);
				curr[neg[a][i].neigh].cst = b;
				curr[neg[a][i].neigh].parent = a;
			}
			//cout<<"complete for"<<endl;
		}
	}
	int ans;
	int var = curr[d].cst-1;
	if(t%var==0)ans=t/var;
	else ans = t/var + 1;
	vi path;
	path.pb(d);
	while(path[path.size()-1]!=s)
	{
		path.pb(curr[path[path.size()-1]].parent);
		//cout<<path[path.size()-1]<<" hello"<<endl;
	}
	for(int i=path.size()-1;i>=0;i--)cout<<path[i]<<" ";
		cout<<endl;
	cout<<ans<<endl;
}