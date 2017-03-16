#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>


using namespace std;

class qpos
{
public:
	int x,y;
	int movs;
};
vector<qpos> q;
char** vec;
int t,i,ko,j,kk,c,d;
int m,n;
int x,y,a,b;
bool visited[1000][1000];
bool inqueue[1000][1000];
int main()
{
	
	scanf("%d",&t);
	
	q.resize(10000000);
	
	vec = (char**)(malloc(1001*(sizeof(*vec))));
	for(i=0;i<1000;i++)
	{
		vec[i]=(char*)(malloc(1001*sizeof(**vec)));
	}

	for(ko=0;ko<t;++ko)
	{
		
		//cin>>n>>m;
		scanf("%d",&n);
		scanf("%d",&m);
		
		for(i=0;i<n;i++)
		{
			//cin>>vec[i];
			scanf("%s",vec[i]);
		}
		
		
		for(i=0;i<n;++i)
			for(j=0;j<m;++j)
			{
				visited[i][j]=0;inqueue[i][j]=0;
			}
		

		//queue<qpos> q;
		a=0;b=0;
		qpos que,var;
		bool donei=false;
		for(i=0;i<n&&!donei;++i)
		{
			for(j=0;j<m;++j)
			{
				if(vec[i][j]=='S')
				{
					que.y=j;que.x=i;que.movs=0;
					q[b]=que;
					b++;
					donei=true;
					break;
				}
			}
		}
		donei=false;
		while(a!=b&&!donei)
		{
			que=q[a];
			a++;
			x=que.x;y=que.y;
			if(vec[x][y]=='F'){printf("%d\n",que.movs);donei=true;break;}
			visited[x][y]=1;
			
			
			for(i=x+1;i<n;++i)
			{
				
				//cout<<vec[i].size()<<endl;
				if(vec[i][y]=='X')break;
				//cout<<i<<" hello "<<y<<endl;
				if(visited[i][y]!=1&&inqueue[i][y]!=1){var.x=i;var.y=y;var.movs=que.movs+1;q[b]=var;b++;inqueue[var.x][var.y]=1;}
				if(visited[i][y]==1)break;
			}
			//cout<<que.x<<" "<<que.y<<endl;
			for(i=x-1;i>=0;--i)
			{
				if(vec[i][y]=='X')break;
				if(visited[i][y]!=1&&inqueue[i][y]!=1){var.x=i;var.y=y;var.movs=que.movs+1;q[b]=var;b++;inqueue[var.x][var.y]=1;}
				if(visited[i][y]==1)break;
			}
			for(i=y+1;i<m;++i)
			{
				if(vec[x][i]=='X')break;
				if(visited[x][i]!=1&&inqueue[x][i]!=1){var.x=x;var.y=i;var.movs=que.movs+1;q[b]=var;b++;inqueue[var.x][var.y]=1;}
				if(visited[x][i]==1)break;
			}
			for(i=y-1;i>=0;--i)
			{
				if(vec[x][i]=='X')break;
				if(visited[x][i]!=1&&inqueue[x][i]!=1){var.x=x;var.y=i;var.movs=que.movs+1;q[b]=var;b++;inqueue[var.x][var.y]=1;}
				if(visited[x][i]==1)break;
			}
			if(m<n)kk=m;else kk=n;
			for(i=1;i<kk;++i)
			{
				c=x+i;d=y+i;

				if(c<n&&d<m)
				{
					if(vec[c][d]=='X')break;
					if(visited[c][d]!=1&&inqueue[c][d]!=1)
					{
						var.x=c;var.y=d;var.movs=que.movs+1;q[b]=var;b++;inqueue[c][d]=1;
					}
					if(visited[c][d]==1)break;
				}
				else break;
			}
			for(i=1;i<kk;++i)
			{
				c=x+i;d=y-i;
				if(c<n&&d>=0)
				{
					if(vec[c][d]=='X')break;
					if(visited[c][d]!=1&&inqueue[c][d]!=1)
					{
						var.x=c;var.y=d;var.movs=que.movs+1;q[b]=var;b++;inqueue[c][d]=1;
					}
					if(visited[c][d]==1)break;
				}
				else break;
			}
			for(i=1;i<kk;++i)
			{
				c=x-i;d=y+i;
				if(c>=0&&d<m)
				{
					if(vec[c][d]=='X')break;
					if(visited[c][d]!=1&&inqueue[c][d]!=1)
					{
						var.x=c;var.y=d;var.movs=que.movs+1;q[b]=var;b++;inqueue[c][d]=1;
					}
					if(visited[c][d]==1)break;
				}
				else break;
			}
			for(i=1;i<kk;++i)
			{
				c=x-i;d=y-i;
				if(c>=0&&d>=0)
				{
					if(vec[c][d]=='X')break;
					if(visited[c][d]!=1&&inqueue[c][d]!=1)
					{
						var.x=c;var.y=d;var.movs=que.movs+1;q[b]=var;b++;inqueue[c][d]=1;
					}
					if(visited[c][d]==1)break;
				}
				else break;
			}

		}
		if(!donei)printf("-1\n");

	}
}