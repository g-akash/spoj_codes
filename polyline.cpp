#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
#include<iomanip>

using namespace std;
int n;
int a,b;

int v(int x, int y)
{
	if(y-x<=1)
	{
		int ans1=max(x,y),ans2=min(x,y);
		if(double(n)/(2.0*double(ans1))>=double(b))return ans1;
		return ans2;
	}
	int m=(x+y)/2;
	if(double(n)/(2.0*double(m))>=double(b))return v(m,y);
	else return v(x,m);
}
	
	

int main()
{
	cin>>a>>b;
	n=a+b;
	if(b>a){cout<<-1<<endl;return 0;}
	double ans=v(1,n);
	cout<<fixed<<setprecision(12)<<double(n)/(2.0*double(ans))<<endl;
}
