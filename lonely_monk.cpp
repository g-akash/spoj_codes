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
	ll n;
	cin>>n;
	vector<ll> vec(n);
	foi(n)
	{
		cin>>vec[i];
	}

	ll ans=0,curr=0,cur=0;
	ll prev[2];
	prev[0]=0;
	prev[1]=0;
	foi(n)
	{
		if(vec[i]%2==0)
		{
			curr++;
			ans+=curr;
			ans+=prev[cur];
		}
		else 
		{
			ans+=prev[(cur+1)%2];
			//ans+=curr;
			curr++;
			prev[cur]+=curr;
			curr=0;
			cur=(cur+1)%2;
		}
	}
	cout<<ans<<endl;

}
