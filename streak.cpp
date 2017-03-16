#include<iostream>
#include<vector>
#include<algorithm>
#include<string>


using namespace std;

int main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		int n;
		string s;
		cin>>n;
		s=to_string(n);
		if(n%21!=0&&(s.find("21")<0||s.find("21")>s.length()-2))cout<<"The streak lives still in our heart!"<<endl;
		else cout<<"The streak is broken!"<<endl;
	}
}
