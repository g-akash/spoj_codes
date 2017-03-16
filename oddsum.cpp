#include<iostream>
#include<vector>


using namespace std;

#define ll long long int


int main()
{
	ll a,b;
	cin>>a>>b;
	if(a%2==0)a++;
	if(b%2==0)b--;
	if(a>b){cout<<0<<endl;return 0;}
	cout<< ((b+2-a)/2*(a+b))/2<<endl;
}