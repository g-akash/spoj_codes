#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

#define ll long long int

int main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		int n;
		cin>>n;
		string s;
		ll var;
		vector<ll> vec;
		vec.resize(n);
		for(int i=0;i<n;i++)
		{
			cin>>s>>vec[i];
		}
		sort(vec.begin(),vec.end());
		ll ans=0;
		for(int i=0;i<n;i++)
		{
			ans+=abs(i+1-vec[i]);
		}
		cout<<ans<<endl;
	}
}