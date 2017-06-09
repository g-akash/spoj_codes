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

class node
{
public:
	int data,count;
	node *left, *right;
	node()
	{
		count=1;
		left = NULL;
		right = NULL;
	}
};

void insert(node * n,int data)
{
	//if(data==n->data){n->count++;return;}
	if(data<=n->data)
	{
		if(n->left==NULL)
		{
			node *nn = new node();
			nn->data = data;
			n->left = nn;
			return;
		}
		insert(n->left,data);
		return;
	}
	else
	{
		if(n->right==NULL)
		{
			node *nn = new node();
			nn->data = data;
			n->right = nn;
			return;
		}
		insert(n->right,data);
		return;
	}
	return;
}

int get_height(node *n)
{
	if(n==NULL)return 0;
	int l=get_height(n->left),r=get_height(n->right);
	return max(l,r)+(n->count);
}


int main()
{
	int n,var;
	cin>>n;
	cin>>var;
	node *tree = new node();
	tree->data = var;
	foi1(n-1)
	{
		cin>>var;
		insert(tree,var);
	}
	cout<<get_height(tree)<<endl;
}