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
#define foj1(n) for(int j=1;j<=n;j++)
#define vi vector<int>
#define vvi vector<vi >
#define si size()
#define MOD 1000000007


ll dp[3000][3000];


int main()
{
	ll n,m,ans=0;
	cin>>n>>m;
	string s;
	cin>>s;
	ll mb=10000000000,b=0;
	foi(m){
		if(s[i]=='(')b++;
		else b--;
		mb=min(mb,b);
	}
	
	dp[0][0]=1;
	foi1(n-m){
		dp[i][0]=dp[i-1][1];
		foj1(i){
			dp[i][j]=dp[i-1][j-1]+dp[i-1][j+1];
			dp[i][j] %= MOD;
		}
	}
	foi(n-m+1){
		foj(i+1){
			if(j>=-mb){if(j+b>=0&&j+b<=n-m)ans+=dp[i][j]*dp[n-m-i][j+b]%MOD;ans%=MOD;}
		}
	}
	cout<<ans<<endl;

}