#include<iostream>
#include<vector>

using namespace std;

#define ll long long int

int main()
{
	vector<int> a0,a1;
	a0.resize(60);
	a1.resize(60);
	a0[0]=1;
	a1[0]=0;
	a1[1]=1;
	a0[1]=1;
	for(int i=2;i<60;i++)
	{
		a0[i]=a1[i-1]+a0[i-1];
		a1[i]=a0[i-2]+a1[i-2];
	}
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
	int n;
	cin>>n;
	cout<<a0[n]+a1[n]<<endl;}
}