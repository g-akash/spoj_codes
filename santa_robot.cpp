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
#define umm(x,y) unordered_map<x,y >
#define pb push_back
#define foi(n) for(int i=0;i<n;i++)
#define foj(n) for(int j=0;j<n;j++)
#define foi1(n) for(int i=1;i<=n;i++)
#define vi vector<int>
#define vvi vector<vi >
#define vll vector<ll>
#define vvll vector<vll >
#define si size()

bool opposite(int vec[], int x)
{
	char c1=char(x),c2;
	if(vec[int('R')]==1&&c1=='L')return true;
	if(vec[int('L')]==1&&c1=='R')return true;
	if(vec[int('U')]==1&&c1=='D')return true;
	if(vec[int('D')]==1&&c1=='U')return true;
	return false;
}


int main()
{
	int vec[200],n,ans=0,count=0;
	string s;
	cin>>n>>s;
	foi(n)
	{
		if(count==0)
		{
			count++;
			vec[int(s[i])]=1;
		}
		else if(count==1)
		{
			if(opposite(vec,int(s[i])))
			{
				ans++;
				count=1;
				vec[int('U')]=0;
				vec[int('L')]=0;
				vec[int('R')]=0;
				vec[int('D')]=0;
				vec[int(s[i])]=1;
			}

			else if(vec[int(s[i])]==1)
			{
				continue;
			}
			else
			{
				vec[int(s[i])]=1;
				count++;
			}
		}
		else if(count==2)
		{
			if(vec[int(s[i])]==1)
			{
				continue;
			}
			else
			{
				ans++;
				count=1;
				vec[int('U')]=0;
				vec[int('L')]=0;
				vec[int('R')]=0;
				vec[int('D')]=0;
				vec[int(s[i])]=1;
			}
		}
	}
	if(count>0)ans++;
	cout<<ans<<endl;
}