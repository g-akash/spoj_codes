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
#define MOD 1000000000000007


int main()
{
	int n,curr=0;
	vi vec;
	string s;
	cin>>n>>s;
	s=s+"W";
	n++;
	if(s[0]=='B')curr++;
	foi1(n-1){
		if(s[i]=='B')curr++;
		else{
			if(curr>0)vec.pb(curr);
			curr=0;
		}
	}

	cout<<vec.size()<<endl;
	foi(vec.size())cout<<vec[i]<<" ";
	if(vec.size()>0)cout<<endl;
}