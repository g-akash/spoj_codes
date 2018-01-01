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

char s[5005];
umm(ll,bool) *um;
vll mins;
ll len;

bool is_palindrome(ll x, ll y)
{
	 
	if(x>=y)return true;
	if(y==x+1)return s[x]==s[y];
	if((*um).find(x*(ll)100000+y)!=(*um).end())return (*um)[x*(ll)100000+y];
	bool ans = false;
	if(s[x]==s[y])if(is_palindrome(x+1,y-1))ans=true;
	(*um)[x*(ll)100000+y]=ans;
	return ans;
}

ll get_ans(int x)
{
	if(x>=len)return 0;
	if(mins[x]>0)return mins[x];
	ll mans = 10000000;
	for(ll i=x;i<len;i++)
	{
		if(is_palindrome(x,i))
		{
			ll var = get_ans(i+1);
			if(var+1<mans)mans=var+1;
		}
	}
	mins[x]=mans;
	return mans;
}


int main()
{
	ll t;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&len);
		scanf("%s",s);
		um = new umm(ll,bool); 
		mins.clear();
		mins.resize(len);
		foi(len)mins[i]=0;
		mins[len-1]=1;
		printf("%lld\n",get_ans(0));//<<endl;

	}
}