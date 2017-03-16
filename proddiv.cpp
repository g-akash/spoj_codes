#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>
#include <math.h>


using namespace std;


#define ll long long int
#define MOD 1000000007
#define umm(x,y) unordered_map<x,y >
#define pb push_back
#define foi(n) for(int i=0;i<n;i++)
#define foj(n) for(int j=0;j<n;j++)
#define foi1(n) for(int i=1;i<=n;i++)
#define vi vector<int>
#define vvi vector<vi >
#define si size()
#define vll vector<ll>
#define vvll vector<vll >

ll pw(ll x, ll y){
	ll ans=1,vr=x;
	while(y>0)
	{
		if(y%2==1)ans*=vr;
		ans%=MOD;
		vr*=vr;
		vr%=MOD;
		y/=2;
	}
	return ans;
}

int main()
{
	int n;
	ll x,pd=1;
	cin>>n;
	vll v(200005,0),w,num;
	foi(n){
		cin>>x;
		v[x]++;
		pd*=x;
		pd%=MOD;
		
	}
	//cout<<pd<<endl;
	bool hasdone=false;
	foi(v.size()){
		if(v[i]%2==1)hasdone=true;
	}
	if(!hasdone)
	{
		pd = 1;
		for(ll i=0;i<v.size();i++)
		{
			foj(v[i]/2){
				pd*=i;
				pd%=MOD;
			}
		}
	}
	//cout<<hasdone<<endl;
	foi(200005){
		if(v[i]>0)
			{
				if(hasdone&&v[i]%2==1)
				{
					w.pb((v[i]+1)/2);
					hasdone=false;
				}
				else
				{
					w.pb(v[i]+1);
				}
			}
	}
	foi(w.size()){
		//cout<<pd<<" "<<w[i]<<endl;
		pd=pw(pd,w[i]);
	}
	cout<<pd<<endl;
	

}