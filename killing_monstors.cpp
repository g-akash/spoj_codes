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
#include <stdio.h>

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
	int curr;
	int tot;
	mm(int,int) mm;
	node *left, *right;
	node()
	{
		tot = 0;
		curr = 0;
		left = NULL;
		right = NULL;
	}

};

node *head;
int sol_left;

void insert(int x, int hlth, node *curr)
{
	if(x==0)
	{
		curr->tot+=1;
		curr->mm[hlth]+=1;
		return;
	}
	if(x%2==0)
	{
		x = x>>1;
		if(curr->left==NULL)curr->left = new node();
		curr->tot+=1;
		insert(x,hlth,curr->left);
		return;
	} else {
		x = x>>1;
		if(curr->right==NULL)curr->right = new node();
		curr->tot+=1;
		insert(x,hlth,curr->right);
		return;
	}
	return;
}

int kill(int x, int y, node *curr)
{
	if(curr==NULL)return 0;
	if(curr->tot<=0)return 0;
	int killed = 0;
	
	curr->curr+=y;
	mm(int,int)::iterator it = curr->mm.begin();
	while(it!=curr->mm.end())
	{
		if(it->first>curr->curr)break;
		killed+=it->second;
		curr->mm.erase(it);
		it = curr->mm.begin();

	}
	
		
	if(x==0){curr->tot-=killed;return killed;}
	
	if(x%2==0)
	{
		killed+=kill(x>>1,y,curr->left);
		curr->tot-=killed;
		return killed;

	} else {
		killed+=kill(x>>1,y,curr->left);
		killed+=kill(x>>1,y,curr->right);
		curr->tot-=killed;
		return killed;
	}

}




int main()
{
	int n;
	scanf("%d",&n);
	int hlth;
	sol_left = n;
	head = new node();
	foi(n)
	{
		scanf("%d",&hlth);
		insert(i,hlth,head);

	}
	int q;
	scanf("%d",&q);
	int x,y;
	foi(q)
	{
		scanf("%d %d",&x,&y);
		int killed = kill(x,y, head);
		sol_left-=killed;
		printf("%d\n",sol_left);

	}

}