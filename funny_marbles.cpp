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


int n,q;
int countt=0;

class node
{
public:
	int value;
	int left,right;
};





void build_tree(vector<vector<node> > &vec)
{
	for(int i=vec.size()-2;i>=0;i--)
	{
		for(int j=0;j<vec[i].size();j++)
		{
			vec[i][j].value=vec[i+1][2*j].value+vec[i+1][2*j+1].value;
			vec[i][j].left = vec[i+1][2*j].left;
			vec[i][j].right = vec[i+1][2*j+1].right;
		}
	}
	return;
}


void add_marbles(int a, int b, vector<vector<node> > &vec)
{
	int ind = a;
	for(int i=countt-1;i>=0;i--)
	{
		vec[i][ind].value+=b;
		ind/=2;
	}
	return;
}


int get_sum(int a, int b, int r, int c, vector<vector<node> > &vec)
{
	//cout<<a<<" "<<b<<" "<<r<<" "<<c<<endl;
	int le = vec[r][c].left;
	int ri = vec[r][c].right;
	if(le==a&&ri==b)return vec[r][c].value;
	if(a<=vec[r+1][2*c].right)
	{
		int ans = 0;
		if(b<=vec[r+1][2*c].right)
		{
			ans+=get_sum(a,b,r+1,2*c,vec);
		}
		else
		{
			ans+=get_sum(a,vec[r+1][2*c].right,r+1,2*c,vec);
			ans+=get_sum(vec[r+1][2*c+1].left,b,r+1,2*c+1,vec);
		}
		return ans;
	}
	else
	{
		return get_sum(a,b,r+1,2*c+1,vec);
	}
}


int main()
{
	vector<vector<node> > vec;
	cin>>n>>q;
	countt = 0;
	int tmp = n;
	while(tmp>0)
	{
		countt+=1;
		tmp/=2;
	}
	vec.resize(countt);
	int curr = 1;
	for(int i=0;i<vec.size();i++)
	{
		vec[i].resize(curr);
		curr*=2;
	}
	foi(vec[countt-1].size())
	{
		vec[countt-1][i].left=i;
		vec[countt-1][i].right=i;
		vec[countt-1][i].value=0;
	}
	foi(n)
	{
		cin>>vec[countt-1][i].value;
	}
	build_tree(vec);

	foi(q)
	{
		char ch;
		int a,b;
		cin>>ch>>a>>b;
		if(ch=='S')
		{
			cout<<get_sum(a,b,0,0,vec)<<endl;
		}
		else if(ch=='G')
		{
			add_marbles(a,b,vec);
		}
		else
		{
			add_marbles(a,-b,vec);
		}
	}

}