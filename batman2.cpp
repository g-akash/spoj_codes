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

int t,n;
vi vec;
vector<vvi > vals(101);

int get_ans(int a, int b, int c)
{
	
	if(a>=n)return 0;
	if(vals[a][b][c]!=-1)return vals[a][b][c];
	int val1=-1,val2=-1,val3=-1;
	if(vec[a]>b)
		val1 = get_ans(a+1,vec[a],c)+1;
	if(vec[a]<c)val2 = get_ans(a+1,b,vec[a])+1;
	val3 = get_ans(a+1,b,c);
	vals[a][b][c]=max(val1,max(val2,val3));
	return vals[a][b][c];
}

int main()
{
	cin>>t;
	foi(101)
	{
		vals[i].resize(101);
		foj(101)vals[i][j].resize(101);
	}
	while(t--)
	{
		cin>>n;
		vec.resize(n);
		foi(101)
		{
			foj(101)
			{
				for(int k=0;k<101;k++)vals[i][j][k]=-1;
			}
		}
		foi(n)cin>>vec[i];
		cout<<get_ans(0,0,100)<<endl;
	}
}