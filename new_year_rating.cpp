#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <math.h>
#include <map>
#include <queue>
#include <algorithm>
#include <list>

using namespace std;


#define ll long long int
#define umm(x,y) unordered_map<x,y >
#define pb push_back
#define foi(n) for(int i=0;i<n;i++)
#define foj(n) for(int j=0;j<n;j++)
#define foi1(n) for(int i=1;i<=n;i++)
#define vi vector<int>
#define vvi vector<vi >
#define vll vector<ll>
#define vvll vector<vll >
#define si size()


int main()
{
	int n,ch,divi;
	int mn=-20000000,mx=200000000,inf=20000001;
	cin>>n;
	foi(n)
	{
		cin>>ch>>divi;
		if(divi==1)
		{
			if(mn<1900)
			{
				mn=1900;
			}
			if(mn>mx)
			{
				cout<<"Impossible"<<endl;
				return 0;
			}
			mn+=ch;
			mx+=ch;
		}
		else if(divi==2)
		{
			if(mx>=1900)
			{
				mx=1899;
			}
			if(mn>mx)
			{
				cout<<"Impossible"<<endl;
				return 0;
			}
			mn+=ch;
			mx+=ch;
		}
		
	}
	if(mx>=100000000)
	{
		cout<<"Infinity"<<endl;
	}
	else cout<<mx<<endl;

}