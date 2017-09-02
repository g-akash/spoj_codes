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
	int n,b,ball;
	while(cin>>n>>b)
	{
		if(n==0&&b==0)break;
		vi vec(n+1);
		vec[0]=1;
		vi balls(n+1);
		foi(b)
		{
			cin>>ball;
			balls[ball]=1;
		}
		for(int i=0;i<=n;i++)
		{
			if(!balls[i])continue;
			for(int j=i;j<=n;j++)
			{
				if(!balls[j])continue;
				vec[j-i]=1;
			}
		}
		int ans = 0;
		foi(n+1)ans+=vec[i];
		if(ans==n+1)cout<<"Y"<<endl;
		else cout<<"N"<<endl;

	}
}