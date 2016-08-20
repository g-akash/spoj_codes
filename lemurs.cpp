#include<iostream>
#include<vector>

using namespace std;

int main()
{
	int N,K,n,k;
	cin>>N>>K;
	for(int i=0;i<N+K;i++)
	{
		for(int j=0;j<=i;j++)
		{
			n=N+j;
			k=K+(i-j);
			if(n%k==0){cout<<i<<endl;return 0;}
			n=N-j;
			k=K+(i-j);
			if(n%k==0){cout<<i<<endl;return 0;}
			n=N-j;
			k=K-(i-j);
			if(n%k==0){cout<<i<<endl;return 0;}
			n=N+j;
			k=K-(i-j);
			if(n%k==0){cout<<i<<endl;return 0;}
		}
	}

}