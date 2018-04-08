#include<iostream>

using namespace std;

class Date
{
private:
	int dd,mm,yyyy;
	int years;
	int count1,count2;
public:
	Date()
	{
		dd=0;
		mm=0;
		yyyy=0;
		years=0;
		count1=0;
		count2=0;
	}

	Date(int d,int m,int y):dd(d),mm(m),yyyy(y)
	{
		years=0;
		count1=0;
		count2=0;
	}

	bool operator==(Date const &rhs)const
	{
		return(dd==rhs.dd && mm==rhs.mm && yyyy==rhs.yyyy);
	}

	bool operator!=(Date const &rp)const
	{
		return !((*this)==rp);
	}

	int getTotalLeapYears()
	{
		years = yyyy;
		if(mm<=2)
		{
			years--;
		}

		return (years/4 - years/100 + years/400);
	}

	int calcYearDiff(Date &rhs)
	{
		const int monthdays[12]={31,28,31,30,31,30,31,31,30,31,30,31};
		count1 = (yyyy*365) + dd;
		for(int i=0;i<mm-1;i++)
		{
			count1 += monthdays[i];
		}
		count1+=getTotalLeapYears();

		count2 = (rhs.yyyy*365) + rhs.dd;
		for(int i=0;i<rhs.mm-1;i++)
		{
			count2 += monthdays[i];
		}
		count2 += rhs.getTotalLeapYears();

		if(count2 > count1)
		{
			return count2 - count1;
		}
		else
		{
			return count1 - count2;
		}
	}
};

int main()
{
	Date d1(10,02,1986),d2(22,02,2018);
	cout<<d1.calcYearDiff(d2);
	if(d1!=d2)
		{cout<<"Date Are unequal";}
}
