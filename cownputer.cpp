#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>

using namespace std;

int main()
{
	long long int n,var;
	string ans="";
	cin>>n;
	while(n!=0)
	{
		if(n<0)
		{
			var=-1*n;
			if(var%2==0){n=-1*(n/2);ans="0"+ans;}
			else
			{
				n=(var+1)/2;ans="1"+ans;
			}


		}
		else
		{
			if(n%2==0)ans="0"+ans;
			else ans="1"+ans;
			n=-1*(n/2);
		}
	}
	if(ans=="")ans="0";
	cout<<ans<<endl;
}