#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int n,e,t,m;
	cin>>n>>e>>t>>m;
	vector<vector<int> > v;
	v.resize(n+1);
	for(int i=1;i<=n;i++)v[i].resize(n+1);
	int a,b,c;
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)v[i][j]=-1;
	for(int i=1;i<=m;i++)
	{
		cin>>a>>b>>c;
		v[b][a]=c;

	}

	vector<int> done;
	done.resize(n+1);
	vector<int> currc;
	currc.resize(n+1);
	for(int i=1;i<=n;i++)currc[i]=1000000000;
	currc[e]=0;
	int currn=e;
	done[currn]=1;
	bool vll=true;
	int currmin;
	while(vll)
	{
		vll=false;
		//cout<<currn<<endl;
		done[currn]=1;
		for(int i=1;i<=n;i++)if(v[currn][i]>=0&&currc[i]>currc[currn]+v[currn][i]){currc[i]=currc[currn]+v[currn][i];}
		 currmin=1000000000;
		for(int i=1;i<=n;i++)
		{
			if(done[i]==0&&currc[i]<currmin){vll=true;currn=i;currmin=currc[i];}
		}
		
	}
	int count=0;
	for(int i=1;i<=n;i++){if(currc[i]<=t)count++;}
		cout<<count<<endl;



}