#include <iostream>
#include<iomanip>

using namespace std;

bool isLeepYear(int Year)
{
    return ((Year % 400) == 0) || ((Year % 4 == 0) && (Year % 100 != 0));
}

int GetNumberyear()
{
    int year;

    cout << "enter the year you want to check : ";
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

int DaysInMonth(int year, int month)
{
    return (month >= 1 && month <= 12 && month != 2) ? CheckMonths(month) :
        (isLeepYear(year) && month == 2) ? 29 : 28;

}

short IndexOfDay(short year, short month, short day)
{
    short a = ((14 - month) / 12);
    short y = year - a;
    short m = month + (12 * a) - 2;

    return (day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;

}

string FWeekDays(short index)
{
    string DayArr[7] = { "Sun" , "Mon" , "Tue" ,"Wed" , "Thu" , "Fri" , "Sat" };
    return DayArr[index];
}

void PrintCalendar(int month, int year)
{


    short FirstDayMonth = IndexOfDay(year, month, 1);
    short HowManyDaysMonth = DaysInMonth(year, month);



    for (int i = 0; i < 7; i++)
    {
        cout << left << setw(10) << FWeekDays(i) << right << setw(10);

    }
    cout << endl;

    if (FirstDayMonth != 0)
    {
        short coutner = FirstDayMonth;

        cout << setw(10 * FirstDayMonth) << "";
        for (int i = 1; i <= HowManyDaysMonth; i++)
        {
            cout << left << setw(10) << i;
            coutner++;

            if (coutner == 7)
            {
                coutner = 0;
                cout << endl;

            }
        }
    }

    if (FirstDayMonth == 0)
    {
        short coutner = FirstDayMonth;
        for (int i = 0; i < HowManyDaysMonth; i++)
        {
            cout << left << setw(10) << (i + 1);
            coutner++;
            if (coutner == 7)
            {
                coutner = 0;
                cout << endl;

            }
        }
    }

}

string Months(short i)
{
    string MonthsArr[12] = { "Jan", "Feb", "Mar", "Apr",
        "May", "Jun", "Jul", "Aug",
        "Sep", "Oct", "Nov", "Dec" };
    return MonthsArr[i-1];
}

void PrintCalendarFullYear()
{
    int year = GetNumberyear();
    cout << endl << "_________________________" << endl;
    cout << "       Calendar - " << year << "        ";
    cout << endl << "_________________________" << endl;

    for (int i = 1; i <= 12; i++)
    {
        cout << endl << "______________________________" << Months(i) << "______________________________" << "\n";
        
        PrintCalendar(i, year);
        cout << endl;
    }


}

int main()
{
    PrintCalendarFullYear();
}

