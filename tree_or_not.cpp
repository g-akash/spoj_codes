#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main()
{
	int m,n;
	cin>>m>>n;
	vector<vector<int> > v;
	v.resize(m+1);
	vector<int> visited;
	visited.resize(m+1);
	int a,b,loop=0;
	for(int i=0;i<n;i++)
	{
		cin>>a>>b;
		v[min(a,b)].push_back(max(a,b));
		//v[b].push_back(a);
	}
	
	for(int i=1;i<=m;i++)
	{
		if(visited[i])continue;
		queue<int> q;
		q.push(i);
		for(int j=0;j<=m;j++)visited[j]=0;
		while(!q.empty())
		{
			a=q.front();
			q.pop();
			if(visited[a]==1){loop=1;break;}
			visited[a]=1;
			for(int j=0;j<v[a].size();j++)q.push(v[a][j]);
		}
	}
	if(loop)cout<<"NO"<<endl;
	else cout<<"YES"<<endl;
}