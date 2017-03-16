#include<bits/stdc++.h>

using namespace std;
#define ll long long

vector<ll int> v;
vector<ll int> ans;

ll int maxgold(ll int i)
{
	if(i>=v.size())return 0;
	if(ans[i]>=0)return ans[i];
	ll int ans1=v[i]+maxgold(i+2),ans2=maxgold(i+1);
	//cout<<ans1<<" "<<ans2<<endl;
	ans1=max(ans1,ans2);
	ans[i]=ans1;
	return ans[i];
}


int main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		ll int n;
		cin>>n;
		v.resize(n);
		ans.resize(n);
		for(ll int j=0;j<n;j++){cin>>v[j];ans[j]=-1;}
		cout<<"Case "<<i+1<<": "<<maxgold(0)<<endl;

	}


}