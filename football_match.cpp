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


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		umm(string,int) um;
		string s;
		foi(n)
		{
			cin>>s;
			um[s]+=1;
		}
		umm(string,int)::iterator it;
		it = um.begin();
		 int s1;
		 if(it!=um.end())s1 = it->second;
		 else s1 = 0;
		 if(it!=um.end())it++;
		 int s2;
		 if(it!=um.end())s2 = it->second;
		 else s2=0;
		 if(s2>s1)
		 {
		 	cout<<it->first<<endl;
		 }
		 else if(s1>s2)
		 {
		 	it=um.begin();
		 	cout<<it->first<<endl;
		 }
		 else cout<<"Draw"<<endl;
	}
}