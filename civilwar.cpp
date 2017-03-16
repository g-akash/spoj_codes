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
	int t;
	cin>>t;
	foi(t)
	{
		int n,k;
		cin>>n>>k;
		if(k==0)
		{
			for(int i=1;i<=n;i++)cout<<i<<" ";
				cout<<endl;
			continue;
		}
		if(n%(2*k)!=0)
		{
			cout<<"CAPTAIN AMERICA EVADES"<<endl;
		}
		else
		{
			int var = n/(2*k);
			foj(var)
			{
				for(int a=1;a<=k;a++)cout<<2*k*j+a+k<<" ";
				for(int a=1;a<=k;a++)cout<<2*k*j+a<<" ";
			}
			cout<<endl;
		}
	}
}