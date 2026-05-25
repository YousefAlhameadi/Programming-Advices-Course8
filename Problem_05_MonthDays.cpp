#include <iostream>

using namespace std;

bool isLeepYear(int Year)
{
    return ((Year % 400) == 0) || ((Year % 4 == 0) && (Year % 100 != 0));
}

int GetNumberYear()
{
    int year;

    cout << "enter the year you want to check : ";
    cin >> year;
    return year;
}

int GetNumberMonth()
{
    int year;

    cout << "enter the month you want to check : ";
    cin >> year;
    return year;
}

int DaysInMonth(int year , int month)
{
    if ((isLeepYear(year) == true) && month == 2)
    {
        return 29;
    }
    else if ((isLeepYear(year) == false) && month == 2)
    {
        return 28;
    }
    else if ((month >=1 && month <=7) && (month !=2))
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
    else if((month >=8 && month <=12) && (month != 2))
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
}

int HoursInMonth(int year , int month)
{
    return DaysInMonth(year, month) * 24;
}

int MinutesInMonth(int year , int month)
{
    return HoursInMonth(year, month) * 60;
}

int SecondsInMonth(int year,int month)
{
    return MinutesInMonth(year, month) * 60;
}

int main()
{
    int year = GetNumberYear() ;
    cout << endl;
    short month = GetNumberMonth();
    cout << endl;

    cout << "number of days are : " << DaysInMonth(year,month) << endl;
    cout << "number of hours in the month are : " << HoursInMonth(year, month) << endl;
    cout << "number of minuets in the month are : " << MinutesInMonth(year, month) << endl;
    cout << "number of seconds in the month are : " << SecondsInMonth(year, month) << endl;

}

