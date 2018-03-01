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


int dig_sum(int x)
{
	int ans = 0;
	while(x!=0)
	{
		ans+=(x%10);
		x/=10;
	}
	return ans;
}

int main()
{
	int n;
	cin>>n;
	int ans=0;
	for(int i=n;i>n-200&&i>=0;i--)
	{
		if(i+dig_sum(i)+dig_sum(dig_sum(i))==n)ans+=1;
	}
	cout<<ans<<endl;
}