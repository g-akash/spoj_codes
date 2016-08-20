#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;

class data{
public:
	string s;
	int n;

};


int main()
{
	int n,ma;
	cin>>n>>ma;
	while(n!=0||ma!=0){
	unordered_map<string,int> m;
	string s;
	for(int i=0;i<n;i++)
	{
		cin>>s;
		m[s]+=1;
	}
	vector<int> v;
	v.resize(n);
	unordered_map<string,int>::iterator it=m.begin();
	while(it!=m.end())
	{
		v[it->second-1]++;
		it++;
	}
	for(int i=0;i<n;i++)cout<<v[i]<<endl;
		cin>>n>>ma;
}
}