#include<iostream>
#include<vector>

using namespace std;

#define ll long long

int main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		ll int n;
		cin>>n;
		n--;
		if(n==0)
		{
			cout<<"poor conductor"<<endl;
			continue;
		}
		ll int row=n/5,col=n%5;
		if((row%2==0&&col>=1)||(row%2==1&&col==0))
		{
			if(col>=1)
			cout<<row+1<<" ";
			else cout<<row<<" ";
			if(col==1){cout<<"W L"<<endl;}
			if(col==2){cout<<"A L"<<endl;}
			if(col==3){cout<<"A R"<<endl;}
			if(col==4){cout<<"M R"<<endl;}
			if(col==0){cout<<"W R"<<endl;}
			

		}
		else
		{
			
			if(col>=1)
			cout<<row+1<<" ";
			else cout<<row<<" ";
			if(col==1){cout<<"W R"<<endl;}
			if(col==2){cout<<"M R"<<endl;}
			if(col==3){cout<<"A R"<<endl;}
			if(col==4){cout<<"A L"<<endl;}
			if(col==0){cout<<"W L"<<endl;}

		}
	}
}