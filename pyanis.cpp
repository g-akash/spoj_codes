#include<iostream>
#include<vector>
#include<stdio.h>

using namespace std;

#define ull unsigned long long


int main()
{
	  int n,var,ans=0;
	cin>>n;

	for(int i=0;i<n;i++)
	{
		scanf("%d",&var);
		ans=ans^var;
	}
	cout<<ans<<endl;
}