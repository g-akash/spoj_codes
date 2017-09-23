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


vi tree(100005),arr(100005);


void insert(int a, int b)

{
	arr[a] = b;
	
	int idx = a;
	if(b%2==1)return;
	while(idx<100005)
	{
		tree[idx]+=1;
		idx +=(idx&-idx);
	}
	return;

}

void update(int a, int b)
{
	if(arr[a]%2==b%2){arr[a]=b;return;}
	if(b%2==0)
	{
		arr[a]=b;
		int idx = a;
		while(idx<100005)
		{
			tree[idx]+=1;
			idx+=(idx&-idx);
		}
	}
	else
	{
		arr[a]=b;
		int idx = a;
		while(idx<100005)
		{
			tree[idx]-=1;
			idx+=(idx&-idx);
		}
	}
	return;
}

int get_sum(int x)
{
	int ans = 0;
	int idx = x;
	while(idx>0)
	{
		ans+=tree[idx];
		idx-=(idx&-idx);
	}
	return ans;
}


int main()
{
	int n,var;
	cin>>n;
	foi1(n)
	{
		cin>>var;
		insert(i,var);
	}
	int q;
	cin>>q;
	while(q--)
	{
		int a,b,c;
		cin>>a>>b>>c;
		if(a==0)
		{
			update(b,c);
		}
		else if(a==1)
		{
			int ans = 0;
			if(b==0)
			{
				ans=get_sum(c);
			}
			else 
			{
				ans = get_sum(c)-get_sum(b-1);
			}
			cout<<ans<<endl;
		}
		else
		{
			int ans = 0;
			if(b==0)
			{
				ans=get_sum(c);
			}
			else 
			{
				ans = get_sum(c)-get_sum(b-1);
			}
			ans = (c-b+1)-ans;
			cout<<ans<<endl;
		}
	}
}