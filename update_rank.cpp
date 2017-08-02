#include <iostream>
#include <vector>
//#include <unordered_map>
#include <string>
#include <math.h>
//#include <map>
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


class node
{
public:
	int val,l_childs;
	node *left, *right;
	node()
	{
		left = NULL;
		right = NULL;
		l_childs=0;
	}
};

node * root;


int insert(node *rt,int seen, int val)
{
	//cout<<rt->val<<" values"<<endl;
	if(val<rt->val)
	{
		if(rt->left!=NULL)
		{
			rt->l_childs++;
			return insert(rt->left,seen,val);
		}
		else
		{
			node * nn = new node();
			rt->l_childs++;
			nn->val=val;
			rt->left=nn;
			return seen;
		}
	}
	else if(val>rt->val)
	{
		if(rt->right!=NULL)
		{
			return insert(rt->right,seen+rt->l_childs+1,val);
		}
		else
		{
			node * nn = new node();
			nn->val = val;
			rt->right = nn;
			return seen+rt->l_childs+1;
		}
	}

}



int main()
{
	int n;
	cin>>n;
	root = NULL;
	int val;
	cin>>val;
	root = new node();
	root->val=val;
	cout<<1<<endl;
	foi1(n-1)
	{
		cin>>val;
		int ans= insert(root,0,val);
		cout<<i+1-ans<<endl;
	}

}