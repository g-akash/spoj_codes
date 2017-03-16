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


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		vector<string> vec(n);
		foi(n)
		{
			cin>>vec[i];
		}
		bool can=true;
		for(int i=0;i<n-1&&can;i++)
		{
			for(int j=0;j<m-1&&can;j++)
			{
				if(vec[i][j]=='A'&&vec[i][j+1]=='W')
				{
					can=false;
					continue;
				}
				if(vec[i][j]=='W'&&vec[i][j+1]=='A')
				{
					can=false;
					continue;
				}
				if((vec[i][j]=='W'||vec[i][j]=='B')&&vec[i+1][j]=='A')
				{
					can=false;
					continue;
				}
				if((vec[i][j]=='B')&&vec[i+1][j]=='W')
				{
					can=false;
					continue;
				}
			}
		}
		for(int i=0;i<n-1&&can;i++)
		{
			int j=m-1;
			if((vec[i][j]=='W'||vec[i][j]=='B')&&vec[i+1][j]=='A')
			{
				can=false;
				continue;
			}
			if((vec[i][j]=='B')&&vec[i+1][j]=='W')
			{
				can=false;
				continue;
			}

		}
		foi(n)
		{
			if(vec[i][0]=='W'||vec[i][m-1]=='W')can=false;
		}
		foj(m)
		{
			if(vec[n-1][j]=='W')can=false;
		}
		if(can)cout<<"yes"<<endl;
		else cout<<"no"<<endl;
	}
}