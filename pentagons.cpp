#include<iostream>
#include<vector>

using namespace std;


int main()
{
	vector<int> marbles;
	marbles.resize(1005);
	marbles[1]=5;
	for(int i=2;i<1005;i++)
	{
		marbles[i]=4+3*(i-1)+marbles[i-1];
	}
	int n;
	cin>>n;
	while(n!=0)
	{
		cout<<marbles[n]<<endl;
		cin>>n;
	}

}