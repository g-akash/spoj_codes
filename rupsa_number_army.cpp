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
		int n;
		cin>>n;
		vi vec(n);
		mm(int,int) m;
		foi(n)
		{
			cin>>vec[i];
		}
		sort(vec.begin(),vec.end());
		int mn=0,mx=0;
		for(int i=0;i<vec.size();)
		{
			if(i==int(vec.size())-1)
			{
				mn+=1;
				i+=1;
				continue;
			}
			else if(i==int(vec.size())-2)
			{
				if(vec[i+1]==vec[i]+1)
				{
					mn+=1;
					i+=2;
					continue;
				}
				else
				{
					mn+=1;
					i+=1;
					continue;
				}
			}
			else
			{
				if(vec[i+1]==vec[i]+1)
				{
					if(vec[i+2]==vec[i+1]+1)
					{
						mn+=1;
						i+=3;
					}
					else
					{
						mn+=1;
						i+=2;
					}
				}
				else
				{
					mn+=1;
					i+=1;
				}
			}
		}

		//cout<<vec.size()<<endl;
		for(int i=0;i<vec.size();)
		{
			//cout<<i<<endl;
			mx+=1;
			if(i<int(vec.size())-1)
			{
				if(vec[i+1]==vec[i]+1)
				{
					i+=2;
				}
				else
				{
					i+=1;
				}
			}
			else
			{
				i+=1;
			}
			//cout<<i<<endl;
		}
		cout<<mn<<" "<<mx<<endl;

	}
}