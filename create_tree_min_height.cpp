#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

vector<int> v;

class node
{
	public:
	int data;
	node* left;
	node* right;
};

node* create_btree(int a, int b)
{
	if(b-a<=1)return 0;
	int curr_data=v[(a+b)/2];
	node* curr_node=new node();
	curr_node->data=curr_data;
	curr_node->left=create_btree(a,(a+b)/2); 
	curr_node->right=create_btree((a+b)/2+1,b);
	return curr_node;
} 
	

int main()
{
}
