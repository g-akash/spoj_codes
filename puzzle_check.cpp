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
	int n,m;
	cin>>n>>m;
	vector<string> vec(n);
	foi(n)
	{
		cin>>vec[i];
	}
	int sx=-1,sy=-1,ex=-1,ey=-1;
	bool done=true;
	foi(n)
	{
		foj(m)
		{
			if(vec[i][j]=='X')
			{
				sx=i;sy=j;
				done=false;
				break;
			}
		}
		if(!done)break;
	}
	done=true;
	for(int i=n-1;i>=0;i--)
	{
		for(int j=m-1;j>=0;j--)
		{

			if(vec[i][j]=='X')
			{
				ex=i;ey=j;
				done=false;
				break;
			}
		}
		if(!done)break;
	}
	//cout<<sx<<sy<<ex<<ey<<endl;
	foi(n)
	{
		foj(m)
		{
			if(vec[i][j]=='X'&&(i<sx||i>ex||j<sy||j>ey))
			{
				cout<<"NO"<<endl;
				return 0;
			}
			if(i>=sx&&i<=ex&&j>=sy&&j<=ey&&vec[i][j]=='.')
			{
				cout<<"NO"<<endl;
				return 0;
			}
		}
	}
	cout<<"YES"<<endl;
}