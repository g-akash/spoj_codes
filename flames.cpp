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
		string s1,s2;
		cin>>s1>>s2;
		vi v1(300),v2(300);
		foi(s1.length())v1[int(s1[i])]=1;
		foi(s2.length())v2[int(s2[i])]=1;
		int count=0;
		foi(s1.size()){if(v2[int(s1[i])]==0)count++;v2[int(s1[i])]=1;}
		foi(s2.size()){if(v1[int(s2[i])]==0)count++;v1[int(s2[i])]=1;}
		count%=5;
		if(count==0)count=5;
		if(count==1)cout<<"LFAME"<<endl;
		else if(count==2)cout<<"FLAME"<<endl;
		else if(count==3)cout<<"FALME"<<endl;
		else if(count==4)cout<<"FAMLE"<<endl;
		else cout<<"FAMEL"<<endl;
	}
}