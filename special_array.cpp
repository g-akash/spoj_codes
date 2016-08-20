#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


int main()
{
	int n,m;
	cin>>n>>m;
	vector<int> v,vec;
	v.resize(n);
	vec.resize(n);
	for(int i=0;i<n;i++)
	{
		cin>>v[i];
	}
	for(int i=1;i<n-1;i++)
	{
		if(v[i-1]>v[i]&&v[i]<v[i+1])vec[i]=1;
	}
	for(int i=1;i<n;i++)vec[i]+=vec[i-1];
		for(int i=0;i<m;i++)
		{
			int a,b;
			cin>>a>>b;
			a--;b--;
			if(vec[b-1]-vec[a]>0)cout<<"No"<<endl;
			else cout<<"Yes"<<endl;
		}



}