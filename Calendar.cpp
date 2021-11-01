#include "Calendar.h"


string Calendar::loadSystemData()
{
    string y, d, m;
    SYSTEMTIME st;
    GetSystemTime(&st);
    y=AuxiliaryMethods::convertIntToString(st.wYear);
    if (st.wMonth<10)
        m="0"+AuxiliaryMethods::convertIntToString(st.wMonth);
    else
        m=AuxiliaryMethods::convertIntToString(st.wMonth);
    if (st.wDay<10)
        d="0"+AuxiliaryMethods::convertIntToString(st.wDay);
    else
        d=AuxiliaryMethods::convertIntToString(st.wDay);

    return y+"-"+m+"-"+d;
}

bool Calendar::isLeap(int year)
{
    return (year % 4 == 0 && year % 100 != 0 || year % 400 == 0);
}

int Calendar::daysInMonth (int year, int month)
{
    switch (month)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        return 31;

    case 4:
    case 6:
    case 9:
    case 11:
        return 30;

    case 2:
        if(isLeap(year))
            return 29;

        else
            return 28;
    default:
        cout<< "Niepoprawnie wprowadzony miesiac." <<endl;
    }

    return 0;
}
int Calendar::yearFromString (string date)
{
    return AuxiliaryMethods::convertStringToInt(date.substr(0,4));
}
int Calendar::monthFromString (string date)
{
    return AuxiliaryMethods::convertStringToInt(date.substr(5,2));
}

int Calendar::dayFromString (string date)
{
    return AuxiliaryMethods::convertStringToInt(date.substr(8,2));
}

int Calendar::getDays(string date)
{
    int ans = 0;
    for (int i = 2000; i < yearFromString(date); ++ i)
    {
        if (isLeap(i))
        {
            ans += 366;
        }
        else
        {
            ans += 365;
        }
    }
    for (int i = 1; i < monthFromString(date); ++ i)
    {
        switch(i)
        {
        case 1:
            ans += 31;
            break;
        case 2:
            ans += isLeap(yearFromString(date)) ? 29 : 28;
            break;
        case 3:
            ans += 31;
            break;
        case 4:
            ans += 30;
            break;
        case 5:
            ans += 31;
            break;
        case 6:
            ans += 30;
            break;
        case 7:
            ans += 31;
            break;
        case 8:
            ans += 31;
            break;
        case 9:
            ans += 30;
            break;
        case 10:
            ans += 31;
            break;
        case 11:
            ans += 30;
            break;
        case 12:
            ans += 31;
            break;
        }
    }
    return ans += dayFromString(date) - 1;
}
int Calendar::daysBetweenDates(string firstDate, string endDate)
{
    return abs(getDays(firstDate) - getDays(endDate));
}

int Calendar::convertDateToInt(string date)
{
    date.erase(4,1);
    date.erase(6,1);

    return AuxiliaryMethods::convertStringToInt(date);
}

string Calendar::convertDateToString (int date)
{
    return AuxiliaryMethods::convertIntToString(date).insert(4, "-").insert(7,"-");
}

bool Calendar::checkIfDateIsValid(string date)
{
    int year = yearFromString(date);
    int month =monthFromString(date);
    int day = dayFromString(date);

    if(month>0&&month<=12)
    {
        if((month==1||month==3||month==5||month==7||month==8||month==10||month==12)&&(day>0&&day<=31))
        {
            return true;
        }
        else if ((month==4||month==6||month==9||month==11)&&(day<=30&&day>0))
        {
            return true;
        }
        else if(month==2)
        {
            if(isLeap(year)&&(day>0&&day<=29))
            {
                return true;
            }
            else if(day>0&&day<=28)
            {
                return true;
            }
            return false;
        }
        return false;
    }
    return false;
}

string Calendar::previousMonth()
{
    return (monthFromString(loadSystemData())-1>=10) ? AuxiliaryMethods::convertIntToString(monthFromString(loadSystemData())-1):
           "0"+ AuxiliaryMethods::convertIntToString(monthFromString(loadSystemData())-1);
}


