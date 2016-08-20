#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	int n,m;
	vector<vector<int> > v;
	cin>>n>>m;
	char ch;
	v.resize(n+1);
	for(int i=0;i<=n;i++)v[i].resize(m+1);
	for(int i=0;i<=m;i++)v[0][i]=0;
	for(int i=0;i<=n;i++)v[i][0]=0;
	int curr_row=0;
	for(int i=1;i<=n;i++)
	{
		curr_row=0;
		for(int j=1;j<=m;j++)
		{
			cin>>ch;
			if(ch=='_')
			{
				curr_row-=1;
				v[i][j]=curr_row+v[i-1][j];
			}
			else 
			{
				curr_row+=1;
				v[i][j]=curr_row+v[i-1][j];
			}
		}
		//cin>>ch;
	}
	int ans=0;
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=m;j++)
		{
			if(i+32<=n&&j+32<=m)
			{
				if(v[i][j+32]+v[i+32][j]-v[i][j]==v[i+32][j+32]){ans++;}
			}
			
		}
		
	}
	cout<<ans<<endl;
	
}

	
