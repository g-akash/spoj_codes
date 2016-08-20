#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class req
{
public:
	int s,e,v,ans;
};

vector<req> v;

int solve(int n)
{
	if(n>=v.size())return 0;
	if(v[n].ans>=0)return v[n].ans;
	int ninc=solve(n+1);
	int i=n,anse=0;
	while(v[i].s<v[n].e&&i<v.size())i++;
	if(v[i].s>=v[n].e)anse=solve(i);
	v[n].ans=max(v[n].v+anse,ninc);
	return v[n].ans;
}


int main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		int m,n;
		cin>>n>>m;
		v.resize(n);
		for(int j=0;j<n;j++){cin>>v[i].s>>v[i].e>>v[i].v;v[i].ans=-1;}
			cout<<solve(0)<<endl;
	}
}