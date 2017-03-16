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
	ll n,x=0,y=0;
	cin>>n;
	vector<ll> a(n),b(n);
	foi(n){
		cin>>a[i];
		x=x|a[i];
	}
	foi(n){
		cin>>b[i];
		y=y|b[i];
	}
	cout<<x+y<<endl;
}