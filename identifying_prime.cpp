#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <math.h>
#include <map>
#include <queue>
#include <algorithm>
#include <list>

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


int a[15]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};
int sq[4]={4,9,25,49};

int main()
{
	int countp=0,countsq=0;
	string ans;
	foi(15)
	{
		cout<<a[i]<<endl;
		cin>>ans;
		if(ans=="yes")countp++;

	}
	foi(4)
	{
		cout<<sq[i]<<endl;
		cin>>ans;
		if(ans=="yes")countsq++;
	}
	if(countp>=2||countsq>=1)cout<<"composite"<<endl;
	else cout<<"prime"<<endl;
}