#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;


int main()
{
	int n;
	cin>>n;
	vector<int> x,y,ansx,ansy;
	x.resize(n);y.resize(n);ansx.resize(n);ansy.resize(n);
	for(int i=0;i<n;i++)
	{
		cin>>x[i]>>y[i];
	}
	ansx[0]=x[0];
	ansy[0]=y[0];
	for(int i=1;i<n;i++)
	{
		ansx[i]=x[i]+max(ansx[i-1]+abs(y[i]-y[i-1]),ansy[i-1]+abs(y[i]-x[i-1]));
		ansy[i]=y[i]+max(ansx[i-1]+abs(x[i]-y[i-1]),ansy[i-1]+abs(x[i]-x[i-1]));
	}
	cout<<max(ansx[n-1],ansy[n-1])<<endl;
}