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

int CheckMonths(short month, short Year)
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

bool Check_Last_day(short Day, short Month, short Year)
{
    return (Day == CheckMonths(Month, Year));

}

bool Check_If_first_Day(short Day)
{
    return (Day == 1);
}

bool Check_First_Month(short Month)
{
    return (Month == 1);
}

stDate DecreaseDay(stDate Date1)
{

    if (Check_First_Month(Date1.Month) && Check_If_first_Day(Date1.Day))
    {

        Date1.Month = 12;
        Date1.Year = Date1.Year - 1;
        Date1.Day = CheckMonths(Date1.Month, Date1.Year);
    }
     else if (Check_If_first_Day(Date1.Day))
    {
        Date1.Month = Date1.Month - 1;
        Date1.Day = CheckMonths(Date1.Month, Date1.Year);
    }
    else
    {
        Date1.Day -= 1;
    }

    return Date1;

}

stDate DecreaseXDays(stDate Date1, int Days)
{
    for (int i = 0; i < Days; i++)
    {
        Date1 = DecreaseDay(Date1);
    }
    return Date1;
}

stDate DecreaseOneWeek(stDate Date1)
{
    Date1 = DecreaseXDays(Date1, 7);
    return Date1;
}

stDate DecreaseXweeks(stDate Date1 , int weeks)
{
    return Date1 = DecreaseXDays(Date1 , (weeks * 7));
}

stDate DecreaseOneMonth(stDate Date1)
{
    for (int i = 0; i < CheckMonths(Date1.Month,Date1.Year); i++)
    {
        Date1 = DecreaseDay(Date1);
    }
    return Date1;
}

stDate DecreaseXMonths(stDate Date1 , int Months)
{
    for (int i = 0; i < Months; i++)
    {
        Date1 = DecreaseOneMonth(Date1);
    }
    return Date1;
}

stDate DecreaseOneYear(stDate Date1)
{
     Date1.Year--;
     return Date1;
}

stDate DecreaseXYears(stDate Date1 , int years)
{
    Date1.Year -= years;

    return Date1;
}

stDate DecreaseOneDecade(stDate Date1)
{
    Date1.Year -= 10;
    return Date1;
}

stDate DecreaseXDecade(stDate Date1 , short Decades)
{
    Date1 = DecreaseXYears(Date1 , (Decades*10));
    return Date1;
}

stDate DecreaseOneCentury(stDate Date1)
{
    Date1  = DecreaseXDecade(Date1,10);
    return Date1;
}

stDate DecreaseOneMillennium(stDate Date1)
{
    Date1  = DecreaseXDecade(Date1,100);
    return Date1;
}

int main()
{
    stDate Date = GetDate();

    cout << endl << "Date After : " << endl;


    Date = DecreaseDay(Date);
    cout << "Date After Subtracting One Day : " << Date.Day << " / " << Date.Month << " / " << Date.Year << endl;

    Date = DecreaseXDays(Date,10);
    cout << "Date After Subtracting 10 Days : " << Date.Day << " / " << Date.Month << " / " << Date.Year << endl;

    Date = DecreaseOneWeek(Date);
    cout << "Date After Subtracting one week : " << Date.Day << " / " << Date.Month << " / " << Date.Year << endl;

    Date = DecreaseXweeks(Date , 10);
    cout << "Date After Subtracting 10 week : " << Date.Day << " / " << Date.Month << " / " << Date.Year << endl;

    Date = DecreaseOneMonth(Date);
    cout << "Date After Subtracting one month : " << Date.Day << " / " << Date.Month << " / " << Date.Year << endl;

    Date = DecreaseXMonths(Date, 5);
    cout << "Date After Subtracting five months : " << Date.Day << " / " << Date.Month << " / " << Date.Year << endl;

    Date = DecreaseOneYear(Date);
    cout << "Date After Subtracting one year : " << Date.Day << " / " << Date.Month << " / " << Date.Year << endl;

    Date = DecreaseXYears(Date,10);

    cout << "Date After Subtracting 10 years : " << Date.Day << " / " << Date.Month << " / " << Date.Year << endl;

    Date = DecreaseOneDecade(Date);
    cout << "Date After Subtracting one Decade : " << Date.Day << " / " << Date.Month << " / " << Date.Year << endl;

    Date = DecreaseXDecade(Date , 10);
    cout << "Date After Subtracting 10 Decades : " << Date.Day << " / " << Date.Month << " / " << Date.Year << endl;

    Date = DecreaseOneCentury(Date);
    cout << "Date After Subtracting one Century : " << Date.Day << " / " << Date.Month << " / " << Date.Year << endl;


    Date = DecreaseOneCentury(Date);
    cout << "Date After Subtracting one Century : " << Date.Day << " / " << Date.Month << " / " << Date.Year << endl;

    Date = DecreaseOneMillennium(Date);
    cout << "Date After Subtracting one Millennium : " << Date.Day << " / " << Date.Month << " / " << Date.Year << endl;
}