#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<math.h>

using namespace std;

#define ll long long int

int main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		ll l,w,h;
		cin>>l>>w>>h;
		cout<<"Case #"<<i+1<<": "<<l*w*h-1<<" "<<ceil(log2(l))+ceil(log2(w))+ceil(log2(h))<<endl;
	}
}