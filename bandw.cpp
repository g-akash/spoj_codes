#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>

using namespace std;

vector<vector<int> > dist;
vector<vector<int> > queued;
vector<string> vec;
int m,n;

class point
{
public:
	int x,y;
};


int main()
{
	int t,x,y;
	cin>>t;
	for(int ko=0;ko<t;ko++)
	{
		
		cin>>m>>n;
		queue<point> q;
		dist.resize(m);
		queued.resize(m);
		vec.resize(m);
		point p,temp;
		for(int i=0;i<m;i++)cin>>vec[i];
		for(int i=0;i<m;i++)
		{
			dist[i].resize(n);
			queued[i].resize(n);
			for(int j=0;j<n;j++)
			{
				dist[i][j]=1000000;
				queued[i][j]=0;
				if(vec[i][j]=='1'){p.x=i;p.y=j;q.push(p);queued[i][j]=1;dist[i][j]=0;}
			}
		}
		while(!q.empty())
		{
			p=q.front();
			q.pop();
			x=p.x;
			y=p.y;
			if(x-1>=0&&dist[x-1][y]>dist[x][y]+1)
			{
				temp.x=x-1;temp.y=y;dist[x-1][y]=dist[x][y]+1;
				if(!queued[x-1][y]){q.push(temp);queued[x-1][y]=1;}
			}
			if(x+1<m&&dist[x+1][y]>dist[x][y]+1)
			{
				temp.x=x+1;temp.y=y;dist[x+1][y]=dist[x][y]+1;
				if(!queued[x+1][y]){q.push(temp);queued[x+1][y]=1;}
			}
			if(y-1>=0&&dist[x][y-1]>dist[x][y]+1)
			{
				temp.x=x;temp.y=y-1;dist[x][y-1]=dist[x][y]+1;
				if(!queued[x][y-1]){q.push(temp);queued[x][y-1]=1;}
			}
			if(y+1<n&&dist[x][y+1]>dist[x][y]+1)
			{
				temp.x=x;temp.y=y+1;dist[x][y+1]=dist[x][y]+1;
				if(!queued[x][y+1]){q.push(temp);queued[x][y+1]=1;}
			}

			queued[x][y]=0;
		}
		for(int i=0;i<m;i++)
		{
			for(int j=0;j<n;j++)cout<<dist[i][j]<<" ";cout<<endl;
		}

	}
}