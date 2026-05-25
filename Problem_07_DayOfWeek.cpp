#include <iostream>
#include <cmath>

using namespace std;

short IndexOfDay(short year , short month , short day)
{
    short a = ((14-month) / 12);
    short y = year - a;
    short m = month + (12 * a) - 2;

    return (day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;

}

void GetData()
{
    short year, month, day;

    cout << "enter the year : ";
    cin >> year;
    cout << "enter the month : ";
    cin >> month;
    cout << "enter the date of the day : ";
    cin >> day;
    cout << endl;

    string ArrDay[7] = { "sunday","monday","tuesday","wednesday","thursday" ,"friday" ,"saturday" };

    cout << "Date : " << day << "/" << month << "/" << year << endl;

    cout << "day order : " << IndexOfDay(year, month, day) << endl;
    cout << "day name : " << ArrDay[IndexOfDay(year, month, day)] << endl;
}


int main()
{
    GetData();
}


