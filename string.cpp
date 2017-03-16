#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<string>

using namespace std;


 int fun()
 {
	 static int i;
	 i++;
	 return i;
 }
int main()
{
for(int j;j<5;j++)cout<<fun()<<endl;
}
