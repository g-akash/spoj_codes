#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
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
#define vi vector<int>
#define vvi vector<vi >
#define si size()


int main()
{
	ll n,k;
	cin>>n>>k;
	vector<ll> vec(n);
	foi(n)cin>>vec[i];
	ll x=0,y=n+1;
	while(!(y-x==1)){
		ll mid = (x+y)/2;
		if((mid*(mid+1))/2>k){
			y=mid;
		}
		else{
			x=mid;
		}
	}
	if((x*(x+1))/2==k){
		cout<<vec[x-1]<<endl;
	}
	else{
		x=k-(x*(x+1))/2;
		cout<<vec[x-1]<<endl;
	}
}