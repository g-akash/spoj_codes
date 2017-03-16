<<<<<<< HEAD
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <math.h>


using namespace std;


#define ll long long int
#define ull unsigned long long int
#define umm(x,y) unordered_map<x,y >
#define pb push_back
#define foi(n) for(int i=0;i<n;i++)
#define foj(n) for(int j=0;j<n;j++)
#define foi1(n) for(int i=1;i<=n;i++)
#define foj1(n) for(int j=1;j<=n;j++)
#define vi vector<int>
#define vvi vector<vi >
#define si size()
#define MOD 1000000007


int main()
{
	ull ans=1;
	int n, var;
	cin>>n;
	vi v;
	foi(n){
		cin>>var;if(var==1)v.pb(i);
	}
	for(int i=1;i<v.size();i++)
	{
		ans*=(ull)(v[i]-v[i-1]);
	}
	if(v.size()>0)cout<<ans<<endl;
	else cout<<0<<endl;
=======
#include<iostream>
#include<vector>

using namespace std;

#define ull unsigned long long int

int main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		ull n,cut=0,len=1,ans;
		cin>>n;
		while(len<n)len*=2;
		ans=len;
		while(n>0)
		{
			if(len<=n){n-=(len);}
			else{len/=2;cut++;}
			
		}
		cout<<ans<<" "<<cut<<endl;
	}
>>>>>>> 605cad988f52511160a1c156a1f635a23974d531
}