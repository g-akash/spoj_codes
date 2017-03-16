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
		int a,n,j;
		cin>>a>>n;
		vector<int> v;
		v.resize(n);
		for( j=0;j<n;j++)cin>>v[j];
			sort(v.begin(),v.end());
		int ans=0;
		j=n-1;
		//cout<<a<<j<<endl;
		while(j>=0&&ans<a){ans+=v[j];j--;}
		if(ans>=a)cout<<"Scenario #"<<i+1<<":\n"<<n-1-j<<endl<<endl;
		else cout<<"Scenario #"<<i+1<<":\n"<<"impossible"<<endl<<endl;

	}
}