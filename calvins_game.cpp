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
	int n,k;
	cin>>n>>k;
	k--;
	vi vec(n);
	foi(n)cin>>vec[i];
	vi fz(n),fk(n);
	fz[0]=vec[0];
	fz[1]=vec[0]+vec[1];
	fk[k]=0;
	if(k<n-1)fk[k+1] = 	vec[k+1];
	for(int i=2;i<n;i++)
	{
		fz[i] = max(fz[i-2],fz[i-1])+vec[i];
	}
	for(int i=k+2;i<n;i++)
	{
		fk[i] = max(fk[i-1],fk[i-2])+vec[i];
	}
	int ans=k;
	for(int i=k;i<n;i++)
	{
		if(fz[i]+fk[i]-vec[i]>fz[ans]+fk[ans]-vec[ans])
		{
			ans = i;
		}
	}
	cout<<fz[ans]+fk[ans]-vec[ans]<<endl;
}