#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <math.h>
#include <map>
#include <queue>
#include <algorithm>
#include <list>

using namespace std;


#define ll long long int
#define umm(x,y) unordered_map<x,y >
#define pb push_back
#define foi(n) for(int i=0;i<n;i++)
#define foj(n) for(int j=0;j<n;j++)
#define foi1(n) for(int i=1;i<=n;i++)
#define vi vector<int>
#define vvi vector<vi >
#define vll vector<ll>
#define vvll vector<vll >
#define si size()


int main()
{
	vector<ll> v1,v2;
	ll n,k;
	cin>>n>>k;
	ll srt = sqrt(n);
	foi1(srt)
	{
		if(n%i==0)
		{
			v1.pb(i);
			//cout<<i<<endl;
			if(n/i!=i)v2.pb(n/i);
		}
	}
	//cout<<v1.size()<<" "<<v2.size()<<endl;
	if(v1.size()>=k)
	{
		cout<<v1[k-1]<<endl;
		//cout<<"ll"<<endl;
	}
	else if(v1.size()+v2.size()>=k)
	{
		cout<<v2[v2.size()-(k-v1.size())]<<endl;
		//cout<<v2.size()-(k-v1.size())<<endl;
	}
	else cout<<-1<<endl;
}