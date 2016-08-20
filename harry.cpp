#include<bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		vector<vector<int> > v,ans;
		int m,n;
		cin>>n>>m;
		v.resize(n);
		ans.resize(n);
		for(int j=0;j<n;j++)
		{
			v[j].resize(m);
			ans[j].resize(m);
		}
		for(int j=0;j<n;j++)
		{
			for(int k=0;k<m;k++)
			{
				cin>>v[j][k];
			}
		}
		for(int k=0;k<m;k++)ans[0][k]=v[0][k];
		for(int j=1;j<n;j++)
		{
			for(int k=0;k<m;k++)
			{
				if(m>1)
				{
					if(k==0)
					{
						ans[j][k]=v[j][k]+max(ans[j-1][k],ans[j-1][k+1]);
					}
					else if(k==m-1)
					{
						ans[j][k]=v[j][k]+max(ans[j-1][k],ans[j-1][k-1]);
					}
					else
					{
						ans[j][k]=v[j][k]+max(ans[j-1][k],max(ans[j-1][k-1],ans[j-1][k+1]));
					}
				}
				else
				{
					ans[j][k]=ans[j-1][k]+v[j][k];
				}

			}
		
		}
		int finans=-10000;
		for(int k=0;k<m;k++)finans=max(finans,ans[n-1][k]);
			cout<<finans<<endl;
	}
}