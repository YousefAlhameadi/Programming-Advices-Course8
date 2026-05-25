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
    cout << endl;
    return year;
}

int GetNumberMonth()
{
    int year;

    cout << "enter the month you want to check : ";
    cin >> year;
    cout << endl;
    return year;
}

int CheckMonths(int month)
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

}

int DaysInMonth(int year , int month)
{
    return (month >= 1 && month <= 12 && month != 2) ? CheckMonths(month) : 
        (isLeepYear(year) && month == 2) ? 29:28;
    
}


int main()
{
    int year = GetNumberYear();
    int month = GetNumberMonth();

    cout << endl << "the number of days are : " << DaysInMonth(year, month);

}

