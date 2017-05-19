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
#define foi(n) for(int i=0;i<n;++i)
#define foj(n) for(int j=0;j<n;++j)
#define foi1(n) for(int i=1;i<=n;++i)
#define foj1(n) for(int j=1;j<=n;++j)
#define vi vector<int>
#define vb vector<bool>
#define vvi vector<vi >
#define vvb vector<vb >
#define vll vector<ll>
#define vvll vector<vll >
#define si size()

int k;

class node
{
public:
	int val;
	vector<int> child;
};

vector<node> vec;
vector<int> visited;
vector<int> nex(1);
vector<int> start;
vll nans;


int main()
{
	int n,var;
	scanf("%d %d",&n,&k);
	vec.resize(n+1);
	nans.resize(n+1);
	start.resize(n+1);
	visited.resize(n+1);
	foi1(n)
	{
		scanf("%d",&vec[i].val);
	}
	foi1(n-1)
	{
		scanf("%d",&var);
		vec[var].child.pb(i+1);
	}
	
	nex[0]=0;
	stack<int> st;
	st.push(1);
	while(!st.empty())
	{
		int x=st.top();
		bool done = true;
		
		for(int i=0;i<vec[x].child.size();i++)
		{
			if(!visited[vec[x].child[i]])
			{
				st.push(vec[x].child[i]);
				done=false;
			}
		}
		if(start[x]==0)start[x]=nex.size();
		if(done)
		{
			//cout<<"here"<<endl;
			st.pop();
			
			visited[x]=1;
			for(int i=start[x];i<nex.size();++i)
			{
				nex[i]=nex[i]^vec[x].val;
				if(nex[i]==k)++nex[0];
			}
			nex.pb(vec[x].val);
			if(vec[x].val==k)++nex[0];
			//nex[0]+=currans;
		}
		else
		{
			continue;
		}

	}
	printf("%d\n",nex[0]);//<<endl;
}