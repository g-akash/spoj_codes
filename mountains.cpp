#include<bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin>>t;
	vector<int> a,b;
	for(int count=0;count<t;count++)
	{
		int m,n;
		
		cin>>m;
		a.resize(m);
		for(int i=0;i<m;i++)cin>>a[i];
		
		cin>>n;
		b.resize(n);
		for(int i=0;i<n;i++)cin>>b[i];
		sort(a.begin(),a.end());
		sort(b.begin(),b.end());
		
		int x=0,y=0,ans=1000000000;
		while(x<m-1||y<n-1)
		{
			//cout<<x<<" "<<y<<endl;
			ans=min(ans,abs(a[x]-b[y]));
			if(x==m-1){y++;continue;}
			else if(y==n-1){x++;continue;}
			else if(a[x]<b[y]){x++;continue;}
			else if(b[y]<=a[x]){y++;continue;}
		}
		ans=min(ans,abs(a[m-1]-b[n-1]));
		cout<<ans<<endl;

	}
}