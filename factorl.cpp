#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
vector<int> v;


void mult(int n)
{
	int carry=0,var;
	for(int i=0;i<v.size();i++)
	{
		 var=carry+v[i]*n;
		v[i]=var%10;
		carry=var/10;
	}
	while(carry>0)
	{
		v.push_back(carry%10);
		carry/=10;
	}
	return;
}


int main()
{

	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
	v.resize(1);
	int n;
	cin>>n;
	v[0]=1;


	for(int i=1;i<=n;i++)
	{
		mult(i);
		
	}
	for(int i=0;i<v.size();i++)cout<<v[v.size()-1-i];
			cout<<endl;
	}
}