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


ll diams(int x)
{
	int ans = 0;
	while(x>0)
	{
		if((x%10)%2==0)ans+=(x%10);
		else ans-=(x%10);
		x/=10;
	}
	return (ll)abs(ans);

}

vll tmps(2000005);


ll get_sum(int x, int y)
{
	if(x>y)return 0;
	return (ll)(tmps[y]-tmps[x-1]);
}

int main()
{
	vll vec(1000005);
	
	tmps[0]=0;
	foi1(2000004)tmps[i]=diams(i)+tmps[i-1];


	vec[0]=0;
	vec[1]=2;
	for(int i=2;i<1000004;i++)
	{
		vec[i]=vec[i-1]+(ll)2*(get_sum(i+1,i+i-1))+get_sum(i+i,i+i);
	}
	int t;
	cin>>t;
	while(t--)
	{
		int var;
		cin>>var;
		cout<<vec[var]<<endl;
	}
}