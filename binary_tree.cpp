#include<iostream>
#include<vector>
#include<list>
#include<algorithm>

using namespace std;

class node
{
	public:
	int data;
	node* left_child;
	node* right_child;
};

class btree
{
	public:
	node* root;
	btree(){root = NULL;}
};

void insert(node* &curr, int val)
{
	if(curr==0)
	{
		node* new_node =new node();
			new_node->data=val;
			curr=new_node;
			return;
		}
		
	if(val <curr-> data)
	{
		if(curr->left_child==0)
		{
			node* new_node =new node();
			new_node->data=val;
			curr->left_child=new_node;
			}
		else insert(curr->left_child,val);
		}
	else if(val==curr->data)
	{
		return;
		}
	else
	{
		if(curr->right_child==0)
		{
			node* new_node =new node();
			new_node->data=val;
			curr->right_child=new_node;
			}
		else insert(curr->right_child,val);
		}
}

bool find(node* &curr, int val)
{
	if(curr==0)return false;
	cout<<curr->data<<endl;
	if(curr->data==val)return true;
	else if(curr->data>val&&curr->left_child==0)return false;
	else if(curr->data<val&&curr->right_child==0)return false;
	else if(curr->data>val)return find(curr->left_child,val);
	else if(curr->data<val)return find(curr->right_child,val);
}

int main()
{
	btree bin_tree;
	int var;
	for(int i=0;i<100;i++)
	{
		var=rand()%10000;
		cout<<var<<endl;
		insert(bin_tree.root,var);
	}
	cout<<bin_tree.root->data<<endl;
	while(cin>>var)
	{
		if(find(bin_tree.root,var))cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	
}
	
		
