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
	int n;
	cin>>n;
	vi nums(n);
	foi(n)cin>>nums[i];
	string s;
	char ch;
	cin.get(ch);
	foi(n)
	{
		int cnt=0;
		getline(cin,s);
		//cout<<s<<"s"<<endl;
		foj(s.length())if(s[j]=='a'||s[j]=='e'||s[j]=='i'||s[j]=='o'||s[j]=='u'||s[j]=='y')cnt++;
		if(cnt!=nums[i]){cout<<"NO"<<endl; return 0;}
	}
	cout<<"YES"<<endl;
}