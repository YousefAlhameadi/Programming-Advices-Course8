#include <iostream>

using namespace std;

struct stDate
{
    short Year;
    short Month;
    short Day;
};

stDate GetDate()
{
    stDate Date;
    cout << "enter the day :";
    cin >> Date.Day;
    cout << "enter the month : ";
    cin >> Date.Month;
    cout << "enter the year : ";
    cin >> Date.Year;

    return Date;
}

bool isLeapYear(short Year)
{
    return ((Year % 400) == 0) || ((Year % 4 == 0) && (Year % 100 != 0));
}

int CheckMonths(short month, short Year)
{
    if ((month >= 1 && month <= 7) && (month != 2))
    {
        if ((month % 2) == 0)
        {
            return 30;
        }
        else if ((month % 2) != 0)
        {
            return 31;
        }
    }
    else if ((month >= 8 && month <= 12) && (month != 2))
    {
        if ((month % 2) != 0)
        {
            return 30;
        }
        else if ((month % 2) == 0)
        {
            return 31;
        }
    }
    if ((month == 2) && (isLeapYear(Year)))
    {
        return 29;
    }
    if ((month == 2) && (!isLeapYear(Year)))
    {
        return 28;
    }

}

bool Check_Last_Month(short Month)
{
    return (Month == 12);
}

bool Check_Last_day(short Day, short Month, short Year)
{
    return (Day == CheckMonths(Month, Year));

}

stDate AddDay(stDate Date1)
{

    if (Check_Last_day(Date1.Day, Date1.Month, Date1.Year))
    {
        if (Check_Last_Month(Date1.Month))
        {
            Date1.Day = 1;
            Date1.Month = 1;
            Date1.Year += 1;
        }
        else
        {
            Date1.Day = 1;
            Date1.Month += 1;
        }
    }

    else
    {
        Date1.Day += 1;
    }

    return Date1;

}

stDate AddNumberOfDays(stDate Date1,short Days)
{
    for (int i = 0; i < Days; i++)
    {
        Date1 = AddDay(Date1);
    }
    return Date1;
}

stDate AddOneWeek(stDate Date1)
{
    for (int i = 0; i < 7; i++)
    {
        Date1 = AddDay(Date1);
    }
    return Date1;
}

stDate AddMoreThanOneWeek(stDate Date1,short weeks)
{
    for (int i = 0; i < weeks; i++)
    {
        Date1 = AddOneWeek(Date1);
    }
    return Date1;
}

stDate AddOneMonth(stDate Date1)
{
    if (Date1.Month == 12)
    {
        Date1.Year++;
    }
    else
    {
        Date1.Month++;
    }
    return Date1;
}

stDate AddMoreThanOneMonth(stDate Date1 , short Months)
{
    for (int i = 0; i < Months; i++)
    {
       Date1 = AddOneMonth(Date1);
    }
    return Date1;
}

stDate AddOneYear(stDate Date1)
{
    Date1.Year++;

    return Date1;
}

stDate AddXYears(stDate Date1, short Years)
{
    for (int i = 0; i < Years; i++)
    {
        Date1 = AddOneYear(Date1);
    }
    return Date1;
}

stDate AddXYearsFaster(stDate Date1, short Years)
{
     Date1.Year += Years;

    return Date1;
}

stDate AddOneDecade(stDate Date1)
{
    return AddXYears(Date1,10);
}

stDate AddXDecades(stDate Date1 , short Decades)
{
    return AddXYearsFaster(Date1 , (Decades * 10));
}

stDate AddOneCentury(stDate Date1)
{
   return AddXDecades(Date1,10);
}

stDate AddOneMillennium(stDate Date1)
{
    return AddXDecades(Date1, 100);
}

int main()
{
    stDate Date = GetDate();
    Date = AddDay(Date);

    cout << endl << endl << "Date After : " << endl << endl;

    cout << "Date After Adding One Day : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = AddNumberOfDays(Date,10);

    cout << "Date After Adding 10 Days : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = AddOneWeek(Date);

    cout << "Date After Adding One week : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = AddMoreThanOneWeek(Date , 10);
    cout << "Date After Adding 10 weeks : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = AddOneMonth(Date);

    cout << "Date After Adding One Month : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = AddMoreThanOneMonth(Date, 5);

    cout << "Date After Adding Five Month : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = AddOneYear(Date);

    cout << "Date After Adding One year : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = AddXYears(Date , 10);
    
    cout << "Date After Adding 10 years : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = AddXYearsFaster(Date, 10);

    cout << "Date After Adding 10 years (Faster) : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = AddOneDecade(Date);

    cout << "Date After Adding One Decade : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = AddXDecades(Date , 10);

    cout << "Date After Adding 10 Decades : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = AddOneCentury(Date);

    cout << "Date After Adding one Century : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = AddOneMillennium(Date);

    cout << "Date After Adding one Millennium : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
}

