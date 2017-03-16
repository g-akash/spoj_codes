#include <iostream>
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
	unordered_map<int,int> pv,vp;
	int n,k;
	cin>>n>>k;
	vi vec(n+1);
	foi1(n)
	{
		cin>>vec[i];
		pv[i]=vec[i];
		vp[vec[i]]=i;
	}
	for(int i=1;i<=n;i++)
	{
		if(k<=0)
		{
			cout<<pv[i]<<" ";
		}
		else
		{
			if(pv[i]!=n-i+1)
			{
				int a,b,c,d;
				a=vp[n-i+1];
				b=pv[i];
				pv[i]=pv[a];
				pv[a]=b;
				vp[pv[a]]=a;
				vp[pv[i]]=i;
				cout<<pv[i]<<" ";
				k--;
			}
			else
				cout<<pv[i]<<" ";
		}

		
	}
	cout<<endl;
}