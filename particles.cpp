#include <iostream>
#include <vector>
#include <algorithm>
#include <string>


using namespace std;

#define ll long long int

int main()
{
	int n;
	cin>>n;
	string dir;
	vector<ll> pos;
	pos.resize(n);
	cin>>dir;
	for(int i=0;i<n;i++)
	{
		cin>>pos[i];
	}
	ll ans=10000000000;
	for(int i=0;i<n-1;i++)
	{
		if(dir[i]=='R'&&dir[i+1]=='L')
		{
			ans=min(ans,(pos[i+1]-pos[i])/2);
		}
	}
	if(ans>=10000000000)cout<<-1<<endl;
	else cout<<ans<<endl;
}