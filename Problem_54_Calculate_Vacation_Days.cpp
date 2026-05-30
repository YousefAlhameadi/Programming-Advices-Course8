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

short IndexOfDay(short year, short month, short day)
{
    short a = ((14 - month) / 12);
    short y = year - a;
    short m = month + (12 * a) - 2;

    return (day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;

}

short IndexOfDay(stDate Date)
{
    return IndexOfDay(Date.Year, Date.Month, Date.Day);

}

string WeekDays(short index)
{
    string DayArr[7] = { "Sun" , "Mon" , "Tue" ,"Wed" , "Thu" , "Fri" , "Sat" };
    return DayArr[index];
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

bool IsWeekend(string NameOfDay)
{
    return (NameOfDay == "Sat" || NameOfDay == "Fri") ? true : false;
}

bool Check_Last_Month(short Month)
{
    return (Month == 12);
}

bool Check_Last_day(short Day, short Month, short Year)
{
    return (Day == CheckMonths(Month, Year));

}

bool Check_If_First_Date_Is_Less(stDate Date1, stDate Date2)
{
    return (Date1.Year < Date2.Year) ? true : (Date1.Month < Date2.Month) ? true : (Date1.Day < Date2.Day) ? true : false;
}

bool CheckEqualDates(stDate Date1, stDate Date2)
{
    return (Date1.Year == Date2.Year) && (Date1.Month == Date2.Month) && (Date1.Day == Date2.Day);
}

stDate AddDay(stDate Date1)
{

    if (Check_Last_day(Date1.Day, Date1.Month, Date1.Year))
    {
        if (Check_Last_Month(Date1.Month))
        {
            Date1.Day = 1;
            Date1.Month = 1;
            Date1.Year += 1;
        }
        else
        {
            Date1.Day = 1;
            Date1.Month += 1;
        }
    }

    else
    {
        Date1.Day += 1;
    }

    return Date1;

}

short Diff_Between_Two_Dates(stDate Date1, stDate Date2, bool IncludeFirstDay = false) // the Function is updated to calculate the difference even if Date1 is not less than Date2 but if Date2 is less than Date1 it will calculate the difference in negative days.
{
    short counter = 0;

    if (Check_If_First_Date_Is_Less(Date1, Date2))
    {
        while (CheckEqualDates(Date1, Date2) == false)
        {
            Date1 = AddDay(Date1);
            counter += 1;
        }
        (IncludeFirstDay == true ? counter = counter + 1 : counter);
    }
    else if (!Check_If_First_Date_Is_Less(Date1, Date2))
    {
        while (CheckEqualDates(Date1, Date2) == false)
        {
            Date2 = AddDay(Date2);
            counter -= 1;
        }
        (IncludeFirstDay == true ? counter = counter - 1 : counter);
    }
    return counter;
}



short Calc_Total_Vaction_Days(stDate Date1, stDate Date2)
{

    short counter = Diff_Between_Two_Dates(Date1, Date2,true);

    for (int i = 0; i < counter+1; i++)
    {
        if (IsWeekend(WeekDays(IndexOfDay(Date1))))
        {
            counter = counter - 1;

        }
        Date1 = AddDay(Date1);
    }

    return counter;

}

int main()
{
    cout << "Vacation Start : "<<endl;

    stDate VacationStart = GetDate();

    cout << "Vacation ends : " << endl;

    stDate VacationEnd = GetDate();

    cout << "Vacation From : " << WeekDays(IndexOfDay(VacationStart)) << " , " <<VacationStart.Day << " / " << VacationStart.Month << " / " << VacationStart.Year << endl;

    cout << "Vacation To : " << WeekDays(IndexOfDay(VacationEnd)) << " , " << VacationEnd.Day << " / " << VacationEnd.Month << " / " << VacationEnd.Year << endl;

    cout << endl << "Vacation Days are : " << Calc_Total_Vaction_Days(VacationStart, VacationEnd);
}


