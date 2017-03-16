#include <bits/stdc++.h>

using namespace std;
template<class T>

class node
{
public:
	node<T> *left,*right;
	T value;
	node()
	{
		left=0;
		right=0;
	}
};

template<class T>
node<T>* make_tree(vector<T> vec)
{
	vector<T> left,right;
	if(vec.size()==0)return 0;
	if(vec.size()==1)
	{
		node<T> * tree = new node<T>();
		tree->value=vec[0];
		return tree;
	}
	for(int i=0;i<vec.size()/2;i++)
	{
		left.push_back(vec[i]);
	}
	for(int i=vec.size()/2+1;i<vec.size();i++)
	{
		right.push_back(vec[i]);
	}
	node<T> *tree = new node<T>();
	tree->value=vec[vec.size()/2];
	tree->left=make_tree(left);
	tree->right=make_tree(right);
	return tree;
}



int main()
{

}