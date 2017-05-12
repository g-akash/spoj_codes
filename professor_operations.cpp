#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <math.h>
#include <map>
#include <queue>
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
	int n,q,l,r;
	cin>>n;
	vi vec(n+2),op(n+2);
	foi1(n)cin>>vec[i];
	cin>>q;

	foi(q)
	{
		cin>>l>>r;
		op[l]+=1;
		op[r+1]+=1;
	}
	int curr=0;
	vi res(n+1);
	foi1(n)
	{
		curr+=op[i];
		if(curr%2==0)res[i]=vec[i];
		else 
		{
			res[i]=vec[n-i+1];
			res[n-i+1]=vec[i];
			vec[n-i+1]=res[n-i+1];
			vec[i]=res[i];
		}
	}
	foi1(n)cout<<res[i]<<" ";
	cout<<endl;
	
}