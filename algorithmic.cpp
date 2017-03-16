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
	int n,c;
	cin>>n>>c;
	vi pr(n),t(n);
	foi(n)cin>>pr[i];
	foi(n)cin>>t[i];
	int res1=0,res2=0,s1=0;
	foi(n)
	{
		s1+=t[i];
		res1+=max(0,(pr[i]-s1*c));
	}
	s1=0;
	for(int i=n-1;i>=0;i--)
	{
		s1+=t[i];
		res2+=max(0,(pr[i]-s1*c));
	}
	if(res1>res2)cout<<"Limak"<<endl;
	else if(res2>res1)cout<<"Radewoosh"<<endl;
	else cout<<"Tie"<<endl;
}