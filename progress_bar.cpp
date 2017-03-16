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
#define PI 3.1415926535897932384

int main()
{
	int t;
	cin>>t;
	double p,x,y,dg;
	foi(t)
	{
		cin>>p>>x>>y;
		cout<<"Case #"<<i+1<<": ";
		double dx=x-50.0,dy=y-50.0;
		double ds=sqrt(dx*dx+dy*dy);
		if(ds-50.0>0.000001)
		{
			cout<<"white"<<endl;
			continue;
		}
		if(dx==0&&dy>=0)
		{
			if(p>0.0)
			{
				cout<<"black"<<endl;
			}
			else cout<<"white"<<endl;
			continue;
		}
		else if(dx==0&&dy<0)
		{
			if(p>=50.0)
			{
				cout<<"black"<<endl;
			}
			else cout<<"white"<<endl;
			continue;
		}
		else if(dx>0&&dy>=0)
		{
			dg = 90.0-(atan2(dy,dx)*180.0)/PI;
			dg=(dg*100.0)/360.0;
			if(dg-p>0.000001)cout<<"white"<<endl;
			else cout<<"black"<<endl;
			continue;
		}
		else if(dx>0&&dy<=0)
		{
			dg = (atan2(dy,dx)*180.0)/PI;
			dg=(-dg)+90.0;
			dg=(dg*100.0)/360.0;
			if(dg-p>0.000001)cout<<"white"<<endl;
			else cout<<"black"<<endl;
			continue;
		}
		else if(dx<0&&dy>=0)
		{
			dg = (atan2(dy,-dx)*180.0)/PI;
			dg+=270.0;
			dg=(dg*100.0)/360.0;
			if(dg-p>0.000001)cout<<"white"<<endl;
			else cout<<"black"<<endl;
			continue;
		}
		else if(dx<0&&dy<0)
		{
			dg = (atan2(-dy,-dx)*180.0)/PI;
			dg-=270.0;
			dg=-dg;
			dg=(dg*100.0)/360.0;
			if(dg-p>0.000001)cout<<"white"<<endl;
			else cout<<"black"<<endl;
			continue;

		}

	}
}