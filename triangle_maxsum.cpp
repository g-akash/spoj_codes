#include<bits/stdc++.h>

using namespace std;

int main()
{
	int t,n,i,j,ans,var;
	cin>>t;
	for(int xo=0;xo<t;xo++)
	{
		
		cin>>n;
		vector<vector<int> > v;
		v.resize(n);
		cin>>var;
		v[0].push_back(var);
		for(i=1;i<n;i++)
		{
			for(j=0;j<i;j++)
			{
				cin>>var;
				v[i].push_back(0);
				v[i][j]=var+max(v[i-1][j],v[i-1][j-1]);
				
			}
			cin>>var;
			v[i].push_back(0);
			v[i][j]=var+v[i-1][j-1];
		}
		ans=0;
		for(i=0;i<v[n-1].size();i++)ans=max(ans,v[n-1][i]);
		cout<<ans<<endl;
	}
}