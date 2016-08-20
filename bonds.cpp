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
		vector<unsigned long long int> m,w;
		m.resize(n);w.resize(n);
		for(int j=0;j<n;j++)cin>>m[j];
			for(int j=0;j<n;j++)cin>>w[j];
		sort(m.begin(),m.end());
	sort(w.begin(),w.end());
	unsigned long long int ans=0;
	for(int j=0;j<n;j++)ans+=(m[j]*w[j]);
		cout<<ans<<endl;

	}
}