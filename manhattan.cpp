#include<iostream>
#include<stdio.h>


using namespace std;

int main()
{
	int n,k;
	scanf("%d",&n);
	scanf("%d",&k);
	//cin>>n>>k;
	int a[n][k];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<k;j++)scanf("%d",&a[i][j]);//cin>>a[i][j];
	}
	int dist=-1000000000,var;
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			var=0;
			for(int l=0;l<k;l++)
			var+=(a[i][l]>=a[j][l]?a[i][l]-a[j][l]:a[j][l]-a[i][l]);
			dist=dist>=var?dist:var;
		}
	}
	cout<<dist<<endl;
}
