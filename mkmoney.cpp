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
#include <iomanip>

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
	double p,i,inter,interest;
	int t;
	int cnum = 1;
	while(cin>>p>>inter>>t)
	{
		if(p==0.0&&inter==0.0&&t==0)break;
		i = inter;
		i/=double(t);
		i/=100.0;
		double ans = p;
		//cout<<ans<<" "<<i<<endl;
		foj(t)
		{
			interest = ans*i;
			interest = (double)(floor(interest*100))/100.0;
			ans+=interest;
		}
		//cout<<ans<<endl;
		cout<<"Case "<<cnum<<". $"<<fixed<<setprecision(2)<<p<<" at "<<fixed<<setprecision(2)<<inter<<"% APR compounded "<<t<<" times yields $"<<fixed<<setprecision(2)<<ans<<endl;
		cnum+=1;
	}

}