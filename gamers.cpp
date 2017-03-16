#include<iostream>
#include<vector>
#include<math.h>

using namespace std;

int main()
{
	long long int n;
	cin>>n;
	if(n%10!=0)
	{
		cout<<1<<endl<<n%10<<endl;
	}
	else cout<<2<<endl;
}
