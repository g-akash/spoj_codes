#include <iostream>
#include <vector>
//#include <unordered_map>
#include <string>
#include <math.h>
//#include <map>
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
	int n;
	cin>>n;
	vi vec(n);
	foi(n){
		cin>>vec[i];
	}
	vi temp;
	for(int i=0;i<n;i++)
	{
		if(temp.size()==0)
		{
			temp.pb(vec[i]);
		}
		else if(vec[i]>=temp[temp.size()-1])
		{
			temp.pb(vec[i]);
		}
		else if(temp[0]>=vec[i])
		{
			temp[0]=vec[i];
		}
		else
		{
			int x=0,y=temp.size()-1;
			while(y-x>1)
			{
				int mid = (x+y)/2;
				if(temp[mid]>=vec[i])y=mid;
				else x=mid;
			}
			temp[y]=vec[i];
		}

	}
	cout<<n-temp.size()<<endl;
}