#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;

int main()
{
	int n,m;
	cin>>n>>m;
	vector<vector<int> > v,ans;
	v.resize(n);
	ans.resize(n);
	for(int i=0;i<n;i++){v[i].resize(m);ans[i].resize(m);}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)cin>>v[i][j];
	}
	for(int j=0;j<m;j++)ans[0][j]=v[0][j];
	for(int i=1;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(j-1>=0&&j+1<m)ans[i][j]=v[i][j]+min(min(ans[i-1][j-1],ans[i-1][j]),ans[i-1][j+1]);
			else if(j-1<0&&j+1<m)ans[i][j]=v[i][j]+min(ans[i-1][j],ans[i-1][j+1]);
			else if(j-1>=0&&j+1>=m)ans[i][j]=v[i][j]+min(ans[i-1][j-1],ans[i-1][j]);
			else ans[i][j]=v[i][j]+ans[i-1][j];
		}
	}
	int minn=100000000;
	//for(int i=0;i<n;i++){for(int j=0;j<m;j++)cout<<ans[i][j]<<" ";cout<<endl;}
	for(int j=0;j<m;j++)if(ans[n-1][j]<minn)minn=ans[n-1][j];
		cout<<minn<<endl;

}