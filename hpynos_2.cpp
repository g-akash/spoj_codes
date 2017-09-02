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


int get_sum_sq_digits(int x)
{
	int ans = 0, unit_digit;
	while(x!=0)
	{
		unit_digit = x%10;
		x/=10;
		ans += unit_digit*unit_digit;

	}
	return ans;
}

int happy_steps(int x)
{
	umm(int,bool) um;
	int ans = 0;
	while(true)
	{
		if(x==1){return ans;}
		if(um.find(x)!=um.end())return -1;
		um[x]=true;
		x = get_sum_sq_digits(x);
		ans+=1;
	}
}



int main()
{
	int t;
	scanf("%d",&t);
	int var;
	umm(int,int) cache;
	foi1(1000)
	{
		cache[i] = happy_steps(i);
	}
	while(t--)
	{
		scanf("%d",&var);
		int ans = 0;
		var = get_sum_sq_digits(var);
		if(cache[var]==-1)printf("-1\n");
		else printf("%d\n",cache[var]+1);
	}
}