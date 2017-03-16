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
	int n;
	int dist,currpos=0;
	string dir;
	cin>>n;
	foi(n)
	{
		cin>>dist>>dir;
		if(dir=="South")
		{
			currpos+=dist;
		}
		else if(dir=="North")
		{
			currpos-=dist;
		}
		else if(dir=="East"||dir=="West")
		{
			if(currpos==0||currpos==20000)
			{
				cout<<"NO"<<endl;
				return 0;
			}
		}
		if(currpos>20000||currpos<0)
		{
			cout<<"NO"<<endl;
			return 0;
		}
	}
	if(currpos==0)
	{
		cout<<"YES"<<endl;
	}
	else cout<<"NO"<<endl;
}