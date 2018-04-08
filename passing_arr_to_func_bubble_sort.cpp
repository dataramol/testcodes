#include <iostream>

using namespace std;

#define SIZE 5

void input(int *ptr);
void display(int *ptr);
void sort(int *ptr);


int main()
{
	int arr[SIZE];
	input(arr);
	//display(arr);
	sort(arr);
	display(arr);	
}

void input(int *ptr)
{
	cout << "Enter array elements";
	for (int i = 0; i < SIZE; i++)
	{
		cin >> ptr[i];
	}

}

void display(int *ptr)
{

	for (int i = 0; i < SIZE; i++)
	{
		cout << ptr[i] <<endl;
	}

}

void sort(int *ptr)
{

	int temp;
	for (int i=0; i < SIZE-1; i++)
	{
		for (int j = i+1; j < SIZE; j++)
		{
			if (ptr[i] > ptr[j])
			{
				temp = ptr[i];
				ptr[i] = ptr[j];
				ptr[j] = temp;
			}
		}
	}
}