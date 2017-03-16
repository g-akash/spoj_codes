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
		vector<int> v;
		v.resize(n);
		for(int i=0;i<n;i++)cin>>v[i];
		unsigned long long int ans=1;
		int x=0,y=1;
		for(y=1;y<n;y++)
		{
			if(v[y]<v[y-1]){ans++;x=y;}
			else if(v[y]>=v[y-1]){ans+=(unsigned long long int)(y-x+1);}
		}
		cout<<ans<<endl;
	}
}
		
