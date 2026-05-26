#include <iostream>
#include <string>

using namespace std;

struct sDate
{
    short Year;
    short Month;
    short Day;
};


short ReadDay()
{
    short Day;
    cout << "\nPlease enter a Day? ";
    cin >> Day;
    return Day;
}

short ReadMonth()
{
    short Month;
    cout << "\nPlease enter a Month? ";
    cin >> Month;
    return Month;
}

short ReadYear()
{
    short Year;
    cout << "\nPlease enter a Year? ";
    cin >> Year;
    return Year;
}

sDate ReadFullDate()
{
    sDate Date;
    Date.Day = ReadDay();
    Date.Month = ReadMonth();
    Date.Year = ReadYear();
    return Date;
}

short ReadDaysToAdd()
{
    short Days;
    cout << "\nHow many days to add? ";
    cin >> Days;
    return Days;
}

bool isLeapYear(int Year)
{
    return ((Year % 400) == 0) || ((Year % 4 == 0) && (Year % 100 != 0));
}

short CheckMonths(short month, short year)
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
    else if (month == 2 && isLeapYear(year))
    {
        return 29;
    }
    else if (month == 2 && !isLeapYear(year))
    {
        return 28;
    }

    return 0;
}

short NumberOfDaysFromTheBeginingOfTheYear(short Day, short Month,
    short Year)
{
    short TotalDays = 0;
    for (int i = 1; i <= Month - 1; i++)
    {
        TotalDays += CheckMonths(i, Year);
    }
    TotalDays += Day;
    return TotalDays;
}

sDate DateAddDays(short Days, sDate Date)
{
    short RemainingDays = Days + NumberOfDaysFromTheBeginingOfTheYear(Date.Day, Date.Month,
        Date.Year);
        
    short MonthDays = 0;
    Date.Month = 1;
    while (true)
    {
        MonthDays = CheckMonths(Date.Month, Date.Year);
        if (RemainingDays > MonthDays)
        {
            RemainingDays -= MonthDays;
            Date.Month++;
            if (Date.Month > 12)
            {
                Date.Month = 1;
                Date.Year++;
            }
        }
        else
        {
            Date.Day = RemainingDays;
            break;
        }
    }
    return Date;
}
    



int main()
{
    short day, month, year ,HowManyDaysToAdd;

    sDate Date = ReadFullDate();
    short Days = ReadDaysToAdd();
    

    Date = DateAddDays(Days, Date);
    cout << "\nDate after adding [" << Days << "] days is: ";
    cout << Date.Day << "/" << Date.Month << "/" << Date.Year;
   

}

