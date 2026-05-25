#include <iostream>
#include<string>
using namespace std;

int GetNumberYear()
{
    int year;

    cout << "enter the year  : ";
    cin >> year;
    cout << endl;
    return year;
}

int GetNumberMonth()
{
    int month;

    cout << "enter the month : ";
    cin >> month;
    cout << endl;
    return month;
}

int GetNumberDay()
{
    int day;

    cout << "enter the day : ";
    cin >> day;
    cout << endl;
    return day;
}

bool isLeepYear(int Year)
{
    return ((Year % 400) == 0) || ((Year % 4 == 0) && (Year % 100 != 0));
}

int CheckMonths(int month , int year)
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
    else if (month == 2 && isLeepYear(year))
    {
        return 29;
    }
    else if (month == 2 && !isLeepYear(year))
    {
        return 28;
    }
    
    return 0;
}

short TotalDaysFromTheStartOfTheYear(int year, int month, int day)
{
    short counter = 0;

    
    for (int i = 1; i < month; i++)
    {
        counter += CheckMonths(i, year);
    }

   
    return counter + day;
}

string DateFromTotalDaysMonths(int days , int year)
{
   
    short CountMonths = 1;
    for (int i = 1; days > CheckMonths(i,year); i++)
    {
        
         days = days - CheckMonths(i , year);

        CountMonths +=1;
    }
    return  to_string(days) + "/" + to_string(CountMonths);
}

int main()
{
    int day = GetNumberDay();
    int month = GetNumberMonth();
    int year = GetNumberYear();

    cout << "number of days from the begining of the year is :" << TotalDaysFromTheStartOfTheYear(year, month, day) << endl;

    cout << "data is " << DateFromTotalDaysMonths(TotalDaysFromTheStartOfTheYear(year, month, day), year) << "/" << year;
    
}

