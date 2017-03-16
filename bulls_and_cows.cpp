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


string rem_part(int x, int times)
{
	string var=to_string(x),ans="";
	while(times--)
	{
		ans+=var;
	}
	return ans;

}


int main()
{
	int curr=0,a=0,b=0;
	string bulls="",var;
	foi(10)
	{
		var=bulls+rem_part(i,4-curr);
		cout<<var<<endl;
		cin>>a>>b;
		if(a==4)return 0;
		a+=b;
		bulls=var.substr(0,a);
		curr=a;
	}
	sort(bulls.begin(),bulls.end());
	a=0;
	while(a!=4)
	{
		cout<<bulls<<endl;
		cin>>a>>b;
		next_permutation(bulls.begin(),bulls.end());
	}


}