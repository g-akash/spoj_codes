#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>
#include <math.h>


using namespace std;


#define ll long long int
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
	int n,mrr=0,mrb=0,mbr=0,mbb=0;
	string s;
	cin>>n>>s;
	foi(n)
	{
		if(s[i]=='r'&&i%2==1)mrr++;
		if(s[i]=='b'&&i%2==0)mrb++;
	}
	foi(n){
		if(s[i]=='b'&&i%2==1)mbb++;
		if(s[i]=='r'&&i%2==0)mbr++;
	}
	int ans1=max(mrr,mrb),ans2=max(mbr,mbb);
	cout<<min(ans1,ans2)<<endl;
}