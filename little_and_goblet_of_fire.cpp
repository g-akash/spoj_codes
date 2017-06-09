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


class stud
{
public:
	int coll,roll;
	stud(int x, int y)
	{
		coll=x;
		roll=y;
	}
};

int main()
{
	int q;
	cin>>q;
	list<stud> l;
	stud s(0,0);
	l.push_back(s);
	list<stud>::iterator it1,it2,it3,it4,it,tmp;
	it1=it2=it3=it4=l.end();
	it = l.begin();
	string typ;
	int x,y;
	foi(q)
	{
		cin>>typ;
		if(typ=="E")
		{
			cin>>x>>y;
			if(x==1)
			{
				if(it1==l.end())
				{
					l.push_back(stud(x,y));
					it1=l.end();
					it1--;
				}
				else
				{
					it1++;
					it1=l.insert(it1,stud(x,y));
				}
			}
			else if(x==2)
			{
				if(it2==l.end())
				{
					l.push_back(stud(x,y));
					it2=l.end();
					it2--;
				}
				else
				{
					it2++;
					it2=l.insert(it2,stud(x,y));
				}
			}
			else if(x==3)
			{
				if(it3==l.end())
				{
					l.push_back(stud(x,y));
					it3=l.end();
					it3--;
				}
				else
				{
					it3++;
					it3=l.insert(it3,stud(x,y));
				}
			}
			else if(x==4)
			{
				if(it4==l.end())
				{
					l.push_back(stud(x,y));
					it4=l.end();
					it4--;
				}
				else
				{
					it4++;
					it4=l.insert(it4,stud(x,y));
				}
			}
		}
		else if(typ=="D")
		{
			it++;
			if(it==it1)it1=l.end();
			if(it==it2)it2=l.end();
			if(it==it3)it3=l.end();
			if(it==it4)it4=l.end();
			cout<<it->coll<<" "<<it->roll<<endl;
		}
	}
}