#include <iostream>

using namespace std;

bool isLeepYear(int Year)
{
    return ((Year % 400) == 0) || ((Year % 4 == 0) && (Year % 100 != 0));
}

int GetNumber()
{
    int year;

    cout << "enter the year you want to check : ";
    cin >> year;
    return year;
}

int convertYearsToSeconds(int year)
{
    if (isLeepYear(year) == true)
    {
        return (366 * 24 * 60 * 60);
    }
    else if (isLeepYear(year) == false)
    {
        return (365 * 24 * 60 * 60);
    }

}

int convertYearsToMinuets(int Seconds)
{
    return (Seconds / 60);
}

short convertYearsToHours(int Minuets)
{
    return (Minuets /60);
}

short ConvertYearsToDays(int Year)
{
    if (isLeepYear(Year) == true)
    {
        return 366;
    }
    if (isLeepYear(Year) == false)
    {
        return 365;
    }
}

int main()
{
    int year = GetNumber();

    int Seconds = convertYearsToSeconds(year);
    cout << "number of seconds are :" << Seconds << endl;

    int Minuets = convertYearsToMinuets(Seconds);
    cout << "nubmer of minuets are : " << Minuets << endl ;

    int Hours = convertYearsToHours(Minuets);
    cout << "number of hours are : " << Hours << endl;

   cout << "number of days are : " << ConvertYearsToDays(year);


}


