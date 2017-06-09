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
	int n,q;
	cin>>n>>q;
	string s;
	cin>>s;
	int data[n+1][26];
	foi(n+1)
	{
		foj(26)data[i][j]=0;
	}
	s = "0"+s;
	foi1(n)
	{
		foj(26)
		data[i][j]=data[i-1][j];
		data[i][int(s[i])-97]+=1;
	}
	foi(q)
	{
		int l,r,k;
		cin>>l>>r>>k;
		int var[26];
		foj(26)var[j]=data[r][j]-data[l-1][j];
		bool done = false;
		foj(26)
		{
			if(k-var[j]<=0)
			{
				cout<<char(j+97)<<endl;
				done=true;
				break;
			}
			k-=var[j];
		}
		if(!done)
		{
			cout<<"Out of range"<<endl;
		}
	}
}