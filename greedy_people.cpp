#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		int n,k;
		cin>>n>>k;
		vector<int> v;
		v.resize(n);
		for(int j=0;j<n;j++)cin>>v[j];
		sort(v.begin(),v.end());
		//for(int j=0;j<n;j++)cout<<v[j]<<" ";cout<<endl;
		int varc,ans=1000000,var;
		for(int j=0;j<n;j++)
		{
			varc=1;
			var=0;
			int x=j,y=j;
			while(varc!=k)
			{
				if(y==n-1){var+=3*(v[j]-v[--x]);}
				else if(x==0){var+=5*(v[++y]-v[j]);}
				else if(3*(v[j]-v[x-1])>=5*(v[y+1]-v[j])){var+=5*(v[++y]-v[j]);}
				else{var+=3*(v[j]-v[--x]);}
				varc++;
			}
			//cout<<var<<endl;
			ans=min(ans,var);
		}
		cout<<ans<<endl;
	}
}
			
