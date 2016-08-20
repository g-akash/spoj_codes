#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int n;
	cin>>n;
	while(n!=0)
	{
		vector<unsigned long long int> v1,v2;
		v1.resize(n);
		v2.resize(n);
		for(int i=0;i<n;i++)cin>>v1[i];
			for(int i=0;i<n;i++)cin>>v2[i];
		sort(v1.begin(),v1.end());
		sort(v2.begin(),v2.end());
		unsigned long long int ans=0;
		for(int i=0;i<n;i++)ans+=v1[i]*v2[n-1-i];
		cout<<ans<<endl;
	cin>>n;
	}
}