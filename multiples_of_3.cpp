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

class node{
public:
	int l,r;
	int r0,r1,r2;
	int add;
	node()
	{
		r0=0;
		r1=0;
		r2=0;
		add=0;
	}
	node(int x,int y)
	{
		l=x;
		r=y;
		r0=1;
		r1=0;
		r2=0;
		add=0;
	}
};

vector<vector<node> > tree;
int n,q;


vector<int> incr(int x, int y, int a, int b)
{
	node nd = tree[x][y];
	vi ans(3,0);
	if(nd.l>b)return ans;
	if(nd.r<a)return ans;
	if(nd.l==a&&nd.r==b)
	{
		vi vals(3,0);
		vals[0]=nd.r0;
		vals[1]=nd.r1;
		vals[2]=nd.r2;
		int tmp = nd.r0;
		nd.r0=nd.r2;
		nd.r2=nd.r1;
		nd.r1=tmp;
		vals[0]=nd.r0-vals[0];
		vals[1]=nd.r1-vals[1];
		vals[2]=nd.r2-vals[2];
		nd.add+=1;
		tree[x][y]=nd;
		return vals;

	}
	node rt = tree[x+1][2*y+1];
	node lf = tree[x+1][2*y];
	
	if(rt.l<=b)
	{
		vi rans = incr(x+1,2*y+1,rt.l,b);
		if(nd.add%3==0)
		{	
			ans[0]+=rans[0];
			ans[1]+=rans[1];
			ans[2]+=rans[2];
		}
		else if(nd.add%3==1)
		{
			ans[0]+=rans[2];
			ans[1]+=rans[0];
			ans[2]+=rans[1];
		}
		else
		{
			ans[0]+=rans[1];
			ans[1]+=rans[2];
			ans[2]+=rans[0];
		}
	}
	if(lf.r>=a)
	{
		vi lans = incr(x+1,2*y,a,lf.r);
		if(nd.add%3==0)
		{	
			ans[0]+=lans[0];
			ans[1]+=lans[1];
			ans[2]+=lans[2];
		}
		else if(nd.add%3==1)
		{
			ans[0]+=lans[2];
			ans[1]+=lans[0];
			ans[2]+=lans[1];
		}
		else
		{
			ans[0]+=lans[1];
			ans[1]+=lans[2];
			ans[2]+=lans[0];
		}
		
	}
	nd.r0+=ans[0];
	nd.r1+=ans[1];
	nd.r2+=ans[2];
	tree[x][y]=nd;
	return ans;

}


int get_res(int x, int y, int a, int b, int add)
{
	// cout<<"coming inside"<<endl;
	// cout<<x<<" "<<y<<endl;
	node nd = tree[x][y];
	add%=3;
		if(add==0)
			{}
		else if(add==1)
		{
			int tmp = nd.r2;
			nd.r2=nd.r1;
			nd.r1=nd.r0;
			nd.r0=tmp;
		}
		else
		{
			int tmp = nd.r0;
			nd.r0=nd.r1;
			nd.r1 = nd.r2;
			nd.r2=tmp;
		}

	nd.add+=add;
	if(nd.r<a){tree[x][y]=nd;return 0;}
	if(nd.l>b){tree[x][y]=nd;return 0;}
	if(nd.l==a&&nd.r==b)
	{
		tree[x][y]=nd;
		return nd.r0;
	}
	node rt = tree[x+1][2*y+1];
	node lf = tree[x+1][2*y];
	int ans = 0;
	if(rt.l<=b)
	{
		if(rt.l>=a)ans += get_res(x+1,2*y+1,rt.l,b,nd.add);
		else ans+=get_res(x+1,2*y+1,a,b,nd.add);
	}
	else get_res(x+1,2*y+1,rt.r+1,rt.l-1,nd.add);
	if(lf.r>=a)
	{
		
		if(lf.r<=b)ans += get_res(x+1,2*y,a,lf.r,nd.add);
		else ans+=get_res(x+1,2*y,a,b,nd.add);
	}
	else get_res(x+1,2*y,lf.r+1,lf.l-1,nd.add);
	nd.add=0;
	tree[x][y]=nd;
	return ans;
}

int main()
{
	
	cin>>n>>q;
	int num=1;
	vector<node> vec(1);
	tree.pb(vec);
	while(num<n)
	{
		num*=2;
		vec.resize(num);
		tree.pb(vec);
	}
	int leaf = tree.size()-1;

	foi(tree[leaf].size())
	{
		node nd(i,i);
		tree[leaf][i]=nd;
	}
	node n1,n2;
	for(int i=leaf-1;i>=0;i--)
	{
		for(int j=0;j<tree[i].size();j++)
		{
			n1 = tree[i+1][2*j];
			n2 = tree[i+1][2*j+1];
			node nd(n1.l,n2.r);
			nd.r0=n1.r0+n2.r0;
			nd.r1=n1.r1+n2.r1;
			nd.r2=n1.r2+n2.r2;
			nd.add=0;
			tree[i][j]=nd;
		}
	}
	int typ,a,b;
	foi(q)
	{
		
		cin>>typ>>a>>b;
		if(typ==0)
		{
			incr(0,0,a,b);
		}
		else
		{
			int ans = get_res(0,0,a,b,0);
			cout<<ans<<endl;
		}
		// foj(tree.size())
		// {

		// 	for(int k=0;k<tree[j].size();k++)cout<<tree[j][k].add<<tree[j][k].r0<<" ";cout<<endl;
		// }
	}

}