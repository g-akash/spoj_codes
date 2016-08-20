#include<iostream>
#include<unordered_set>
#include<string>
#include<vector>
#include<algorithm>


using namespace std;


int main()
{
	int n;
	unordered_map<string,int> s;
	cin>>n;
	string var;
	char c[6];
	vector<string> v;
	for(int i=0;i<n;i++)
	{
		scanf("%s",c);
		var=c;
		if(s[var]==0){s[var]=1;v.push_back(var);}
	}
	cout<<v.size()<<endl;
	sort(v.begin(),v.end());
	for(int i=0;i<v.size();i++){cout<<v[i]<<endl;}
}