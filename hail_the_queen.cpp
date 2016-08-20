#include<iostream>
#include<string>

using namespace std;

int main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		cout<<"Case "<<i+1<<": ";
		int n,var;
		cin>>n;
		var=n%16;
		n=n/16;
		string ans="";
		if(n<=9)ans+=to_string(n);
		else if(n==15)ans+="Z";
		else if(n==14)ans+="Y";
		else if(n==13)ans+="X";
		else if(n==12)ans+="W";
		else if(n==11)ans+="V";
		else if(n==10)ans+="U";
		if(var<=9)ans+=to_string(var);
		else if(var==15)ans+="Z";
		else if(var==14)ans+="Y";
		else if(var==13)ans+="X";
		else if(var==12)ans+="W";
		else if(var==11)ans+="V";
		else if(var==10)ans+="U";
		cout<<ans<<" ";
		cin>>n;
		var=n%16;
		n=n/16;
		ans="";
		if(n<=9)ans+=to_string(n);
		else if(n==15)ans+="Z";
		else if(n==14)ans+="Y";
		else if(n==13)ans+="X";
		else if(n==12)ans+="W";
		else if(n==11)ans+="V";
		else if(n==10)ans+="U";
		if(var<=9)ans+=to_string(var);
		else if(var==15)ans+="Z";
		else if(var==14)ans+="Y";
		else if(var==13)ans+="X";
		else if(var==12)ans+="W";
		else if(var==11)ans+="V";
		else if(var==10)ans+="U";
		cout<<ans<<" ";
		cin>>n;
		var=n%16;
		n=n/16;
		ans="";
		if(n<=9)ans+=to_string(n);
		else if(n==15)ans+="Z";
		else if(n==14)ans+="Y";
		else if(n==13)ans+="X";
		else if(n==12)ans+="W";
		else if(n==11)ans+="V";
		else if(n==10)ans+="U";
		if(var<=9)ans+=to_string(var);
		else if(var==15)ans+="Z";
		else if(var==14)ans+="Y";
		else if(var==13)ans+="X";
		else if(var==12)ans+="W";
		else if(var==11)ans+="V";
		else if(var==10)ans+="U";
		cout<<ans<<endl;;
	}
}