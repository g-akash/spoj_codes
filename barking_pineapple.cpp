#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <math.h>
#include <algorithm>


using namespace std;


#define ll long long int
#define umm(x,y) unordered_map<x,y >
#define pb push_back
#define foi(n) for(int i=0;i<n;i++)
#define foj(n) for(int j=0;j<n;j++)
#define foi1(n) for(int i=1;i<=n;i++)
#define vi vector<int>
#define vvi vector<vi >


int main()
{
	int t,s,x;
	cin>>t>>s>>x;
	if(((x-t)%s==0||(x-t-1)%s==0)&&x>=t&&x!=t+1)
	{
		cout<<"YES"<<endl;
	}
	else
	{
		cout<<"NO"<<endl;
	}
}