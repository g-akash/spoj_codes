#include <iostream>
#include <vector>
//#include <unordered_map>
#include <string>
#include <math.h>
//#include <map>
#include <set>
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


int main()
{
	int n1,n2,n3,var;
	cin>>n1>>n2>>n3;
	set<int> s1,s2,s3,ans;
	set<int>::iterator it;
	foi(n1)
	{
		cin>>var;
		s1.insert(var);
	}
	foi(n2)
	{
		cin>>var;
		s2.insert(var);
	}
	foi(n3)
	{
		cin>>var;
		s3.insert(var);
	}
	it = s1.begin();
	while(it!=s1.end())
	{
		if(s2.find(*it)!=s2.end()||s3.find(*it)!=s3.end())
		{
			ans.insert(*it);
		}
		it++;
	}

	it = s2.begin();
	while(it!=s2.end())
	{
		if(s1.find(*it)!=s1.end()||s3.find(*it)!=s3.end())
		{
			ans.insert(*it);
		}
		it++;
	}

	it = s3.begin();
	while(it!=s3.end())
	{
		if(s1.find(*it)!=s1.end()||s2.find(*it)!=s2.end())
		{
			ans.insert(*it);
		}
		it++;
	}

	cout<<ans.size()<<endl;
	it = ans.begin();
	while(it!=ans.end())
	{
		cout<<*it<<endl;
		it++;
	}


}