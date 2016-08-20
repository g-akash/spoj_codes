#include<bits/stdc++.h>

using namespace std;
vector<vector<int> > depends;



int main()
{
	int n,m;
	cin>>n>>m;
	depends.resize(n+1);
	for(int i=0;i<=n;++i)
	{
		depends[i].resize(n+1);
	}
	for(int i=0;i<m;i++)
	{
		int t,k,d;
		cin>>t>>k;
		for(int j=0;j<k;j++)
		{
			cin>>d;
			depends[t][d]=1;
		}
	}
	//cout<<depends[3][5]<<" "<<depends[3][1]<<endl;
	vector<int> tasks,ans;
	tasks.resize(n);
	ans.resize(n);
	for(int i=0;i<n;++i)
	{
		tasks[i]=i+1;
	}
	vector<int> done;
	done.resize(n+1);
	for(int i=0;i<n;i++)
	{
		int sum=0;
		for(int j=1;j<=n;j++)
		{
			sum=0;
			for(int k=1;k<=n;k++)sum+=depends[j][k];
			if(sum==0&&!done[j])
			{
				ans[i]=j;
				done[j]=1;
				for(int k=1;k<=n;k++)depends[k][j]=0;
				break;
			}
		}
	}
	//sort(tasks.begin(),tasks.end(),comp);
	for(int i=0;i<tasks.size();i++)cout<<ans[i]<<" ";cout<<endl;
}