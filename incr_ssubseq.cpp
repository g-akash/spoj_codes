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
	
	int ans=1;
	int var=1;
	for(int i=1;i<n;i++)
	{
		if(v[i]>=v[i-1])var++;
		else var=1;
		ans=max(var,ans);
	}
	cout<<ans<<endl;
}

