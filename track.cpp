#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>
#include <math.h>


using namespace std;


#define ll long long int
#define umm(x,y) unordered_map<x,y >
#define pb push_back
#define foi(n) for(int i=0;i<n;i++)
#define foj(n) for(int j=0;j<n;j++)
#define foi1(n) for(int i=1;i<=n;i++)
#define vi vector<int>
#define vvi vector<vi >
#define si size()

int main()
{
	string s,srev,tar;
	cin>>s>>tar;
	srev=s;
	reverse(srev.begin(),srev.end());
	//cout<<s<<" ll "<<srev<<endl;
	vi x,y;
	while(tar!=""){
		string temp=tar.substr(0,1),pt="";
		//cout<<tar<<endl;
		if(s.find(temp)>s.length()){
			cout<<-1<<endl;
			break;
		}
		while((s.find(temp)<=s.length()-temp.length()||srev.find(temp)<=srev.length()-temp.length())&&temp.length()<=s.length())
		{
			//cout<<temp<<" "<<pt<<endl;
			pt=temp;
			if(temp.length()<tar.length()){
				temp=tar.substr(0,temp.length()+1);
			}
			else  break;
		}
		//cout<<pt<<endl;
		temp=pt;
		if(s.find(temp)<s.length()){
			x.pb(s.find(temp)+1);
			y.pb(s.find(temp)+temp.length());
		}
		else{
			x.pb(s.length()-srev.find(temp));
			y.pb(s.length()+1-srev.find(temp)-temp.length());
		}
		tar=tar.substr(temp.length());
		
	}
	if(tar==""){
		cout<<x.size()<<endl;
		foi(x.size()){
			cout<<x[i]<<" "<<y[i]<<endl;
		}
	}
}