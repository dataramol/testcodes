#include<iostream>

using namespace std;

class Test
{
private:
	int data;
public:
	Test()
	{
		data = 0;
	}
	Test(int d):data(d)
	{

	}

	Test operator++(int)
	{
		Test temp = *this;
		++data;
		return temp;
	}

	Test & operator++()
	{
		++data;
		return *this;
	}

	int getter()
	{
		return data;
	}

};

int main()
{
	Test t1(1);
	++t1;
	cout << t1.getter();

	//cout << ++t1;
}