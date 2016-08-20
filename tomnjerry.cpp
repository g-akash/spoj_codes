#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;
int a,b;

int winner(int n, int play,unordered_map<int,int> &m)
{
	if(n<0)return play;
	if(n<a&&n<b)return (play+1)%2;
	if(m[play*100000000+n]!=0)return m[play*100000000+n]-1;
	int w1,w2;

	if(a!=b&&a!=0&&b!=0){
	w1=winner(n-a,(play+1)%2,m);
	w2=winner(n-b,(play+1)%2,m);}
	else if(a==0)
		{
			w2=winner(n-b,(play+1)%2,m);
			if(play==1){if(w2)w1=w2;else w1=winner(n-a,(play+1)%2,m);}
			else{if(!w2)w1=w2;else w1=winner(n-a,(play+1)%2,m); }
		}
	else if(b==0){
			w1=winner(n-a,(play+1)%2,m);
			if(play==1){if(w1)w2=w1;else w2=winner(n-b,(play+1)%2,m);}
			else{if(!w1)w2=w1;else w2=winner(n-a,(play+1)%2,m); }
		}
	else if(a==b){w2=winner(n-b,(play+1)%2,m);w1=w2;}
	if(play==1){if(w1||w2)m[play*100000000+n]=2;else m[play*100000000+n]=1;return w1||w2;}
	else {if(w1&&w2)m[play*100000000+n]=2;else m[play*100000000+n]=1;return w1&&w2;}
}

int main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		unordered_map<int,int> m;
		int n;
		cin>>n>>a>>b;
		cout<<winner(n,1,m)<<endl;
	}
}