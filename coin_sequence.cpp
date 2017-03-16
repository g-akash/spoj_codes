#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>

using namespace std;


int main()
{
	int t;
	cin>>t;
	int n;
	for(int i=0;i<t;i++)
	{
		string s;
		cin>>n;
		cin>>s;
		unordered_map<string,int> m;
		string var=s.substr(0,2);
		s=s.substr(2);
		for(int j=0;j<38;j++)
		{
			var=var+s.substr(0,1);
			m[var]+=1;
			var=var.substr(1);
			s=s.substr(1);
		}
		cout<<i+1<<" "<<m["TTT"]<<" "<<m["TTH"]<<" "<<m["THT"]<<" "<<m["THH"]<<" "<<m["HTT"]<<" "<<m["HTH"]<<" "<<m["HHT"]<<" "<<m["HHH"]<<endl;
	}
}