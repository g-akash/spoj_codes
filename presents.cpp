#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <math.h>


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


int main()
{
	int n;
	cin>>n;
	if(n%3==0)
	{
		cout<<2*(n/3)<<endl;
	}
	else
	{
		cout<<2*(n/3)+1<<endl;
	}
}