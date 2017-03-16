#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int g,b,G,B;
	cin>>G>>B;
	while(G+B>=0)
	{
		g=max(G,B);
		b=min(G,B);
		int ans=g/(b+1);
		while(ans*(b+1)>g)ans--;
		while(ans*(b+1)<g)ans++;
		cout<<ans<<endl;
		cin>>G>>B;
	}
}