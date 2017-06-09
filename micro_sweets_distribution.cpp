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
	int t;
	cin>>t;
	while(t--)
	{
		int n,m,sx,sy,dx,dy;
		cin>>n>>m>>sx>>sy>>dx>>dy;
		if(sx==1&&sy==1)
		{
			
			if(dx%2==1)
			{
				if(dx==n&&dy==m)
				{
					cout<<"Over"<<endl;
					continue;
				}
				if(dy==m)
				{
					cout<<"Back"<<endl;
					continue;
				}
				cout<<"Right"<<endl;

			}
			else
			{
				if(dx==n&&dy==1)
				{
					cout<<"Over"<<endl;
					continue;
				}
				if(dy==1)
				{
					cout<<"Back"<<endl;
					continue;
				}
				cout<<"Left"<<endl;
			}
		}
		else if(sx==1&&sy==m)
		{
			
			if(dx%2==1)
			{
				if(dx==n&&dy==1)
				{
					cout<<"Over"<<endl;
					continue;
				}
				if(dy==1)
				{
					cout<<"Back"<<endl;
					continue;
				}
				cout<<"Left"<<endl;

			}
			else
			{
				if(dx==n&&dy==m)
				{
					cout<<"Over"<<endl;
					continue;
				}
				if(dy==m)
				{
					cout<<"Back"<<endl;
					continue;
				}
				cout<<"Right"<<endl;
			}
		}
		else if(sx==n&&sy==1)
		{
				
			if((n-dx)%2==0)
			{
				if(dx==1&&dy==m)
				{
					cout<<"Over"<<endl;
					continue;
				}
				if(dy==m)
				{
					cout<<"Front"<<endl;
					continue;
				}
				cout<<"Right"<<endl;

			}
			else
			{
				if(dx==1&&dy==1)
				{
					cout<<"Over"<<endl;
					continue;
				}
				if(dy==1)
				{
					cout<<"Front"<<endl;
					continue;
				}
				cout<<"Left"<<endl;
			}
		}
		else if(sx==n&&sy==m)
		{
				
			if((n-dx)%2==1)
			{
				if(dx==1&&dy==m)
				{
					cout<<"Over"<<endl;
					continue;
				}
				if(dy==m)
				{
					cout<<"Front"<<endl;
					continue;
				}
				cout<<"Right"<<endl;

			}
			else
			{
				if(dx==1&&dy==1)
				{
					cout<<"Over"<<endl;
					continue;
				}
				if(dy==1)
				{
					cout<<"Front"<<endl;
					continue;
				}
				cout<<"Left"<<endl;
			}
		}
	}
}