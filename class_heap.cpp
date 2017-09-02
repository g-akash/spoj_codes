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



// assuming its a max heap class

class heap
{
public:
	vi vec;

	void heapify(int x)
	{

		int p1 = 2*x+1, p2 = 2*x+2;
		if(p1>=vec.size())
			return;
		if(p2>=vec.size())
		{
			if(vec[p1]>vec[x])
			{
				swap(x,p1);
				heapify(p1);
			}
			else
				return;
		}
		else
		{
			if(vec[x]>vec[p1]&&vec[x]>vec[p2])
				return;
			if(vec[p1]>vec[p2])
			{
				swap(x,p1);
				heapify(p1);
			}
			else
			{
				swap(x,p2);
				heapify(p2);
			}
		}
	}

	void make_heap()
	{
		
		for(int i=vec.size()-1;i>=0;i--)
		{
			heapify(i);
		}
	}

	void swap(int x, int y)
	{
		int tmp = vec[x];
		vec[x] = vec[y];
		vec[y] = tmp;
	}

	void insert(int val)
	{
		int pos = vec.size();
		vec.pb(val);
		while(pos>0)
		{
			if(vec[pos]>vec[(pos-1)/2])
			{
				swap(pos,(pos-1)/2);
				pos = (pos-1)/2;

			}
			else 
				break;

		}
		return 0;
	}

	int top()
	{
		if(vec.size()>0)return vec[0];
		else return 0;
		
	}

	void pop()
	{
		if(vec.size()==0)
			return;
		if(vec.size()==1)
		{
			vec.pop_back();
			return;
		}
		swap(0,vec.size()-1);
		vec.pop_back();
		int x = 0;
		while(2*x+1<vec.size())
		{
			int p1 = 2*x+1, p2 = 2*x+2;
			if(p2>=vec.size())
			{
				if(vec[x]>vec[p1])
				{
					swap(x,p1);
					x=p1;
					continue;
				}
				else
					break;
			}
			else if(vec[x]<vec[p1]&&vec[x]<vec[p2])
				break;
			else if(vec[p1]>vec[p2])
			{
				swap(x,p1);
				x=p1;
			}
			else
			{
				swap(x,p2);
				x=p2;
			}
		}
		return;
	}

};