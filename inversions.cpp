#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

#define ll long long int

ll sorti(vector<ll> &v)
{
	if(v.size()==1||v.size()==0)return 0;
	vector<ll> v1,v2;
	ll ans=0,mid=v.size()/2;
	for(int i=0;i<mid;i++)v1.push_back(v[i]);
	for(int i=mid;i<v.size();i++)v2.push_back(v[i]);
	//for(int i=0;i<v1.size();i++)cout<<v1[i]<<" ";
	//for(int i=0;i<v2.size();i++)cout<<v2[i]<<" ";
	//	cout<<"okk"<<endl;
	ans+=sorti(v1);
	ans+=sorti(v2);
	int x=0,y=0;
	//cout<<v1.size()<<"ok"<<v2.size()<<endl;
	//for(int i=0;i<v1.size();i++)cout<<v1[i]<<" ";cout<<endl;
	for(int i=0;i<v.size();i++)
	{
		//cout<<"hello"<<endl;
		if(x>=v1.size()){v[i]=v2[y];y++;}
		else if(y>=v2.size()){v[i]=v1[x];x++;}
		else
		{
			if(v1[x]>v2[y]){v[i]=v2[y];ans+=v1.size()-x;y++;}
			else {v[i]=v1[x];x++;}
		}
	}
		return ans;
}

int main()
{
	int t;
	cin>>t;
	for(int xo=0;xo<t;xo++)
	{
		int n;
		cin>>n;
		vector<ll> v;
		v.resize(n);
		for(int i=0;i<n;i++)cin>>v[i];
		ll ans = sorti(v);
	cout<<ans<<endl;
	}
}