#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>

using namespace std;

vector<int> a,b;
unordered_map<string, vector<int> >m; 

vector<int> ls(int x, int y)
{
	string s=to_string(x)+"A"+to_string(y);
	vector<int> ans;
	ans.resize(0);
	if(x>=a.size()||y>=b.size())return ans;
	if(m.find(s)!=m.end())return m[s];
	else if(a[x]==b[y])
	{
		ans=ls(x+1,y+1);
		ans.push_back(a[x]);
		m[s]=ans;
		return ans;
	}
	else
	{
		vector<int> ans1=ls(x+1,y),ans2=ls(x,y+1);
		if(ans1.size()>ans2.size()){m[s]=ans1;return ans1;}
			else{m[s]=ans2;return ans2;}
	}
}

int main()
{
	int n,m;
	cin>>n>>m;
	a.resize(n);
	b.resize(m);
	for(int i=0;i<n;i++)cin>>a[i];
		for(int i=0;i<m;i++)cin>>b[i];
	vector<int> ans=ls(0,0);
for(int i=ans.size()-1;i>=0;i--)cout<<ans[i]<<" ";
	
}