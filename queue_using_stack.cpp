#include<iostream>
#include<stack>

using namespace std;


class Myqueue
{
	private:
	stack<int> s1,s2;
	public:
	void insert(int n)
	{
		s2.push(n);
	}
	int top()
	{
		int front_element;
		while(!s2.empty())
		{
			s1.push(s2.top());
			s2.pop();
		}
		if(s1.empty())return -100;
		front_element=s1.top();
		while(!s1.empty())
		{
			s2.push(s1.top());
			s1.pop();
		}
		return front_element;
	}
	void pop()
	{
		while(!s2.empty())
		{
			s1.push(s2.top());
			s2.pop();
		}
		if(s1.empty())return;
		s1.pop();
		while(!s1.empty())
		{
			s2.push(s1.top());
			s1.pop();
		}
	}
};

int main()
{
	Myqueue q;
	q.insert(1);
	q.insert(2);
	q.insert(10);
	cout<<q.top()<<endl;
	q.pop();
	cout<<q.top()<<endl;
	q.pop();
	cout<<q.top()<<endl;
}
