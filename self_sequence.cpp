#include<iostream>
#include<vector>

using namespace std;

int main()
{
	vector<int> v;
	v.push_back(0);
	v.push_back(1);
	int count=1,nt=2,pos=1;
	while(count<=1000000)
	{
		for(int i=0;i<v[pos];i++)v.push_back(nt);
			nt++;
		count+=v[pos];
		pos++;
	}
	//for(int i=0;i<10;i++)cout<<v[i];cout<<endl;
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		cin>>nt;
		cout<<"Case #"<<i+1<<": "<<v[nt]<<endl;
	}

}