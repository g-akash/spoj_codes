#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main()
{
	int t;
	cin>>t;
	for(int k=0;k<t;k++)
	{
		int n,i;
		string m,j;
		cin>>n>>m>>i>>j;
		if(n%2==0||(m[m.length()-1]=='0'||m[m.length()-1]=='2'||m[m.length()-1]=='4'||m[m.length()-1]=='6'||m[m.length()-1]=='8'))
		{
			cout<<"Impossible."<<endl;
		}
		else
		{
			if(i%2==0&&(j[j.length()-1]=='0'||j[j.length()-1]=='2'||j[j.length()-1]=='4'||j[j.length()-1]=='6'||j[j.length()-1]=='8'))
				cout<<"Possible."<<endl;
			else if(i%2==1&&(j[j.length()-1]=='1'||j[j.length()-1]=='3'||j[j.length()-1]=='5'||j[j.length()-1]=='7'||j[j.length()-1]=='9'))
				cout<<"Possible."<<endl;
			else cout<<"Impossible."<<endl;
		}		

	}
}