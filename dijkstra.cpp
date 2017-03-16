#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class node
{
	public:
	int num,fin_cost,st;
	node()
	{
		st=0;
		fin_cost=1000000000;
	}
};


int main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		int n,m,s;
		cin>>n;
		vector<vector<int> > v,cst;
		v.resize(n+1);
		cst.resize(n+1);
		for(int j=1;j<=n;j++)cst[j].resize(n+1);
		for(int j=1;j<=n;j++)for(int k=1;k<=n;k++)cst[j][k]=1000000000;
		cin>>m;
		int x,y,r;
		for(int j=0;j<m;j++)
		{
			cin>>x>>y>>r;
			cst[x][y]=min(r,cst[x][y]);
			cst[y][x]=min(r,cst[x][y]);
			v[x].push_back(y);
			v[y].push_back(x);
		}
		//cout<<"okay"<<endl;
		cin>>s;
		vector<node> nods;
		nods.resize(n+1);
		nods[s].fin_cost=0;
		for(int j=1;j<=n;j++)
		{
			//cout<<"hello"<<endl;
			int mnc=1000000000,mnind=0;
			for(int k=1;k<=n;k++)
			{
				if(nods[k].st!=1&&nods[k].fin_cost<mnc){mnc=nods[k].fin_cost;mnind=k;}
			}
			//cout<<mnind<<endl;
			nods[mnind].st=1;
			for(int k=0;k<v[mnind].size();k++){nods[v[mnind][k]].fin_cost=min(nods[v[mnind][k]].fin_cost,nods[mnind].fin_cost+cst[mnind][v[mnind][k]]);}
		}
		for(int j=1;j<=n;j++)if(j!=s)if(nods[j].fin_cost!=1000000000)cout<<nods[j].fin_cost<<" ";else cout<<-1<<" ";
		cout<<endl;
	}
}
