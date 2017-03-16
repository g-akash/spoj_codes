#include<iostream>
#include<vector>
#include<string>
#include<math.h>

using namespace std;



int main()
{
	string s;
	//jose();
	cin>>s;
	while(s!="00e0")
	{
		int n=stoi(s.substr(0,2))*pow(10,stoi(s.substr(3,1)));
		int var=1,k;
		while(var<=n)
		{
			k=n-var;
			var*=2;
		}
		cout<<2*k+1<<endl;
		cin>>s;
	}

}