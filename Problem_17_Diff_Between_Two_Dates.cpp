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

bool Check_If_First_Date_Is_Less(stDate Date1 , stDate Date2)
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

short Diff_Between_Two_Dates(stDate Date1, stDate Date2 , bool IncludeFirstDay = false)
{
    short counter = 0;
    if(Check_If_First_Date_Is_Less(Date1,Date2))
    {
        while (CheckEqualDates(Date1, Date2) == false)
        {
            Date1 = AddDay(Date1);
            counter += 1;
        }

    }
    else
    {
        return -2;
    }
        
    (IncludeFirstDay == true ?  counter = counter + 1 : counter);
    
    return counter;
}

int main()
{
    cout << "enter the first Date : " << endl;
    stDate Date1 = GetDate();
    cout << "enter the second Date : " << endl;
    stDate Date2 = GetDate();

    short DiffBetweenTwoDates = Diff_Between_Two_Dates(Date1,Date2);
    short DiffBetweenTwoDatesWithFirstDay = Diff_Between_Two_Dates(Date1, Date2, true);

    if (DiffBetweenTwoDates == -2)
    {
        cout << "Invaild Input First Date Should Be less Than Second Date";
    }
    else
    {
        cout << "The Diffrence Between Two Dates is : " << DiffBetweenTwoDates << "Day(s)" << endl;
        cout << "The Diffrence Between Two Dates is Including First Day: " << DiffBetweenTwoDatesWithFirstDay << "Day(s)";
    }
}


