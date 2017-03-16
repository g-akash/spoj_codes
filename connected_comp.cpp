#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
vector<int> v;
vector<vector<int> > vec;

void dffs(int n)
{
	for(int i=0;i<vec[n].size();i++)
	{
		if(v[vec[n][i]]==0){v[vec[n][i]]=1;dffs(vec[n][i]);}
	}
	return;
}

int dfs()
{
	int ans=0;
	for(int i=0;i<vec.size();i++)
	{
		if(v[i]==0){ans++;v[i]=1;dffs(i);}
	}
	return ans;
}


int main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		int n;
		cin>>n;
		v.resize(n);
		vec.resize(n);
		for(int j=0;j<n;j++){vec[j].resize(0);v[j]=0;}
		int rel,a,b;
		cin>>rel;
		for(int j=0;j<rel;j++){cin>>a>>b;vec[a].push_back(b);vec[b].push_back(a);}

		cout<<dfs()<<endl;
	}
}