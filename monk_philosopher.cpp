#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <math.h>
#include <stack>
#include <map>
#include <queue>
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
	int n;
	cin>>n;
	vi vec(n);
	foi(n)cin>>vec[i];
	int q,x;
	cin>>q>>x;
	string inst;
	int curr=0,count=0,val=0;
	stack<int> coins;
	foi(q)
	{
		cin>>inst;
		if(inst=="Harry")
		{
			coins.push(vec[curr]);
			val+=vec[curr];
			count++;
			curr++;
		}
		else
		{
			if(count<=0)continue;
			val-=coins.top();
			coins.pop();
			count--;

		}
		if(val==x)
		{
			cout<<count<<endl;
			break;
		}
	}
	cout<<-1<<endl;
}