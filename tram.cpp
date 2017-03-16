#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <math.h>
#include <map>
#include <queue>
#include <algorithm>

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
	int s,x1,x2,t1,t2,p,d;
	cin>>s>>x1>>x2>>t1>>t2>>p>>d;
	int mtim = abs(x2-x1)*t2;
	int ttim=100000000;
	if(x2>=x1)
	{
		if(d==1)
		{
			if(p>x1)
			{
				ttim=(2*s+x2-p)*t1;
			}
			else
			{
				ttim = (x2-p)*t1;
			}
		}
		else
		{
			ttim = (p+x2)*t1;
		}
	}
	else
	{
		if(d==-1)
		{
			if(p<x1)
			{
				ttim = (p+2*s-x2)*t1;
			}
			else
			{
				ttim = (p-x2)*t1;
			}
		}
		else
		{
			ttim = (2*s-p-x2)*t1;
		}
	}
	cout<<min(mtim,ttim)<<endl;
}