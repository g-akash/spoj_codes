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

int get_day_int(string day)
{
	if(day=="mon")return 0;
	if(day=="tues")return 1;
	if(day=="wed")return 2;
	if(day=="thurs")return 3;
	if(day=="fri")return 4;
	if(day=="sat")return 5;
	if(day=="sun")return 6;
	return 0;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int numdays;
		string firstday;
		cin>>numdays;
		cin>>firstday;
		int day = get_day_int(firstday);
		int curr = day;
		int strt = 1;
		//cout<<curr<<endl;
		vi ans(7);
		foi(7)
		{
			if(strt+28<=numdays)
			{
				ans[curr]=5;
			}
			else ans[curr]=4;
			curr=(curr+1)%7;
			strt+=1;
		}
		foi(7)cout<<ans[i]<<" ";cout<<endl;
	}
}