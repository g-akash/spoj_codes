#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>

using namespace std;

class datapoint
{
public:
	int h,w;
	char let;

};
vector<string> grid;
vector<vector<int> > paths;

int longest_path(int b, int a)
{
	if(a<0||b<0||a>=grid.size()||b>=grid[0].length())return 0;
	if(paths[a][b]>=0)return paths[a][b];
		datapoint d,ver;
		ver.h=a;
		ver.w=b;
		int varans=0;
		ver.let=grid[a][b];
		{
			int x=ver.w,y=ver.h;
			if(x-1>=0&&y-1>=0)
			{
				d.w=x-1;d.h=y-1;
				if(int(grid[d.h][d.w])-int(ver.let)==1){varans=max(varans,longest_path(d.w,d.h));}						
			}
			if(x-1>=0)
			{
				d.w=x-1;d.h=y;
				if(int(grid[d.h][d.w])-int(ver.let)==1){varans=max(varans,longest_path(d.w,d.h));}
			}
			if(x-1>=0&&y+1<grid.size())
			{
				d.w=x-1;d.h=y+1;
				if(int(grid[d.h][d.w])-int(ver.let)==1){varans=max(varans,longest_path(d.w,d.h));}
			}
			if(y-1>=0)
			{
				d.w=x;d.h=y-1;
				if(int(grid[d.h][d.w])-int(ver.let)==1){varans=max(varans,longest_path(d.w,d.h));}
			}
			if(y+1<grid.size())
			{
				d.w=x;d.h=y+1;
				if(int(grid[d.h][d.w])-int(ver.let)==1){varans=max(varans,longest_path(d.w,d.h));}
			}
			if(x+1<grid[0].length()&&y-1>=0)
			{
				d.w=x+1;d.h=y-1;
				if(int(grid[d.h][d.w])-int(ver.let)==1){varans=max(varans,longest_path(d.w,d.h));}
			}
			if(x+1<grid[0].length())
			{
				d.w=x+1;d.h=y;
				if(int(grid[d.h][d.w])-int(ver.let)==1){varans=max(varans,longest_path(d.w,d.h));}
			}
			if(x+1<grid[0].length()&&y+1<grid.size())
			{
				d.w=x+1;d.h=y+1;
				if(int(grid[d.h][d.w])-int(ver.let)==1){varans=max(varans,longest_path(d.w,d.h));}
			}
		}
		paths[a][b]=varans+1;
		return paths[a][b];
			
}


int main()
{
	int w,h,cc=1;
	cin>>h>>w;
	while(!(h==0&&w==0))
	{
		grid.resize(h);
		paths.resize(h);
		for(int i=0;i<h;i++)
		{
			cin>>grid[i];
			paths[i].resize(grid[i].size());
			for(int j=0;j<paths[i].size();j++)paths[i][j]=-1;
		}
		int ans=0,varans;
		for(int i=0;i<h;i++)
		{
			for(int j=0;j<w;j++)
			{
				if(grid[i][j]!='A')continue;
				ans=max(ans,longest_path(j,i));
			}

		}
		cout<<"Case "<<cc<<": "<<ans<<endl;
		cc++;
		cin>>h>>w;
	}

}