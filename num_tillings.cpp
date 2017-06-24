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
	vi vec(1000005),sm(1000005);
	vec[0] = 1;
	vec[1] = 1;
	vec[2] = 2;
	vec[3] = 5;
	sm[0]=2;
	sm[1]=4;
	sm[2]=8;
	sm[3]=18;
	for(int i=4;i<1000005;i++)
	{
		vec[i]+=sm[i-3];
		vec[i]+=(vec[i-2]+vec[i-1]);
		vec[i]%=10000;
		sm[i]+=(2*vec[i]);
		sm[i]+=sm[i-1];
		sm[i]%=10000;

	}
	int n;
	cin>>n;
	cout<<vec[n]<<endl;
}