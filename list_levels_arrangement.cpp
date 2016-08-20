#include<iostream>
#include<vector>
#include<list>

using namespace std;

class node
{
	public:
	int data;
	node *left,*right;
};
vector<node*> v;


void arranger(node* head,int k)
{
	if(head->left!=0)arranger(head->left,k+1);
	if(head->right!=0)arranger(head->right,k+1);
	if(v.size()<k+1)v.resize(k+1);
	head->right=v[k];
	v[k]=head;
	return;
}
	
	

int main()
{
	node * head;
	arranger(head,0);
}
	
