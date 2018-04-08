#include<iostream>

using namespace std;

class Date
{
private:
	unsigned int dd,mm,yyyy;
	int days;
	int yeardiff;
	int leapcount;
	int daydiff;

public:
	Date()
	{
		dd=0;
		mm=0;
		yyyy=0;
		days=0;
		yeardiff=0;
		leapcount=0;
		daydiff=0;
	}

	Date(int d, int m, int y):dd(d),mm(m),yyyy(y)
	{
		days=0;
		yeardiff=0;
		leapcount=0;
		daydiff=0;
	}

	bool isLeapyear(int year)
	{
		return (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
	}


	void calcYearDiff(Date &rp)
	{
		if(yyyy == rp.yyyy)
		{
			return;
		}
		if(yyyy > rp.yyyy)
		{
			yeardiff = yyyy - rp.yyyy - 1;
		}
		else
		{
			yeardiff = rp.yyyy - yyyy - 1;
		}

	}

	void calcLeapCount(Date &rp)
	{
			if(yyyy == rp.yyyy)
			{
				return;
			}

			if(yyyy > rp.yyyy)
			{
				for(int i=rp.yyyy ; i<yyyy ; i++)
				{
					if(isLeapyear(i))
					{
						leapcount++;
					}
				}
			}
			else
			{
				for(int i=yyyy ; i<rp.yyyy ; i++)
				{
					if(isLeapyear(i))
					{
						leapcount++;
					}
				}
			}

	}

	int getDaysOfYears(Date &rp)
	{
		int monthdays[12]={31,28,31,30,31,30,31,31,30,31,30,31};
		days += dd;
		rp.days += rp.dd;
		cout << "days"<<days<<"rpdays"<<rp.days;
		if(yeardiff==0)
		{
			if(mm<=rp.mm)
			{cout<<"hehe";
				for(int i=mm;i<12;i++)
				{
					days+=monthdays[i-1];
				}
				for(int i=1;i<rp.mm;i++)
				{
					rp.days+=monthdays[i-1];
				}
			}
			else if(mm>rp.mm)
			{
				for(int i=rp.mm;i<12;i++)
				{
					rp.days+=monthdays[i-1];
				}
				for(int i=1;i<rp.mm;i++)
				{
					days+=monthdays[i-1];
				}

			}	

		}
		/*if(mm > 1)
		{
			for(int i=mm;i<12;i++)
			{
				days += monthdays[i-1]; 
			}
		}
		if(rp.mm > 1)
		{
			for(int i=1;i<rp.mm;i++)
			{
				rp.days += monthdays[i-1]; 
			}
		}*/
		//cout << "days:"<<dd<<"rpdays"<<rp.days;
		if(isLeapyear(yyyy))
		{
			days+=1;
		}
		if(isLeapyear(rp.yyyy))
		{
			rp.days+=1;
		}
		return (days+rp.days);

	}


	int getDaysBetweenYears(Date &rhs)
	{

		calcYearDiff(rhs);
		calcLeapCount(rhs);
		daydiff = (yeardiff*365) + leapcount;
		getDaysOfYears(rhs);
		//cout << "daydiff1:" << daydiff;
		daydiff += getDaysOfYears(rhs);
		//cout << "daydiff2:" << daydiff;
		return daydiff;
	}

};


int main()
{
	Date d1(28,02,2017),d2(20,02,2018);
	cout << d1.getDaysBetweenYears(d2);
	return 0;
}