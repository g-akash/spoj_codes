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
#define si size()


int main()
{
	vector<int> side,fin;
	side.resize(3);
	fin.resize(3);
	cin>>side[0]>>fin[0];
	side[1]=side[0];
	side[2]=side[1];
	fin[1]=fin[0];
	fin[2]=fin[1];
	int mncount=3000000,temp,curr=0,maxx=side[0];
	while(fin!=side)
	{
		//cout<<fin[0]<<" "<<fin[1]<<" "<<fin[2]<<endl;
		fin[0]=min(side[0],fin[1]+fin[2]-1);
		sort(fin.begin(),fin.end());
		curr++;
	}
		
	
	cout<<curr<<endl;
}