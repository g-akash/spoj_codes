#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n,m;
vector<vector<int> > v;
vector<int> cat;
int ans=0;

void rest(int a,int b)
{
	//cout<<a<<" "<<b<<endl;
	int ct;
	if(cat[a]==1)ct=b+1;
	else ct=0;
	if(ct>m)return;
	if(v[a].size()==0){ans++;return;}
	for(int i=0;i<v[a].size();i++)
	{
		rest(v[a][i],ct);
	}
	return;
}

int main()
{
	cin>>n>>m;
	v.resize(n+1);
	cat.resize(n+1);
	int a,b;
	for(int i=1;i<=n;i++)cin>>cat[i];
	for(int i=0;i<n-1;i++)
	{
		cin>>a>>b;
		v[a].push_back(b);
	}
	rest(1,0);
	cout<<ans<<endl;
	
}
	
	
