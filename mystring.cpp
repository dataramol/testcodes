#include<iostream>

using namespace std;

class MyString
{
private:
	int size;
	char *sptr;
public:
	MyString()
	{
		size=0;
		sptr=NULL;
	}
	
	MyString(int s):size(s)
	{
		sptr = new char[size];
	}

	MyString(const MyString* rhs)
	{
		size = rhs->size;
		sptr = new char[size];
		for(int i=0;i<size;i++)
		{
			sptr[i] = rhs->sptr[i];
		}
	}

	void Accept()
	{
		cout << "Enter String";
		for(int i=0;i<size;i++)
		{

			cin >> sptr[i];
			//cin.get();
		}
		//while()
	}

	void Display()
	{
		cout << sptr;	
	}

	int strlen()
	{
		int length=0;
		for(int i=0;i<size;i++)
		{
			length++;
		}
		return length;

	}

	char* reverse()
	{
		//char *rsptr;
		//char *rsptr = new char[size];
		char *rsptr;
		for(int i=0;i<size;i++)
		{
			rsptr[i] = sptr[size-i-1];
		}
		return rsptr;
	}

	bool operator==(MyString &rhs)
	{
		int len1 = strlen();
		int len2 = rhs.strlen();
		if(len1 != len2)
		{
			return false;
		}
		for(int i=0;i<len1;i++)
		{
			if(sptr[i] != rhs.sptr[i])
			{
				return false;
			}
		}
		return true;
	}

	bool operator!=(MyString &rhs)
	{
		return !((*this)==rhs);
	}

	MyString operator+(MyString &rhs)
	{
		int len1 = strlen();
		int len2 = rhs.strlen();
		MyString temp(len1+len2);
		for(int i=0;i<len1;i++)
		{
			temp.sptr[i] = sptr[i];
		}
		for(int i=0;i<len2;i++)
		{
			temp.sptr[len1+i] = rhs.sptr[i];
		}
		return temp;
	}

	bool isPalindrome()
	{
		char *csptr = sptr;
		int len = strlen();
		for(int i=0,j=len-1;i<len && j>=0;i++,j--)
		{
			if(csptr[j] != sptr[i])
			{
				return false;
			}
		}
		return true;
	}

	~MyString()
	{
		delete []sptr;
	}
};

int main()
{
	MyString str1(5);//str2(5);
	str1.Accept();
	//str2.Accept();
	if(str1.isPalindrome())
	{
		cout << "str 1 is palindrome";
	}
	//MyString str3 = str1 + str2;
	//cout << "concatenated String is";
	//str3.Display();

	//MyString str2 = &str1;
	//str2.Display();
	//cout << str2.strlen();
	//cout<< str2.reverse();
	/*if(str1 != str2)
	{
		cout << "unequal";
	}*/

	/*int size;
	cout << "Enter Size of array";
	cin >> size;
	char *str = new char[size];
	//int *ptr;
	//cout << "enter array elements";
	

	//ptr = &arr[0];
	cout <<"enter";
	for (int i = 0; i < size; i++)
	{
		cin >> str[i];

	}
	for (int i = 0; i < size; ++i)
	{
		cout << str[i];// also *(ptr+i)
	}
	delete []str;
	
	cout << str[0];*/
}