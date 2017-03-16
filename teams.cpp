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
		int n;
		cin>>n;
		vector<int> v;
		v.resize(n);
		for(int j=0;j<n;j++)cin>>v[j];
		sort(v.begin(),v.end());
		int maxx=-1000000000,minn=1000000000;
		for(int j=0;j<n/2;j++)
		{
			if(v[j]+v[n-1-j]>maxx)maxx=v[j]+v[n-1-j];
			if(v[j]+v[n-1-j]<minn)minn=v[j]+v[n-1-j];
		}
		cout<<maxx-minn<<endl;
	}
}
