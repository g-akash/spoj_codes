#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;

int main()
{
	int n,m;
	cin>>n>>m;
	vector<vector<int> > v;
	vector<vector<char> > bord;
	string s;
	v.resize(n);
	bord.resize(n);
	for(int i=0;i<n;i++)
	{
		v[i].resize(m);
		bord[i].resize(m);
		cin>>s;
		for(int j=0;j<m;j++)bord[i][j]=s[j];
	}
	vector<int> x,y;
	int ans=0;
	int va,vb;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(v[i][j]==1)
			{
				for(int k=0;k<x.size();k++)
				{
					v[x[k]][y[k]]=1;
				}
				x.resize(0);
				y.resize(0);
				}
			else if(v[i][j]==2)
			{
				x.push_back(i);
				y.push_back(j);
				for(int k=0;k<x.size();k++)
				{
					v[x[k]][y[k]]=1;
				}
				x.resize(0);
				y.resize(0);
				ans++;
				}
			else
			{
				va=i;vb=j;
				while(v[va][vb]!=2&&v[va][vb]!=1)
				{
					x.push_back(va);
					y.push_back(vb);
					v[va][vb]=2;
					if(bord[va][vb]=='N'){va--;}
					if(bord[va][vb]=='E'){vb++;}
					if(bord[va][vb]=='S'){va++;}
					if(bord[va][vb]=='W'){vb--;}
				}
				if(v[va][vb]==1)
				{
				for(int k=0;k<x.size();k++)
				{
					v[x[k]][y[k]]=1;
				}
				x.resize(0);
				y.resize(0);
				}
				else if(v[va][vb]==2)
				{
				x.push_back(i);
				y.push_back(j);
				for(int k=0;k<x.size();k++)
				{
					v[x[k]][y[k]]=1;
				}
				x.resize(0);
				y.resize(0);
				ans++;
				}
				
				}
		}
	}
	cout<<ans<<endl;
}
	
