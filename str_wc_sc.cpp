#include<iostream>
#include<string>
#include<cstring>
using namespace std;

/*program to count no. of spaces in a string*/

int main()
{
	int spacecount=0;
	int wc=0;
	int i=0;
	int newsize=0;
	string str;
	cout << "enter string";
	getline(cin, str);
	int size = str.size();
	for(int j=size-1;j>=0;j--)
	{
		if(str[j]!=' ')
		{
			break;
		}
		newsize=size-1;
                spacecount++;
	}
	newsize==0?newsize=size:newsize=newsize;
	while(i<newsize)
	{
		while(str[i]==' ')
		{
			i++;
			spacecount++;
		}
		while(str[i]!=' ' && i<newsize)
		{
			i++;
		}
		wc++;	
		
	}

        /*if(str[size-1]==' ')
        {wc--;}*/
	cout << wc<<endl;
        cout << spacecount;
				
		
}
