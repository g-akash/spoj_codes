#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <math.h>
#include <map>
#include <queue>
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
#define si size()


int main()
{
	int n;
	cin>>n;
	if(n%2==0)
	{
		cout<<n/2<<endl;
		while(n!=0){cout<<"2 ";n-=2;}cout<<endl;
	}
	else
	{
		n-=3;
		cout<<n/2+1<<endl;
		while(n!=0){cout<<"2 ";n-=2;}cout<<3<<endl;
	}

}