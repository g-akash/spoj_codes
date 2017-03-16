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
	int a,b,c;
	cin>>a>>b>>c;
	int x=0,y=a;
	while(y-x>1)
	{
		int mid = (x+y)/2;
		if(2*mid<=b&&4*mid<=c)x=mid;
		else y=mid;
	}
	if(2*y<=b&&4*y<=c)cout<<7*y<<endl;
	else cout<<7*x<<endl;
}