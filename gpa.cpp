#include<iostream>
#include<algorithm>
#include<string>
#include<iomanip>

using namespace std;


int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		float cre[6];
		bool failed = false;
		for(int j=0;j<6;j++)cin>>cre[j];
		float marks[6];
		for(int j=0;j<6;j++){
			marks[j]=0.0;
		string a1,a2,a3;
		cin>>a1>>a2>>a3;
		vector<float> as;
		as.resize(3);
		if(a1=="ab")as[0]=0.0;
		else as[0]=stof(a1);

		if(a2=="ab")as[1]=0.0;
		else as[1]=stof(a2);

		if(a3=="ab")as[2]=0.0;
		else as[2]=stof(a3);
		sort(as.begin(),as.end());
		marks[j]+=((as[2]+as[1])*45.0/40.0);
		cin>>as[0];
		marks[j]+=(as[0]/2.0);
		cin>>as[0];
		if(as[0]<51.0)marks[j]+=5;
		else if(as[0]<61.0)marks[j]+=4;
		else if(as[0]<71.0)marks[j]+=3;
		else if(as[0]<81.0)marks[j]+=2;
		else if(as[0]<91.0)marks[j]+=1;
		else marks[j]+=0;
		//cout<<marks[j]<<endl;

	}
		float gpa=0,cred=0;;


		for(int j=0;j<6;j++)
		{
			cred+=cre[j];
			if(marks[j]>=91.0)gpa+=cre[j]*10;
			else if(marks[j]>=81.0)gpa+=cre[j]*9;
			else if(marks[j]>=71.0)gpa+=cre[j]*8;
			else if(marks[j]>=61.0)gpa+=cre[j]*7;
			else if(marks[j]>50.0)gpa+=cre[j]*6;
			else if(marks[j]==50.0)gpa+=cre[j]*5;
			else {gpa+=0*cre[j];failed=true;}
		}
		if(!failed)cout<<"PASSED, "<<fixed<<setprecision(2)<<gpa/cred<<endl;
		else cout<<"FAILED, "<<fixed<<setprecision(2)<<gpa/cred<<endl;

	}
}