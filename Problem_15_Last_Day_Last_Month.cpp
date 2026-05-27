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

int CheckMonths(short month , short Year)
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

bool Check_Last_day (short Day , short Month , short Year)
{
    return (Day == CheckMonths(Month,Year));

}

int main()
{
    stDate  Date1;

    Date1 = GetDate();
    cout << endl;

    if (Check_Last_day(Date1.Day, Date1.Month , Date1.Year))
    {
        cout << "yes Day is last day of the month" << endl;
    }

    else 
    {
        cout << "no Day is not the last day of the month " << endl;
    }

     if (Check_Last_Month(Date1.Month))
    {
        cout << "yes month is the last month of the year" << endl;
    }

    else
    {
        cout << "no month is not the last month of the year" << endl;
    }
}


