#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>


using namespace std;

int main()
{
	int t;
	cin>>t;
	//cout<<endl;
	for(int i=0;i<t;i++)
	{
		int n,m;
		scanf("%d",&n);
		scanf("%d",&m);
		//cin>>n>>m;
		int mx=-1000,mn=1000000000,var;
		for(int j=0;j<m;j++)
		{
			scanf("%d",&var);
			if(var>mx)mx=var;
			if(var<mn)mn=var;
		}
		//cout<<"Oj"<<mn<<" "<<mx<<endl;
		for(int j=0;j<n;j++)
		{
			if(j<mn)cout<<mx-j<<" ";
			else if(j>=mn&&j<=mx)cout<<max(mx-j,j-mn)<<" ";
			else if(j>mx)cout<<j-mn<<" ";
		}
		cout<<endl;
	}
}