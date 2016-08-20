#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int n;
	vector<int> v;
	cin>>n;
	v.resize(n);
	for(int i=0;i<n;i++)cin>>v[i];
	sort(v.begin(),v.end());
	int ans=-1000000;
	for(int i=0;i<n-2;i+=2)ans=max(ans,v[i+2]-v[i]);
	if(n%2==0)
	{
		ans=max(ans,v[n-1]-v[n-2]);
		for(int i=n-1;i>=2;i-=2)ans=max(ans,v[i]-v[i-2]);
		ans=max(ans,v[1]-v[0]);
		}
	else
	{
		ans=max(ans,v[n-1]-v[n-2]);
		for(int i=n-2;i>=2;i-=2)ans=max(ans,v[i]-v[i-2]);
		ans=max(ans,v[1]-v[0]);
	}
	cout<<ans<<endl;
}
