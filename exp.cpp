#include<iostream>
#include<vector>
#include<iomanip>
using namespace std;

vector<double> turns;

int main()
{
	turns.push_back(0);
	double sum=0;
	for(int i=1;i<1000000;i++)
	{
		turns.push_back(turns[i-1]+1.0/double(i));
	}
	//for(int i=0;i<100;i++)cout<<turns[i]<<endl;
	int t;
	int n;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		//cout<<i<<endl;
		cin>>n;
		cout<<fixed<<setprecision(9)<<turns[n]<<endl;
	}
	//cout<<"hello"<<endl;
	return 0;
}