#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

#define ll unsigned long long int

int main()
{
	int n,q;
	cin>>n>>q;
	vector<ll> v1,v2;
	v1.resize(n);
	v2.resize(n);
	for(int i=0;i<n;i++)cin>>v1[i];
	for(int i=0;i<n;i++)cin>>v2[i];
	int var;
	for(int i=1;i<n;i+=2)
	{
		var=v1[i];
		v1[i]=v2[i];
		v2[i]=var;
	}
	//for(int i=0;i<n;i++)cout<<v1[i]<<" ";cout<<endl;
	//for(int i=0;i<n;i++)cout<<v2[i]<<" ";cout<<endl;
	for(int i=1;i<n;i++)
	{
		v1[i]+=v1[i-1];
		v2[i]+=v2[i-1];
	}
	int ng,l,r;
	for(int i=0;i<q;i++)
	{
		cin>>ng>>l>>r;
		l--;
		r--;
		//cout<<l<<" okay "<<r<<endl;
		if(ng==1)
		{
			if(l%2==0){
			if(l!=0)cout<<v1[r]-v1[l-1]<<endl;
			else cout<<v1[r]<<endl;}
			else
			{
			if(l!=0)cout<<v2[r]-v2[l-1]<<endl;
			else cout<<v2[r]<<endl;
			}
		}
		else
		{
			if(l%2==0)
			{
			if(l!=0)cout<<v2[r]-v2[l-1]<<endl;
			else cout<<v2[r]<<endl;
			}
			else
			{
				if(l!=0)cout<<v1[r]-v1[l-1]<<endl;
			else cout<<v1[r]<<endl;
		}
		
		}
	}
}
