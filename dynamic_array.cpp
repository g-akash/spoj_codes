#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <math.h>
#include <map>
#include <queue>
#include <algorithm>
#include <list>

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
	cin>>n>>q;
	vi vec(n),curr(n),mx(n);
	foi(n)cin>>vec[i];
	int cur=1,mxt=1;
	curr[0]=1;mx[0]=1;
	foi1(n-1)
	{
		if(vec[i]>vec[i-1])
		{
			cur++;
			mxt=max(mxt,cur);
			curr[i]=cur;
			mx[i]=mxt;
		}
		else
		{
			cur=1;
			mxt=max(mxt,cur);
			curr[i]=cur;
			mx[i]=mxt;
		}
	}
	int endpos=n-1;
	int typ,val;
	foi(q)
	{
		cin>>typ;
		//cout<<typ<<" "<<val<<endl;
		foi(vec.size())cout<<mx[i]<<" ";cout<<endl;
		foi(vec.size())cout<<curr[i]<<" ";cout<<endl;
		if(typ==1)
		{
			cin>>val;
			vec.resize(vec.size()+1);
			curr.resize(curr.size()+1);
			mx.resize(mx.size()+1);
			endpos+=1;
			vec[endpos]=val;
			if(endpos>0)
			{
				if(vec[endpos]>vec[endpos-1])
				{
					cur++;
					mxt=max(mxt,cur);
					curr[endpos]=cur;
					mx[endpos]=mxt;
				}
				else
				{
					cur=1;
					mxt=max(mxt,cur);
					curr[endpos]=cur;
					mx[endpos]=mxt;
				}
			}
			else
			{
				cur=1;
				mxt=1;
			}
		}
		else
		{
			vec.resize(vec.size()-1);
			curr.resize(curr.size()-1);
			mx.resize(mx.size()-1);
			endpos--;
			cur=curr[endpos];
			mxt=mx[endpos];
		}
		cout<<mxt<<endl;
	}
}
