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
#define vll vector<ll>
#define vvll vector<vll >
#define si size()


int main()
{
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		string s1=s.substr(0,2)+s.substr(3,2);
		s=s.substr(6,4);
		std::sort(s1.begin(),s1.end());
		std::sort(s.begin(),s.end());
		if(s==s1)cout<<"Lucky Watson"<<std::endl;
		else cout<<"Unlucky Watson"<<std::endl;
	}
}