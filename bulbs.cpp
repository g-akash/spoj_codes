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
	int n,m,cnt=0;
	cin>>n>>m;
	vector<int> vec(m+1,0);
	foi(n){
		int x,var;
		cin>>x;
		foj(x){
			cin>>var;
			if(vec[var]==0)cnt++;
			vec[var]=1;
		}
	}
	if(cnt==m)cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
}