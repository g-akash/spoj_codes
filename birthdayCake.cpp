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
	int n;
	cin>>n;
	vector<string> vec(n);
	foi(n)cin>>vec[i];
	int ans=0,var1=0,var2=0;
	foi(n){
		var1=0;
		var2=0;
		foj(n){
			if(vec[i][j]=='C')var1++;
			if(vec[j][i]=='C')var2++;
		}
		ans+=(var1*(var1-1))/2;
		ans+=(var2*(var2-1))/2;
	}
	cout<<ans<<endl;

}