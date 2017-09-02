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
#include <stdio.h>

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
int bord[1000][1000];
char board[1000][1000];
int x,y;


int main()
{
	int t;
	char ch;
	scanf("%d",&t);
	while(t--)
	{
		
		scanf("%d %d",&n,&m);
		int sx,sy,fx,fy;
		foi(n)
		{
			scanf("%s",board[i]);
			foj(m)
			{
				bord[i][j]=100000000;
				if(board[i][j]=='S')
				{
					sx=i;
					sy=j;
				}
				else if(board[i][j]=='F')
				{
					fx=i;
					fy=j;
				}
			}
		}
		//cout<<sx<<" "<<sy<<" "<<fx<<" "<<fy<<" start and end"<<endl;
		bord[sx][sy]=0;
		queue<int> qx,qy;
		qx.push(sx);
		qy.push(sy);
		bool done=false;
		while(!qx.empty()&&!done)
		{
			
			x = qx.front();
			y = qy.front();
			qx.pop();
			qy.pop();
			int val = bord[x][y];
			if(x==fx&&y==fy)
			{
				printf("%d\n",bord[fx][fy]);
				done=true;
				break;
			}
			for(int i=1;i<n-x&&board[x+i][y]!='X';i++)
			{
				if(x+i==fx&&y==fy)
				{
					printf("%d\n",min(val+1,bord[fx][fy]));
					done = true;
					break;
				}
				if(bord[x+i][y]>val+1)
				{
					bord[x+i][y]=val+1;
					qx.push(x+i);
					qy.push(y);
				}
			}
			if(done) break;
			for(int i=1;i<=x&&board[x-i][y]!='X';i++)
			{
				if(x-i==fx&&y==fy)
				{
					printf("%d\n",min(val+1,bord[fx][fy]));
					done = true;
					break;
				}
				if(bord[x-i][y]>val+1)
				{
					bord[x-i][y]=val+1;
					qx.push(x-i);
					qy.push(y);
				}
			}


			if(done) break;

			for(int i=1;i<m-y&&board[x][y+i]!='X';i++)
			{
				if(x==fx&&y+i==fy)
				{
					printf("%d\n",min(val+1,bord[fx][fy]));
					done = true;
					break;
				}
				if(bord[x][y+i]>val+1)
				{
					bord[x][y+i]=val+1;
					qx.push(x);
					qy.push(y+i);
				}
			}
			if(done) break;

			for(int i=1;i<=y&&board[x][y-i]!='X';i++)
			{
				if(x==fx&&y-i==fy)
				{
					printf("%d\n",min(val+1,bord[fx][fy]));
					done = true;
					break;
				}
				if(bord[x][y-i]>val+1)
				{
					bord[x][y-i]=val+1;
					qx.push(x);
					qy.push(y-i);
				}
			}
			if(done) break;

			for(int i=1;i<n-x&&i<m-y&&board[x+i][y+i]!='X';i++)
			{
				if(x+i==fx&&y+i==fy)
				{
					printf("%d\n",min(val+1,bord[fx][fy]));
					done = true;
					break;
				}
				if(bord[x+i][y+i]>val+1)
				{
					bord[x+i][y+i]=val+1;
					qx.push(x+i);
					qy.push(y+i);
				}
			}
			if(done) break;

			for(int i=1;i<=x&&i<=y&&board[x-i][y-i]!='X';i++)
			{
				if(x-i==fx&&y-i==fy)
				{
					printf("%d\n",min(val+1,bord[fx][fy]));
					done = true;
					break;
				}
				if(bord[x-i][y-i]>val+1)
				{
					bord[x-i][y-i]=val+1;
					qx.push(x-i);
					qy.push(y-i);
				}
			}
			if(done) break;

			for(int i=1;i<=x&&i<m-y&&board[x-i][y+i]!='X';i++)
			{
				if(x-i==fx&&y+i==fy)
				{
					printf("%d\n",min(val+1,bord[fx][fy]));
					done = true;
					break;
				}
				if(bord[x-i][y+i]>val+1)
				{
					bord[x-i][y+i]=val+1;
					qx.push(x-i);
					qy.push(y+i);
				}
			}
			if(done) break;

			for(int i=1;i<n-x&&i<=y&&board[x+i][y-i]!='X';i++)
			{
				if(x+i==fx&&y-i==fy)
				{
					printf("%d\n",min(val+1,bord[fx][fy]));
					done = true;
					break;
				}
				if(bord[x+i][y-i]>val+1)
				{
					bord[x+i][y-i]=val+1;
					qx.push(x+i);
					qy.push(y-i);
				}
			}
			if(done) break;


		}

		if(!done)printf("-1\n");
		//else printf("%d\n",bord[fx][fy]);


	}
}