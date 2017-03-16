#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		int n,k;
		cin>>n>>k;
		vector<int> v;
		v.resize(n);
		for(int j=0;j<n;j++)
		{
			cin>>v[j];
		}
		sort(v.begin(),v.end());
		int mindiff=1000005000;
		for(int j=0;j+k-1<n;j++)
		{
			mindiff=min(mindiff,v[j+k-1]-v[j]);
		}
		cout<<mindiff<<endl;
	}
}