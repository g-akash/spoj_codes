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


vi orig, cpy,final;

class node
{
	public:
		int data;
		node *left, *right;
		node()
		{
			data = 0;
			left = NULL;
			right = NULL;
		}
};

node* make_tree(int a, int b)
{
	//cout<<a<<" "<<b<<endl;
	if(a>b)return NULL;
	if(a==b)
	{
		node *nn = new node();
		nn->data=cpy[a];
		return nn;
	}

	int mid,diff = (b-a+1),cdiff = 2,curr = 1;
	while(curr+cdiff<diff)
	{
		curr+=cdiff;
		cdiff*=2;
	}
	int rest = (diff-curr);
	if(rest<=cdiff/2){mid = a+rest+(curr-1)/2;}
	else {mid = a+(cdiff/2)+(curr-1)/2;}

	
	node *nn = new node();
	nn->data = cpy[mid];
	nn->left = make_tree(a,mid-1);
	nn->right = make_tree(mid+1,b);
	return nn;
}

// int get_size(node *n)
// {
// 	if(n==NULL)return 0;
// 	int ans=get_size(n->left);
// 	ans+=get_size(n->right);
// 	ans+=1;
// 	return ans;
// }


// void tree_traversal(node *n)
// {
// 	cout<<"I am at the value "<<n->data<<endl;
// 	int lsize = get_size(n->left), rsize = get_size(n->right);
// 	cout<<lsize<<" "<<rsize<<endl;
// 	if(rsize>lsize)cout<<"problem at this node. left has more childs than right"<<endl;
// 	if(n->left!=NULL)tree_traversal(n->left);
// 	if(n->right!=NULL)tree_traversal(n->right);
// 	return;
// }


void make_vector(node *n, int pos)
{
	//cout<<pos<<endl;
	final[pos]=n->data;
	if(n->left!=NULL)make_vector(n->left,2*pos+1);
	if(n->right!=NULL)make_vector(n->right,2*pos+2);
	return ;
}




int main()
{
	int n;
	cin>>n;
	orig.resize(n), cpy.resize(n);
	final.resize(n);
	//cout<<final.size()<<" kk"<<endl;
	foi(n)
	{
		cin>>orig[i];
		cpy[i]=orig[i];
	}
	sort(cpy.begin(),cpy.end());
	node *root;
	root = make_tree(0,cpy.size()-1);
	//tree_traversal(root);
	//cout<<root->data<<endl;
	make_vector(root,0);

	umm(int,int) um;
	int count=0,ans=0;
	foi(n)
	{
		if(final[i]!=orig[i])
		{
			um[final[i]]=orig[i];
			count++;
		}
	}
	while(count!=0)
	{
		//cout<<count<<endl;
		vi tmp;
		umm(int,int)::iterator it=um.begin();
		tmp.pb(it->first);
		it = um.find(it->second);
		while(it->first!=tmp[0])
		{
			tmp.pb(it->first);
			it = um.find(it->second);
		}
		foi(tmp.size())um.erase(tmp[i]);
		ans+=(tmp.size()-1);
		count-=tmp.size();


	}
	cout<<ans<<endl;

}