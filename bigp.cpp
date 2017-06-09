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
	int a,b;
	int v1=0,v2=0,v3=0,v4=0;
	cin>>a>>b;
	int tmp = 1;
	while(a!=0)
	{
		if(a%10!=6&&a%10!=5)
		{
			v1=v1+tmp*(a%10);
			v3=v3+tmp*(a%10);
		}
		else
		{
			v1=v1+tmp*(5);
			v3=v3+tmp*(6);
		}
		tmp*=10;
		a/=10;
	}
	tmp=1;
	while(b!=0)
	{
		if(b%10!=6&&b%10!=5)
		{
			v2=v2+tmp*(b%10);
			v4=v4+tmp*(b%10);
		}
		else
		{
			v2=v2+tmp*(5);
			v4=v4+tmp*(6);
		}
		tmp*=10;
		b/=10;
	}
	tmp=1;
	cout<<v1+v2<<" "<<v3+v4<<endl;
}