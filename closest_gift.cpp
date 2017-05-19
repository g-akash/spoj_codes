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

bool isprime(int n)
{
	if(n==0||n==1)return false;
	int srt = (int)sqrt(n);
	for(int i=2;i<=srt;i++)
	{
		if(n%i==0)return false;
	}
	return true;
}

int main()
{
	
	int n;
	cin>>n;
	int ansp,ansn=-2000000000;
	for(int i=n;;i++)
	{
		if(isprime(i))
		{
			ansp=i;
			break;
		}
	}
	for(int i=n;i>=0;i--)
	{
		if(isprime(i))
		{
			ansn=i;
			break;
		}
	}
	//cout<<ansp<<" "<<ansn<<endl;
	if(ansp-n<=n-ansn)cout<<ansp-n<<endl;
	else cout<<n-ansn<<endl;
}