#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <string>

using namespace std;

int main()
{
	int n,m;
	cin>>n>>m;
	char fld[n][m];
	string str;
	for(int i=0;i<n;i++)
	{
		cin>>str;
		for(int j=0;j<m;j++)
		{
			//cin>>fld[i][j];
			fld[i][j]=str[j];
		}
	}
	int vist[n][m];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)vist[i][j]=0;
	}
	int shep,wolf,fence,x,y,tsh=0,twf=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(fld[i][j]=='#'||vist[i][j]==1)continue;
			shep=0;
			wolf=0;
			fence=0;
			stack<int> s;
			s.push(j);
			s.push(i);
			while(!s.empty())
			{

				x=s.top();
				s.pop();
				y=s.top();
				s.pop();
				//if(x==1&&y==5)
				//cout<<x<<" "<<y<<endl;
				if(vist[x][y])continue;
				vist[x][y]=1;
				if(x==0||x==n-1||y==0||y==m-1)fence=1;
				if(fld[x][y]=='k')shep++;
				else if(fld[x][y]=='v')wolf++;
				//cout<<n<<" kk "<<m<<endl;
				if(x-1>=0&&x-1<n&&y>=0&&y<m){if(vist[x-1][y]==0&&fld[x-1][y]!='#'){s.push(y);s.push(x-1);}}
				if(x+1>=0&&x+1<n&&y>=0&&y<m){if(vist[x+1][y]==0&&fld[x+1][y]!='#'){s.push(y);s.push(x+1);}}
				if(x>=0&&x<n&&y-1>=0&&y-1<m){if(vist[x][y-1]==0&&fld[x][y-1]!='#'){s.push(y-1);s.push(x);}}
				if(x>=0&&x<n&&y+1>=0&&y+1<m){if(vist[x][y+1]==0&&fld[x][y+1]!='#'){s.push(y+1);s.push(x);}}
			}
			//cout<<i<<" "<<j<<endl;
			//cout<<fence<<" "<<shep<<" "<<wolf<<endl;
			if(fence){tsh+=shep;twf+=wolf;}
			else if(shep>wolf)tsh+=shep;
			else twf+=wolf;

		}
	}
	cout<<tsh<<" "<<twf<<endl;
}