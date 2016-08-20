#include<iostream>
#iclude<vector>
#include<algorithm>

uisng namespace std;

#define ll long long int

int main()
{
	ll n,m,a,b,c;
	cin>>n>>m;
	vector<ll> v,sms;
	v.resize(n);
	ll len;
	for(int i=0;i<n;i++){cin>>v[i];len+=v[i];}
	sort(v.begin(),v.end());
	sms.resize(n+1);
	sms[0]=len;
	for(int i=0;i<n;i++)
	{
		if(i!=0)
		a=v[i]-v[i-1];
		else a=v[0];
		
		b=a*(n-1-i);
		len-=b;
		sms[i+1]=len;
	}
	vector<ll>::iterator it;
	int ko,x,y,z,ht;
	//it=lower_bound(sms.begin(),sms.end(),m);
	for(ko=0;ko<sms.size();ko++)
	{
			if(sms[ko]<=m)break;
		}
		
	if(sms[ko]==m){cout<<v[ko-1]<<endl;return 0;}
	if(sms[ko]<m){x=v[ko-2];y=v[ko-1];z=n-1-(ko-1);ht=;}
	while(!())
	{
		if(){}
		else if(){}
		else{}
	}
