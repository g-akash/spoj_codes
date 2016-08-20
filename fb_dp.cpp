#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
	int l;
	cin>>l;
	int n;
	int a,b;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a>>b;
		if(a<l||b<l)cout<<"UPLOAD ANOTHER"<<endl;
		else if(a==l&&b==l)cout<<"ACCEPTED"<<endl;
		else cout<<"CROP IT"<<endl;
	}
}
