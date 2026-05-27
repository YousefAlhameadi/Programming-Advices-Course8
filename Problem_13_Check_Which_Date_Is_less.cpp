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

string CheckLess(stDate Date1 , stDate Date2)
{
    if (Date1.Year < Date2.Year)
    {
        return "Yes , Date1 is Less than Date2 ";
    }
    else if (Date1.Year > Date2.Year)
    {
        return "No , Date1 is not Less than Date2";
    }
    else if(Date1.Month < Date2.Year)
    {
        return "Yes , Date1 is Less than Date2 ";
    }
    else if (Date1.Month > Date2.Month)
    {
        return "No , Date1 is not Less than Date2";
    }
    else if (Date1.Day < Date2.Day)
    {
        return "Yes , Date1 is Less than Date2 ";
    }
    else if (Date1.Day > Date2.Day)
    {
        return "No , Date1 is not Less than Date2";
    }

    return "Both Dates are Equal . ";
}


int main()
{
    stDate  Date1, Date2;

    cout  << "enter the first Date : " << endl << endl;
    
    Date1 = GetDate();

    cout << endl << "enter the second Date : " << endl << endl;

    Date2 = GetDate();

    cout << CheckLess(Date1,Date2);
}

