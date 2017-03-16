#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <math.h>
#include <map>

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
	int n,h,d;
	int c1,c2;
	cin>>n>>d>>h;
	if(h<=0||h>n-1||d>2*h||d<h||(h==n-1&&d!=n-1)){cout<<-1<<endl;return 0;}
	if(h!=d||n==2){
		
		c1=h;
		c2=d-h;
		for(int i=0;i<c1;i++)
		{
			cout<<i+1<<" "<<i+2<<endl;
		}
		int prev=1;
		for(int i=0;i<c2;i++)
		{
			cout<<prev<<" "<<i+c1+2<<endl;
			prev=i+c1+2;
		}
		for(int i=c1+c2+2;i<=n;i++)cout<<1<<" "<<i<<endl;
	}
	else if(h<2&&d==h)
	{
		cout<<-1<<endl;
	}
	else
	{
		c1=h;
		c2=d-h;
		for(int i=0;i<c1;i++)
		{
			cout<<i+1<<" "<<i+2<<endl;
		}
		for(int i=c1+c2+2;i<=n;i++)cout<<2<<" "<<i<<endl;
	}
}