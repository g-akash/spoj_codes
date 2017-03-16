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
#define vi vector<int>
#define vvi vector<vi >
#define si size()


bool poss(ull k, ull x, vector<ull> &req, vector<ull> &ava){
	foi(req.size()){
		if(req[i]*x<=ava[i])continue;
		else if(k>=(req[i]*x-ava[i])) k-=(req[i]*x-ava[i]);
		else return false;
	}
	return true;;
}

int main()
{
	ull n,k,mx=0;
	cin>>n>>k;
	vector<ull> req(n,0),ava(n,0);
	foi(n){
		cin>>req[i];
	}
	foi(n){
		cin>>ava[i];
		mx=max(mx,(ava[i]+k)/req[i]);
	}
	ull x=0,y=mx+1;
	while(y-x>1)
	{
		ull mid = (x+y)/2;
		if(poss(k, mid, req, ava))x=mid;
		else y=mid;
	}
	cout<<x<<endl;
}