#include<bits/stdc++.h>

using namespace std;

#define ll long long int

int main()
{
	int n;
	cin>>n;
	vector<ll> var;
	var.resize(n);
	for(int i=0;i<n;i++)
	{
		cin>>var[i];
	}
	vector<ll> nums,sums;
	nums.resize(n);
	sums.resize(n);
	ll temp=0;
	for(int i=n-1;i>=0;i--)
	{
		nums[n-1-i]=var[i];
		sums[n-1-i]=temp+var[i];
		temp=sums[n-1-i];
	}
	int q;
	ll l,r,x;
	cin>>q;
	for(int i=0;i<q;i++)
	{
		cin>>temp;
		if(temp==1)
		{
			cin>>l>>r;
			l--;
			r--;
			l=nums.size()-1-l;
			r=nums.size()-1-r;
			l+=r;
			r=l-r;
			l-=r;
			if(l==0)cout<<sums[r]<<endl;
			else cout<<sums[r]-sums[l-1]<<endl;
		}
		else
		{
			cin>>x;
			nums.push_back(x);
			sums.push_back(sums[sums.size()-1]+x);
		}
	}
}