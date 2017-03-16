#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	vector<vector<int> > v;
	v.resize(13);
	for(int i=0;i<13;i++)v[i].resize(99);
		v[1][0]=1;
		for(int i=1;i<99;i++)v[1][i]=0;
			for(int i=2;i<13;i++)
			{
				for(int j=0;j<99;j++)
				{
					for(int k=0;k<i;k++)if(j-k>=0)v[i][j]+=v[i-1][j-k];
				}
			}

			int d;
			cin>>d;
			int a,b;
			for(int i=0;i<d;i++)
			{
				cin>>a>>b;
				cout<<v[a][b]<<endl;
			}
}