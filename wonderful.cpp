#include<iostream>
#include<vector>

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
	for(int i=0;i<n;i++)cin>>v[i];
	int ans=0;
	if(v[n-1]<0)v[n-1]=2000000000;
	for(int j=n-2;j>=0;j--)
	{
	if(v[j]<0||v[j]>v[j+1])
	{
		v[j]=v[j+1];
		ans++;
	}
	}
	cout<<ans<<endl;
	}
}