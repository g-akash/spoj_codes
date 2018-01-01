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
#include <stdlib.h>
#include <cstring>

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

char s1[100005],s2[100005];
int a,b,k;
int len1,len2;
umm(ll,int) um;

int get_min(int x, int y, int lef)
{
	if(lef<0)return 100000000;
	if(x>=len1)
	{
		int add = len2-y;
		if(add*a<=lef)return add*a;
		else return 100000000;
	}
	if(y>=len2)
	{
		int rem = len1-x;
		if(rem*a<=lef)return rem*a;
		return 100000000;
	}
	if(um.find((ll)x*1000000000+(ll)y*1000+lef)!=um.end())return um[(ll)x*1000000000+(ll)y*1000+lef];
	if(s1[x]==s2[y])return get_min(x+1,y+1,lef);
	int ans1=100000000,ans2=100000000,ans3=100000000;
	if(lef>=a) ans1 = get_min(x+1,y,lef-a)+a;
	if(lef>=a) ans2 = get_min(x,y+1,lef-a)+a;
	if(lef>=b) ans3 = get_min(x+1,y+1,lef-b)+b;
	int ans = min(ans1,min(ans2,ans3));
	um[(ll)x*1000000000+(ll)y*1000+lef]=ans;
	return ans;

}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		
		scanf("%s %s",s1,s2);
		scanf("%d %d %d",&a,&b,&k);
		len1 = strlen(s1);
		len2 = strlen(s2);
		//cout<<s1<<" "<<s2<<" "<<a<<b<<k<<endl;
		um.clear();
		if(a==0)
		{
			cout<<0<<endl;
		}
		else if(b==0)
		{
			int val = abs(len1-len2)*a;
			if(val<=k)
			{
				cout<<val<<endl;
			}
			else cout<<-1<<endl;
		}
		else
		{
			int ans = get_min(0,0,k);
			if(ans>k)cout<<-1<<endl;
			else cout<<ans<<endl;
		}

	}
}