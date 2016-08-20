#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int c;
	cin>>c;
	for(int i=0;i<c;i++)
	{
		int n,k,b,t;
		cin>>n>>k>>b>>t;
		vector<int> pos,sped;
		pos.resize(n);
		sped.resize(n);
		int j;
		for( j=0;j<n;j++)cin>>pos[j];
		for( j=0;j<n;j++)cin>>sped[j];
		int ans=0,cr=0,cnr=0;
		j=n-1;
		while(j>=0&&cr<k)
		{
			if(sped[j]*t+pos[j]>=b){cr++;ans+=cnr;}
			else {cnr++;}
			j--;
		}
		if(cr>=k){cout<<"Case #"<<i+1<<": "<<ans<<endl;}
			else {cout<<"Case #"<<i+1<<": "<<"IMPOSSIBLE"<<endl;}


	}
}