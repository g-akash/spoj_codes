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

vi v1(10),v2(10),v3(10);

bool present(int a, int b=-1, int c=-1)
{
	if(b==-1)
	{
		if(v1[a]==1||v2[a]==1||v3[a]==1)return true;
		return false;
	}
	if(c==-1)
	{
		if(v1[a]==1&&(v2[b]==1||v3[b]==1))return true;
		if(v2[a]==1&&(v1[b]==1||v3[b]==1))return true;
		if(v3[a]==1&&(v1[b]==1||v2[b]==1))return true;
		return false;
	}
	if(v1[a]==1&&v2[b]==1&&v3[c]==1)return true;
	if(v1[a]==1&&v2[c]==1&&v3[b]==1)return true;
	if(v1[b]==1&&v2[a]==1&&v3[c]==1)return true;
	if(v1[b]==1&&v2[c]==1&&v3[a]==1)return true;
	if(v1[c]==1&&v2[a]==1&&v3[b]==1)return true;
	if(v1[c]==1&&v2[b]==1&&v3[a]==1)return true;
	return false;
}




int main()
{
	int n;
	cin>>n;
	int var;
	foi(6){cin>>var;v1[var]=1;}
	foi(6){cin>>var;v2[var]=1;}
	foi(6){cin>>var;v3[var]=1;}
	foi1(999)
	{
		vi vec;
		int n = i;
		while(n!=0)
		{
			vec.pb(n%10);
			n/=10;
		}
		while(vec.size()!=3)vec.pb(-1);
		if(!present(vec[0],vec[1],vec[2]))
		{
			cout<<i-1<<endl;
			break;
		}
	}

}