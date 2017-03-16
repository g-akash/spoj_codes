#include <iostream>
#include <stdio.h>
#include <algorithm>
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
	vi vec(n);
	foi(n)cin>>vec[i];
	if(vec[n-1]==15)cout<<"DOWN"<<endl;
	else if(vec[n-1]==0)cout<<"UP"<<endl;
	else if(vec.size()==1)cout<<-1<<endl;
	else if(vec[n-1]>vec[n-2])cout<<"UP"<<endl;
	else if(vec[n-1]<vec[n-2])cout<<"DOWN"<<endl;
}