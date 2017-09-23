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



class BIT
{
private:
	int sum(int r)
	{
		int ans = 0;
		while(r!=0)
		{
			ans+=tree[r];
			r -=(r&-r);
		}
		return ans;
	}

public:
	vi tree;
	BIT(vi values)
	{
		vi freq(1000001);
		foi(values.size())
		{
			freq[values[i]]+=1;
		}
		vi cf(1000001);
		cf[0]=0;
		foi(1000001)
		{
			cf[i]=cf[i-1]+freq[i];
		}
		tree.resize(1000001);
		foi(1000001)
		{
			int idx = i;
			int strt = idx-(idx&-idx)+1;
			if(strt==0)tree[idx]=cf[idx];
			else tree[idx] = cf[idx]-cf[strt-1];
		}
		return;
	}

	void insert(int val, int freq)
	{
		while(val<=1000000)
		{
			tree[val]+=freq;
			val+=(val&-val);
		}
	}
	int range_sum(int l, int r)
	{
		if(l==0)
		{
			return sum(r);
		}
		else
		{
			return sum(r)-sum(l-1);
		}
	}

};


int main()
{
	vi values;
	int n,value;
	cin>>n;
	foi(n)
	{
		cin>>value;
		values.pb(value);
	}
	BIT bit(values);
	foi1(18)cout<<bit.tree[i]<<endl;
	int q;
	cin>>q;
	int typ,val,freq,l,r;
	foi(q)
	{
		cin>>typ;
		if(typ==1)
		{
			cin>>val>>freq;
			bit.insert(val,freq);
		}
		else if(typ==2)
		{
			cin>>l>>r;
			cout<<bit.range_sum(l,r)<<endl;
		}
	}
}