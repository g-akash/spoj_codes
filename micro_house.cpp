#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <math.h>
#include <map>
#include <queue>
#include <algorithm>
#include <list>

using namespace std;


#define ll long long int
#define umm(x,y) unordered_map<x,y >
#define pb push_back
#define foi(n) for(int i=0;i<n;i++)
#define foj(n) for(int j=0;j<n;j++)
#define foi1(n) for(int i=1;i<=n;i++)
#define foj1(n) for(int j=1;j<=n;j++)
#define vi vector<int>
#define vvi vector<vi >
#define vll vector<ll>
#define vvll vector<vll >
#define si size()


class trnode{
public:
	trnode *l0,*l1;
};

class trie
{

public:
	trnode *head;
	umm(int,bool) um;
	trie(){
		head = new trnode();
	}
	void insert(int in)
	{
	    if(um.find(in)!=um.end())return;
		trnode *curr = head;
		int x=1<<27;
		foi(28)
		{
			if((in&(x))==0)
			{
				if(curr->l0==0)curr->l0=new trnode();
				curr=(curr->l0);
			}
			else 
			{
				if(curr->l1==0)curr->l1=new trnode();
				curr=curr->l1;
			}
			x=x>>1;
			
		}
		um[in]=true;

	}
	
	int find_max(int in)
	{
		trnode *curr = head;
		int ans=0;
		int x=1<<27;
		foi(28)
		{
			if((in&(x))==0)
			{
				if(curr->l1!=0)
				{
					ans=ans*2+1;
					curr=curr->l1;

				}
				else 
				{
					ans=ans*2;
					curr=curr->l0;
				}
			}
			else
			{ 		
				if(curr->l0!=0)
				{
					ans=ans*2+1;
					curr=curr->l0;
				}		
				else 
				{
					ans=ans*2;
					curr=curr->l1;
				}
			}
			x=x>>1;
		}
		return ans;
	}
};

int n,m;
int vec[10001][21];
int main()
{
	
	scanf("%d",&n);
	scanf("%d",&m);
	foi(n+1)
	{
		vec[i][0]=0;

	}
	foi(21)vec[0][i]=0;
	foi1(n)
	{
		foj1(m)
		{
			scanf("%d",&vec[i][j]);
			vec[i][j]=vec[i][j]^vec[i][j-1];
		}
	}
	int ans=0,prexor=0;
	trie tr;
	foi1(m)
	{
		for(int j=i;j<=m;j++)
		{
			int ver,v1,mx=0;
			tr.head = new trnode();
			tr.um.clear();
			prexor=0;
			tr.insert(prexor);
			for(int k=1;k<=n;k++)
			{
				v1=(vec[k][i-1]^vec[k][j]);
				//vi tmp = convert(v1);
				ver=(tr.find_max(v1));
				if(ver>ans)
				{
					ans=ver;
				}
				if(ver>mx)mx=ver;
				
				prexor=prexor^v1;
				//vi prex = convert(prexor);
				tr.insert(prexor);

			}
			if(mx<ans)break;
		}
	}
	printf("%d\n",ans );
}


