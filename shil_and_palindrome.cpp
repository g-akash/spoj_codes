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


int tree[26][100005];
char str[100005];


void insert(int tr, int pos, int val)
{
	int idx = pos;
	while(idx<100005)
	{
		tree[tr][idx]+=val;
		idx +=(idx&-idx);
	}
	return;
}


int sum(int tr, int r)
{
	int idx = r;
	int ans = 0;
	while(idx>0)
	{
		ans+=tree[tr][idx];
		idx-=(idx&-idx);
	}
	return ans;
}

int get_sum(int tr, int l, int r)
{
	if(l==0)
	{
		return sum(tr,r);
	}
	else return sum(tr,r)-sum(tr,l-1);
}


int main()
{
	int n,q;
	cin>>n>>q;
	string s;
	cin>>s;
	foi(s.length())
	{
		str[i+1]=s[i];
		insert((int)s[i]-97,i+1,1);
	}
	foi(q)
	{
		int typ;
		cin>>typ;
		if(typ==1)
		{
			int l;
			char ch;
			cin>>l>>ch;
			int prev = (int)str[l]-97;
			str[l] = ch;
			insert(prev,l,-1);
			insert((int)ch-97,l,1);
		}
		else
		{
			int l,r;
			cin>>l>>r;
			int odd=0;
			foi(26)
			{
				if(get_sum(i,l,r)%2==1)odd+=1;
			}
			if((r-l+1)%2==0)
			{
				if(odd==0)cout<<"yes"<<endl;
				else cout<<"no"<<endl;
			}
			else
			{
				if(odd==1)cout<<"yes"<<endl;
				else cout<<"no"<<endl;
			}
		}
	}

}