#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

int main()
{
	int x;
	cin>>x;
	int count=0;
	while(x>0)
	{
		count=count+(x & 0x1);
		x=x>>1;
		//cout<<x<<endl;
	}
	cout<<count<<endl;
}
