#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <math.h>


using namespace std;


#define ll long long int
#define ull unsigned long long int
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
	ull l,r,k;
	cin>>l>>r>>k;
	vector<ull> vec(65);
	vec[0]=1;
	foi1(64){if(log10(vec[i-1])+log10(k)>19.0)break;vec[i]=k*vec[i-1];}
	bool prnt=false;
	//foi(65)cout<<vec[i]<<endl;
	if(1>=l&&1<=r){cout<<1<<" ";prnt=true;}
	foi1(64){
		
		if(vec[i]>vec[i-1]&&vec[i]>=l&&vec[i]<=r){cout<<vec[i]<<" ";prnt=true;}

	}
	if(!prnt)cout<<-1;
	cout<<endl;
}