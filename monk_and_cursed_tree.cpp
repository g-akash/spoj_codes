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
	int data;
	node *left, *right;
};

node* insert(node *n, int data)
{
	if(n==NULL)
	{
		node *nn = new node();
		nn->data = data;
		return nn;
	}
	if(n->data==data)return n;
	if(n->data>data)
	{
		n->left = insert(n->left,data);
		return n;
	}
	else n->right = insert(n->right,data);
	return n;
}

vi get_path(node *n, int val)
{

	vi ans;
	node *tmp=n;
	ans.pb(tmp->data);
	while(tmp->data!=val)
	{
		if(tmp->data<val)
		{
			tmp=tmp->right;
		}
		else
			tmp=tmp->left;
		ans.pb(tmp->data);

	}
	//foi(ans.size())cout<<ans[i]<<" ";
	return ans;

}


int main()
{
	int n,data;
	node *root;
	cin>>n;
	foi(n)
	{
		cin>>data;
		root = insert(root,data);

	}
	int a,b,pos;
	cin>>a>>b;
	vi p1=get_path(root,a),p2=get_path(root,b);
	foi(p1.size())
	{
		if(p1[i]==p2[i])
		{
			pos=i;
		}
		else break;
		if(i==p2.size()-1)break;
	}
	vi tot_path;
	for(int i=pos;i<p1.size();i++)
	{
		tot_path.pb(p1[i]);
	}
	for(int i=pos;i<p2.size();i++)
	{
		tot_path.pb(p2[i]);
	}
	sort(tot_path.begin(),tot_path.end());
	cout<<tot_path[tot_path.size()-1]<<endl;


}