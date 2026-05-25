#include <iostream>
#include <string>

using namespace std;


int GetNumber()
{
    int Number;

    cout << "enter the number you want to convert :";
    cin >> Number;
    return Number;
}

string ConvertNumberToText(int number)
{
    if (number == 0)
    {
        return "";
    }
    if (number >= 1 && number <=19)
    {
        string arr[] = { "" , "one" , "two" , "three" ,"four" , "five" , "six" , "seven" , "eight" , "nine" , "ten" ,"eleven" , "twelve" , "thirteen" , "fourteen" ,"fifteen" , "sixteen" ,"seventeen" , "eighteen" , "ninrteen" };

        return arr[number] + " ";
    }
    if (number >=20 && number <=99)
    {
        string arr[] = {"","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety" };
        
        return arr[number / 10] + " " + ConvertNumberToText(number % 10);
    }
    if (number >= 100 && number <=199)
    {
        return "one hundred " + ConvertNumberToText(number % 100);
    }
    if (number >= 200 && number <=999)
    {
        return ConvertNumberToText(number / 100) + " hundreds " + ConvertNumberToText(number % 100);
    }
    if (number >= 1000 && number <=1999)
    {
        return "one thousand " + ConvertNumberToText(number%1000);
    }
    if (number >= 2000 && number<=99999)
    {
        return ConvertNumberToText(number / 1000) + "thousands " + ConvertNumberToText(number%1000);
    }
    if (number >= 1000000 && number <= 1999999)
    {
        return "One Million " + ConvertNumberToText(number % 1000000);
    }
    if (number >= 2000000 && number <= 999999999)
    {
        return ConvertNumberToText(number / 1000000) + "Millions " +
            ConvertNumberToText(number % 1000000);
    }
}


int main()
{
    int number = GetNumber();
   cout <<endl<< ConvertNumberToText(number);
}

