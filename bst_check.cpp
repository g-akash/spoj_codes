#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


	if(node

bool bst(node* root)
{
	if(root==0)return true;
	else if(bst(root->left)&&bst(root->right)&&maxx(root->left)<root->data && minn(root->right)>root->data)return true;
	return false;
}

int main()
{
	//take input
	if(bst(root))cout<<"Yes it is a binary search tree"<<endl;
	else cout<<"No its not a binary search tree"<<endl;
}
	
