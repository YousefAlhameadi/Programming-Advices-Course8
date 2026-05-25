#include <iostream>

using namespace std;

int ReadNum()
{
    int Year;
    cout << "enter the year you want to check : ";
    cin >> Year;

    return Year;

}

bool CheckIfLeep(int Year)
{
    if ((Year % 400) == 0)
    {
        return true;
    }
    if ((Year % 4)  == 0 && (Year % 100) != 0)
    {
            return true;   
    }
 
       return false;
    
}

// the fun do the same thing as the last fun but we are going to write one line of code only 
bool isLeepYear(int Year)
{
    return ((Year % 400) == 0) || ((Year % 4 == 0) && (Year % 100 != 0));
}

int main()
{
    int Year = ReadNum();

    /*
    if (CheckIfLeep(Year) == true)
    {
        cout << endl << "the year is a leep year ";
    }
    if (CheckIfLeep(Year) != true)
    {
        cout << endl << "the year is not a leep year ";
    }
    
    */

    if (isLeepYear(Year) == true)
    {
        cout << endl << "the year is a leep year ";
    }
    if (isLeepYear(Year) == false)
    {
        cout << endl << "the year is not a leep year ";
    }
}
