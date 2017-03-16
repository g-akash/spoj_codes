#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int n;
	cin>>n;
	vector<int> v;
	v.resize(n);
	for(int i=0;i<n;i++)cin>>v[i];
	int maxx=0,curr=0;
	for(int i=0;i<n;i++)
	{
		curr+=v[i];
		if(curr<0)curr=0;
		maxx=max(curr,maxx);
	}
	cout<<maxx<<endl;
}
