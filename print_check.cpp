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


int main(){
	int n,m,k;
	cin>>n>>m>>k;
	vi rc(n+1),cc(m+1),rn(n+1),cn(m+1);
	int ty,p,c;
	foi(k){
		cin>>ty>>p>>c;
		if(ty==1){
			rc[p]=c;
			rn[p]=i+1;
		}
		else{
			cc[p]=c;
			cn[p]=i+1;
		}
	}
	foi1(n){
		foj1(m){
			if(rn[i]>cn[j])cout<<rc[i]<<" ";
			else cout<<cc[j]<<" ";
		}
		cout<<endl;
	}
}