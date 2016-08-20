#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int tree_balanced(node* head)
{
	if(head==0)return 0;
	int left_height=tree_balanced(head->left);
	int right_height=tree_balanced(head->right);
	if(left_height<0||right_height<0)return -1;
	if(abs(left_height-right_height)<=1)return Max(left_height,right_height)+1;
	else return -1;
}

int main()
{
}
