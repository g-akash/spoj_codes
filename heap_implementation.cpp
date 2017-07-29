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
#include <time.h>



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

int n;
vi val;

void swap(int a, int b)
{
	int var = val[a];
	val[a]=val[b];
	val[b]=var;
	return;
}

int get_max(int a, int b, int c)
{
	if(val[a]>=max(val[b],val[c]))return a;
	if(val[b]>=max(val[a],val[c]))return b;
	if(val[c]>=max(val[a],val[b]))return c;
	return a;
}

void make_heap(int a)
{
	if(2*a+2<n)
	{
		int x = 2*a+1, y = 2*a+2;
		int z = get_max(a,x,y);
		if(val[z]>val[a])
		{
			swap(a,z);
			make_heap(z);
		}
	}
	else if(2*a+1<n)
	{
		int x = 2*a+1;
		if(val[x]>val[a])
		{
			swap(x,a);
			make_heap(x);
		}
	}	
	return;
}

void heapify()
{
	for(int i=n-1;i>=0;i--)
	{
		make_heap(i);
	}

}

void insert(int x)
{
	val.pb(x);
	int pos = val.size()-1;
	while(pos!=0)
	{
		if(val[pos]>val[(pos-1)/2])
		{
			swap(pos,(pos-1)/2);
			pos = (pos-1)/2;
		}
		else
			break;
	}
	return;
}



int main()
{
	cin>>n;
	srand(time(NULL));
	val.resize(n);
	foi(n)
	{
		val[i]=rand()%1000;
	}

	heapify();
	foi(n+1)
	{
		cout<<val[i]<<" "<<val[2*i+1]<<" "<<val[2*i+2]<<endl;
	}
	cout<<"------------------------------"<<endl;
	insert(10012);

	foi(n+1)
	{
		cout<<val[i]<<" "<<val[2*i+1]<<" "<<val[2*i+2]<<endl;
	}
}