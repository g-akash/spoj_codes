#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

#define ll long long

int main()
{
	int t;
	cin>>t;
	for(ll int i=0;i<t;i++)
	{
		ll int n;
		cin>>n;
		vector<ll int> v1,v2;
		v1.resize(n);
		v2.resize(n);
		for(ll int j=0;j<n;j++)cin>>v1[j];
		for(ll int j=0;j<n;j++)cin>>v2[j];
		reverse(v2.begin(),v2.end());
		ll int ans=0,a,b,c;
		vector<ll int>::iterator it,it2=v2.begin();
		for(ll int i=0;i<n;i++)
		{
			it2=upper_bound(v2.begin(),v2.end(),v1[i]);
			while(it2!=v2.begin()){it=it2-1;if(*(it)==v1[i])it2--;else break;}
			//cout<<i<<" "<<*it2<<" "<<v2.end()-it2<<endl;
			ans=max(ans,(ll int)(v2.end()-it2)-(i+1));
		}
		cout<<ans<<endl;
	}
}
		
