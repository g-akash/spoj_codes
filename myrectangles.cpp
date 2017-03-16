#include <iostream>
#include <vector>
#include<math.h>

using namespace std;

int main()
{
	int count=0;
	vector<int> v;
	v.resize(10005);
	v[1]=1;
	for(int i=2;i<=10000;i++)
	{
		count=0;
		for(int j=1;j<=sqrt(i);j++)
		{
			if(i%j==0)count++;
		}
		v[i]=v[i-1]+count;
	}
	cin>>count;
	cout<<v[count]<<endl;

}