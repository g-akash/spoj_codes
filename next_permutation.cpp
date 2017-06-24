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

vi vec;
int n,k;

bool dec()
{
	foi(n-1)
	{
		if(vec[i]<vec[i+1])return false;
	}
	return true;
}

int main()
{
	
	cin>>n>>k;
	foi(k)
	{
		vec.resize(n);
		foj(n)
		{
			cin>>vec[j];
		}
			if(dec())
			{
				for(int l=n-1;l>=0;l--)
				{
					//cout<<vec[l]<<" ";
				}
				cout<<endl;
			}
			else
			{
				int l,m;
				for(l=n-1;l>=0;l--)
				{
					if(vec[l]>vec[l-1])break;
				}
				l--;
				for(m=n-1;m>l;m--)
				{
					if(vec[m]>vec[l])break;
				}
				vi tmp;
				for(int o=l;o<n;o++)
				{
					if(o==m)continue;
					tmp.pb(vec[o]);
				}
				sort(tmp.begin(),tmp.end());
				for(int o=0;o<l;o++)cout<<vec[o]<<" ";
					cout<<vec[m]<<" ";
				for(int o=0;o<tmp.size();o++)cout<<tmp[o]<<" ";
					cout<<endl;
			}
	}

	
}