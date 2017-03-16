#include<iostream>
#include<set>
#include<vector>
#include<algorithm>

using namespace std;


int main()
{
	int t;
	cin>>t;
	for(int xo=0;xo<t;xo++)
	{
		int n,l,r;
		cin>>n;
		vector<vector<int> > v;
		v.resize(10000001);
		for(int i=0;i<n;i++)
		{
			cin>>l>>r;
			v[l-1].push_back(i);
			v[r].push_back(i);
		}
		set<int>::iterator it;
		vector<int> vis;
		vis.resize(n);
		set<int> s;
		for(int i=10000000;i>0;i--)
		{
			for(int j=0;j<v[i].size();j++)
			{
				if(s.find(v[i][j])!=s.end())s.erase(v[i][j]);
				else s.insert(v[i][j]);
			}
			//cout<<i<<endl;
			it=s.end();
			//it--;
			if(!s.empty()){
			it--;vis[*(it)]=1;}
		}
		int ans=0;
		for(int i=0;i<vis.size();i++)ans+=vis[i];
			cout<<ans<<endl;
	}
}