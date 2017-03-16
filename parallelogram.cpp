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

bool check(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4)
{
	if(x2-x1==x3-x4&&y2-y1==y3-y4&&x4-x1==x3-x2&&y4-y1==y3-y2)return true;
	return false;
}


int main()
{
	int x1,x2,x3,y1,y2,y3;
	cin>>x1>>y1>>x2>>y2>>x3>>y3;
	vi x,y;
	int vx,vy;
	vx=x2+x3-x1;
	vy=y2+y3-y1;
	if(check(x1,y1,x2,y2,vx,vy,x3,y3))
	{
		x.pb(vx);
		y.pb(vy);
	}
	vx=x3+x1-x2;
	vy=y3+y1-y2;
	if(check(x2,y2,x3,y3,vx,vy,x1,y1))
	{
		x.pb(vx);
		y.pb(vy);
	}
	vx=x1+x2-x3;
	vy=y1+y2-y3;
	if(check(x3,y3,x1,y1,vx,vy,x2,y2))
	{
		x.pb(vx);
		y.pb(vy);
	}
	cout<<x.size()<<endl;
	foi(x.size())cout<<x[i]<<" "<<y[i]<<endl;

}