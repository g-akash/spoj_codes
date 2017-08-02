#include <iostream>
#include <stdio.h>
using namespace std;

int main() {
	// your code goes here
	int n;
	scanf("%d",&n);
	unsigned long long var;
	for(int i=0;i<n;i++)
	{
		scanf("%llu",&var);
		var = var/(unsigned long long)2;
		printf("%llu\n",var);
	}
}