#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	int n;
	cin>>n;
	string ans="";
	ans+="I hate ";
	for(int i=1;i<n;i++)
	{
		if(i%2==1)ans+="that I love ";
		else ans+="that I hate ";
	}
	ans+="it";
	cout<<ans<<endl;

}