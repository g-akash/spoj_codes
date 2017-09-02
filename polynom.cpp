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



double get_val(double a, double b, double c, double d, double x)
{
	double ans=a;
	a=a*x+b;
	a=a*x+c;
	a=a*x+d;
	return a;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector<double> vec(n);
		foi(n){
			cin>>vec[i];
		}
		if(n<=4)
		{
			cout<<"YES"<<endl;
		}
		else
		{
			double a,b,c,d;
			a= -1.0*vec[0]+3.0*vec[1]-3.0*vec[2]+1.0*vec[3];
			b= 9.0*vec[0]-24.0*vec[1]+21.0*vec[2]-6.0*vec[3];
			c= -26.0*vec[0]+57.0*vec[1]-42.0*vec[2]+11.0*vec[3];
			d= 24.0*vec[0]-36.0*vec[1]+24.0*vec[2]-6.0*vec[3];
			bool ans = true;
			foi1(n)
			{
				if(abs(get_val(a,b,c,d,(double)i)-6.0*vec[i-1])>=0.00000005)
					{
						ans=false;
						break;
					}
			}
			if(ans)cout<<"YES"<<endl;
			else cout<<"NO"<<endl;
		}
	}
}