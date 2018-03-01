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

int n,m;
vvi cells,visited,ans;

class node
{
public:
	int x, y;
	int lef;

	node()
	{

	}
	node(int a, int b, int c)
	{
		x=a;
		y=b;
		lef=c;
	}
};



int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		cells.resize(n);
		visited.resize(n);
		ans.resize(n);
		foi(n)
		{
			cells[i].resize(m);
			visited[i].resize(m);
			ans[i].resize(m);
		}
		queue<node> q;
		foi(n)
		{
			foj(m)
			{
				cin>>cells[i][j];
				ans[i][j]=0;
				visited[i][j]=0;
				if(cells[i][j]==-1){visited[i][j]=1;ans[i][j]=-2;}
				else if(cells[i][j]>0)
				{
					node nod(i,j,cells[i][j]);
					q.push(nod);
				}
			}
		}


		// do the work here
		while(!q.empty())
		{
			node nod = q.front();
			q.pop();
			if(visited[nod.x][nod.y])continue;
			visited[nod.x][nod.y]=1;
			int x = nod.x;
			int y = nod.y;
			ans[x][y]=1;
			int nex_step = nod.lef-1;
			if(nex_step>=0)
			{
				if(x-1>=0)
				{
					if(!visited[x-1][y])
					{
						node nnod(x-1,y,nex_step);
						q.push(nnod);
					}
				}
				if(y+1<m)
				{
					if(!visited[x][y+1])
					{
						node nnod(x,y+1,nex_step);
						q.push(nnod);
					}
				}
				if(y-1>=0)
				{
					if(!visited[x][y-1])
					{
						node nnod(x,y-1,nex_step);
						q.push(nnod);
					}
				}
				if(x+1<n)
				{
					if(!visited[x+1][y])
					{
						node nnod(x+1,y,nex_step);
						q.push(nnod);
					}
				}
			}
		}



		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				if(ans[i][j]==-2)cout<<'B';
				else if(ans[i][j]==1)cout<<'Y';
				else cout<<'N';
			}
			cout<<endl;
		}

	}
}