#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main()
{
	vector<int> v;
	v.resize(10);
	for(int i=0;i<10;i++)cin>>v[i];
	int ans=0;
	int curr=0;
	for(int i=0;i<10;i++)
	{
		curr+=v[i];
		if(curr<=100)ans=curr;
		else if(curr>=100&&abs(100-ans)>abs(100-curr))ans=curr;
		else if(curr>=100&&abs(100-ans)==abs(100-curr))ans=curr;
	}
	cout<<ans<<endl;
}