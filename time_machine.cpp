#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <math.h>
#include <algorithm>

using namespace std;


#define ll long long int
#define umm(x,y) unordered_map<x,y >
#define pb push_back
#define foi(n) for(int i=0;i<n;i++)
#define foj(n) for(int j=0;j<n;j++)
#define foi1(n) for(int i=1;i<=n;i++)
#define vi vector<int>
#define vvi vector<vi >
#define si size()


class oper
{
public:
	int a,t,x;
};

umm(int,int) um;

bool comp(oper p, oper q)
{
	if(p.t<q.t)return true;
	return false;
}

vector<oper> operate(vector<oper> vec)
{
	foi(vec.size())
	{
		if(vec[i].a==1)
		{
			if(um.find(vec[i].x)==um.end())um[vec[i].x]=1;
			else
				um[vec[i].x]++;
		}
		else if(vec[i].a==2)
		{
			um[vec[i].x]--;
		}
		else
		{
			if(um.find(vec[i].x)==um.end())cout<<0<<endl;
			else cout<<um[vec[i].x]<<endl;
			vector<oper>::iterator beg = vec.begin()+i+1;
			vector<oper> ans(beg,vec.end());
			return ans;

		}
	}
}

int main()
{
	vector<oper> vec;
	int q;
	oper op;
	cin>>q;
	foi(q)
	{
		cin>>op.a>>op.t>>op.x;
		vec.pb(op);
		if(op.a==3)
		{
			sort(vec.begin(),vec.end(),comp);
			vec=operate(vec);
			//vec.clear();
		}
	}
}