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
#include <stdio.h>

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
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		vi vec(n),walks(n);
		foi(n)
		{
			scanf("%d",&vec[i]);
			walks[i]=i-vec[i];
		}
		sort(walks.begin(),walks.end());
	
		//cout<<endl;
		foi(n)
		{
			int num;
			// get nums <= i in walks
			int x=0,y=n;
			while(y-x>1)
			{
				int mid = (x+y)/2;
				if(walks[mid]<=i)x=mid;
				else y=mid;
			}
			num = x+1;
			//cout<<walks[i]<<" wn "<<num<<" x "<<x<<endl;
			if(i!=n-1)printf("%d ",num-vec[i]);
			else printf("%d",num-vec[i]);
		}
		printf("\n");

	}
}