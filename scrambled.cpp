#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <math.h>
#include <iomanip>


using namespace std;


#define ll long long int
#define umm(x,y) unordered_map<x,y >
#define pb push_back
#define foi(n) for(int i=0;i<n;i++)
#define foj(n) for(int j=0;j<n;j++)
#define foi1(n) for(int i=1;i<=n;i++)
#define vi vector<int>
#define vvi vector<vi >
#define si size()

int hcf(int a, int b)
{
	if(a%b==0)return b;
	return hcf(b,a%b);
}


int main()
{
	int n;
	cin>>n;
	vi m(n),r(n);
	foi(n)cin>>m[i];
	foi(n)cin>>r[i];
	int lcm=1;
	foi(n)lcm=(lcm*m[i])/hcf(lcm,m[i]);
	int count=0;
	foi(lcm)
	{
		foj(n)if(i%m[j]==r[j]){count++;break;}
	}
	cout<<fixed<<setprecision(6)<<double(count)/double(lcm)<<endl;
}