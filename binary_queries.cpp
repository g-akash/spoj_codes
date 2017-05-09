#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <math.h>
#include <map>
#include <queue>
#include <algorithm>
#include <list>
#include <stdio.h>

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
	int n,q;
	scanf("%d %d",&n,&q);
	vi vec(n+1);
	foi1(n)scanf("%d",&vec[i]);
	foi(q)
	{
		int typ,l,r;
		scanf("%d %d",&typ,&l);
		if(!typ)
		{
			scanf("%d",&r);
			if(vec[r]==1)printf("ODD\n");
			else printf("EVEN\n");
		}
		else
		{
			vec[l] = (vec[l]+1)%2;
		}
	}
}