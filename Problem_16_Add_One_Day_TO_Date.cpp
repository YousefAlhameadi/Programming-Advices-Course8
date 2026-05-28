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

stDate AddDay(short Day, short Month, short Year)
{
    stDate Date1;
    
    Date1.Day = Day;
    Date1.Month = Month;
    Date1.Year = Year;
   

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

int main()
{
    stDate Date1 , DateAfterAddOneDay;

    Date1 = GetDate();
    cout << endl;

    DateAfterAddOneDay = AddDay(Date1.Day, Date1.Month, Date1.Year);

    cout << DateAfterAddOneDay.Day << "/" << DateAfterAddOneDay.Month << "/" << DateAfterAddOneDay.Year;


}