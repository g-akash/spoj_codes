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

class movies{
public:
	int aud,sub;
};



int main()
{
	int n,var,m;
	//cin>>n;
	scanf("%d",&n);
	map<int,int> lang;
	foi(n){
		//cin>>var;
		scanf("%d",&var);
		lang[var]++;
	}
	//cin>>m;
	
	scanf("%d",&m);
	int ans=0,ma=-1,ms=-1;
	vector<movies> vec(m);
	foi(m){
		scanf("%d",&var);
		//cin>>var;
		vec[i].aud=lang[var];
		if(vec[i].aud>ma){
			ma=vec[i].aud;
			ans=i+1;
		}
	}
	foi(m){
		//cin>>var;
		scanf("%d",&var);
		vec[i].sub=lang[var];
		if(vec[i].aud==ma&&vec[i].sub>ms){
			ms=vec[i].sub;
			ans=i+1;
		}
	}
	printf("%d\n",ans);
	//cout<<ans<<endl;
}