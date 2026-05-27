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

bool CheckEqualDates(stDate Date1,stDate Date2)
{
    return (Date1.Year == Date2.Year) && (Date1.Month == Date2.Month) && (Date1.Day == Date2.Day);
}

int main()
{
    stDate  Date1, Date2;

    cout << "enter the first Date : " << endl << endl;

    Date1 = GetDate();

    cout << endl << "enter the second Date : " << endl << endl;

    Date2 = GetDate();

    if (CheckEqualDates(Date1,Date2) == true)
    {
        cout << endl << "Yes Dates are Equal";
    }
    else
    {
        cout << endl << "No Dates are Not Equal";
    }

}


