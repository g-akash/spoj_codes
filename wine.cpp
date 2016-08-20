#include<iostream>
#include<stack>
#include<algorithm>

using namespace std;

#define ll long long int

int main()
{
	 ll n;
	 cin>>n;
	 while(n!=0)
	 {
	 	ll var;
	 	ll win=0,ans=0;
	 	for(int i=0;i<n;i++)
	 	{
	 		cin>>var;
	 		ans+=abs(win);
	 		win+=var;
	 	}
	 	cout<<ans<<endl;
	 	cin>>n;
	 }
}