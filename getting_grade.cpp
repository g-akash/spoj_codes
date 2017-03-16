#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>
#include <math.h>


using namespace std;


#define ll long long int
#define ull unsigned long long int
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
	int n,t;
	cin>>n>>t;
	string s,s1,s2;
	cin>>s;
	s1=s.substr(0,s.find(".")-1);
	s2=s.substr(s.find(".")-1);
	s2=s2.substr(0,1)+s2.substr(2);
	int end=s2.length();
	foi(s2.length()-1){
		if(int(s2[i+1])-48>=5){
			end=i;
			break;
		}
	}
	cout<<s2<<" "<<end<<endl;
	if(end==s2.length()){
		
	}
	else{
		while(t>0&&end>=0){
			if(int(s2[end+1])-48>=5){

				char ch = char(int(s2[end])+1);
				string var(1,ch);
				if(s2[end]=='9')
				{
					if(s1=="")s1="1";
					else {
						string var(1,ch);
						s1=s1.substr(0,s1.length()-1)+var;
					}
				}
				else{
					if(end!=0)s2=s2.substr(0,end)+var;
					else s2=var;
				}
				t--;
				end--;
			}
			else{
				break;
			}
		}
	}
	//cout<<s1<<" "<<s2<<endl;
	//cout<<s2.length()<<"kk"<<s2[1]<<"kk"<<endl;
	if(!(s2.length()==1))cout<<s1+s2.substr(0,1)+"."+s2.substr(1)<<endl;
	else cout<<s1+s2<<endl;
}