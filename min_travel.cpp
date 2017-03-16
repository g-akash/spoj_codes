#include<iostream>
#include<vector>
#include<algorithm>
#include<unistd.h>

using namespace std;

#define ll long long

class node
{
	public:
	ll int num,cost,st;
	node()
	{
		cost=10000000;
		st=0;
	}
};

int main()
{
	vector<vector<ll int> > v,cst;
	v.resize(501);
	cst.resize(501);
	for(ll int i=0;i<=500;i++)cst[i].resize(501);
	for(ll int i=0;i<=500;i++)for(ll int j=0;j<=500;j++)cst[i][j]=10000000;
	ll int n,x,y,r,maxn=-10000;
	cin>>n;
	//cout<<n<<" strt"<<endl;
	for(ll int i=0;i<n;i++)
	{
		cin>>x>>y>>r;
		v[x].push_back(y);
		v[y].push_back(x);
		cst[x][y]=min(r,cst[x][y]);
		cst[y][x]=min(r,cst[y][x]);
		//cout<<x<<" "<<y<<" "<<cst[x][y]<<" cst"<<endl;
		maxn=max(maxn,x);
		maxn=max(maxn,y);
	}
	//for(int i=0;i<v[2].size();i++)cout<<v[2][i]<<" ";cout<<endl;
	vector<node> nods;
	nods.resize(501);
	ll int s;
	cin>>s;
	//cout<<s<<" balle"<<endl;
	nods[s].cost=0;
	for(ll int i=0;i<=500;i++)
	{
		ll int mnc=1000000,mnind=0;
		for(ll int j=0;j<=500;j++)
		{
			if(nods[j].st!=1&&nods[j].cost<mnc){mnc=nods[j].cost;mnind=j;}
		}
		//cout<<mnind<<endl;
		nods[mnind].st=1;
		//cout<<v[2].size()<<" kk "<<v[mnind].size()<<endl;
		for(ll int j=0;j<v[mnind].size();j++)
		{
			//cout<<j<<endl;
			nods[v[mnind][j]].cost=min(nods[v[mnind][j]].cost,nods[mnind].cost+cst[mnind][v[mnind][j]]);
			//cout<<nods[v[mnind][j]].cost<<" oho "<<v[mnind][j]<<" hoh "<<nods[mnind].cost<<endl;
		}
		//for(int i=0;i<10;i++)cout<<nods[i].cost<<" ";cout<<endl;
	}
	ll int q;
	cin>>q;
	for(ll int i=0;i<q;i++)
	{
		//cout<<i<<" "<<q<<endl;
		//sleep(1);
		cin>>x;
		//cout<<x<<endl;
		if(nods[x].cost<=1000000)cout<<nods[x].cost<<endl;
		else cout<<"NO PATH"<<endl;
	}
}
