#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <math.h>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <list>

using namespace std;


#define ll long long int
#define ull unsigned ll
#define umm(x,y) unordered_map<x,y >
#define mm(x,y) map<x,y >
#define pb push_back
#define foi(n) for(int i=0;i<n;i++)
#define foj(n) for(int j=0;j<n;j++)
#define foi1(n) for(int i=1;i<=n;i++)
#define foj1(n) for(int j=1;j<=n;j++)
#define vi vector<int>
#define vb vector<bool>
#define vvi vector<vi >
#define vvb vector<vb >
#define vll vector<ll>
#define vvll vector<vll >
#define si size()


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int d,y;
		string mon;
		cin>>d>>mon>>y;
		if(d>=2)
		{
			cout<<d-1<<" "<<mon<<" "<<y<<endl;
			continue;
		}
		if(d==1&&mon=="January")
		{
			cout<<31<<" December "<<y-1<<endl;
			continue;
		}
		if(d==1&&mon!="March")
		{
			if(mon=="February"){cout<<31<<" January "<<y<<endl;}
			else if(mon=="April"){cout<<31<<" March "<<y<<endl;}
			else if(mon=="May"){cout<<30<<" April "<<y<<endl;}
			else if(mon=="June"){cout<<31<<" May "<<y<<endl;}
			else if(mon=="July"){cout<<30<<" June "<<y<<endl;}
			else if(mon=="August"){cout<<31<<" July "<<y<<endl;}
			else if(mon=="September"){cout<<31<<" August "<<y<<endl;}
			else if(mon=="October"){cout<<30<<" September "<<y<<endl;}
			else if(mon=="November"){cout<<31<<" October "<<y<<endl;}
			else if(mon=="December"){cout<<30<<" November "<<y<<endl;}
			continue;
			
		}
		if(d==1&&mon=="March")
		{
			if(y%4==0&&y%100!=0)cout<<29<<" February "<<y<<endl;
			else cout<<28<<" February "<<y<<endl;
			continue;
		}

	}
}