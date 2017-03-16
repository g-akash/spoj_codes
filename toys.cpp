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
		int n,x,y;
		cin>>n>>x>>y;
		vector<int> a,b;
		a.resize(n);
		b.resize(n);
		for(int j=0;j<n;j++)
		{
			cin>>a[j]>>b[j];
		}
		sort(a.begin(),a.end());
		sort(b.begin(),b.end());
		int ans=0;
		for(int j=0;j<n;j++)
		{
			if(a[j]>b[j])ans+=y*(a[j]-b[j]);
			else ans+=x*(b[j]-a[j]);
		}
		cout<<ans<<endl;
	}
}
