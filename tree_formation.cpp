#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
vector<int> v;

class node
{
	public:
	int data;
	node* left;
	node*right;
};

node* tree_formation(int a , int b)
{
	if(b<=a)return 0;
	int root = (a+b)/2;
	node* ans=new node();
	ans->left=tree_formation(a,(a+b)/2);
	ans->right=tree_formation((a+b)/2+1,b);
	ans->data=v[root];
	return ans;
}


int main()
{
	int n;
	cin>>n;
	v.resize(n);
	for(int i=0;i<n;i++)
	{
		cin>>v[i];
	}
	node * head = tree_formation(0,n);
	
}
