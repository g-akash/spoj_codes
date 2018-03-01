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
		int a,b,c,d,e,f;
		cin>>a>>b>>c>>d>>e>>f;
		int cd = (d-a)*(d-a)+(e-b)*(e-b);
		if(cd==0&&c==f)
		{
			cout<<"C2~C1"<<endl;
		}
		else
		{
			if(double(c)>=sqrt(double(cd))+double(f))
			{
				cout<<"C1CC2"<<endl;
			}
			else if(double(f)>=sqrt(double(cd))+double(c))
			{
				cout<<"C2CC1"<<endl;
			}
			else cout<<"NOT SATISFIED"<<endl;
		}
	}
}