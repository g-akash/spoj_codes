#include <iostream>
#include <iomanip>
#include <vector>
#include <unordered_map>
#include <string>
#include <math.h>
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
#define PI (12.566370614359172464/4.0)

int main()
{
	int n;
	double x,y,a,b,t,var,d1,d2,px,py,sx,sy,vx,vy;
	cin>>n>>x>>y;
	double mn=100000000000000.0,mx=0;
	cin>>a>>b;
	var=(a-x)*(a-x)+(b-y)*(b-y);
	mn=min(mn,var);	
	mx=max(mx,var);
	px=a;py=b;
	sx=a;sy=b;
	for(int i=1;i<n;i++)
	{
		cin>>a>>b;
		var=(a-x)*(a-x)+(b-y)*(b-y);
		t=((x-px)*(a-px)+(y-py)*(b-py))/(pow(a-px,2.0)+pow(b-py,2.0));
		t=min(max(t,0.0),1.0);
		mx=max(mx,var);
		vx=px+t*(a-px);
		vy=py+t*(b-py);
		var=(vx-x)*(vx-x)+(vy-y)*(vy-y);
		//cout<<var<<"ll"<<endl;
		mn=min(mn,var);
		px=a;py=b;
	}
	a=sx;b=sy;
	t=((x-px)*(a-px)+(y-py)*(b-py))/(pow(a-px,2.0)+pow(b-py,2.0));
	t=min(max(t,0.0),1.0);
	//mx=max(mx,var);
	a=px+t*(a-px);
	b=py+t*(b-py);
	var=(a-x)*(a-x)+(b-y)*(b-y);
	mn=min(mn,var);
	//px=a;py=b;
	//cout<<var<<"ll"<<endl;
	//cout<<mx<<" "<<mn<<endl;
	cout<<fixed<<setprecision(18)<<(mx-mn)*PI<<endl;
}