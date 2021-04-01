#include "Calendar.h"


string Calendar::loadSystemData ()
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

    string date=y+"-"+m+"-"+d;
    return date;
}
bool Calendar::isLeap(int year)
{
        if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
            return true;
        else
            return false;

}

int Calendar::daysInMonth (int year, int month)
{
    switch (month)
    {
    case 1: case 3: case 5: case 7: case 8: case 10: case 12:
    return 31;

    case 4: case 6: case 9: case 11:
    return 30;

    case 2:
    if(isLeap(year))
    return 29;

    else
    return 28;
    default: cout<< "Niepoprawnie wprowadzony miesiac." <<endl;
    }

    return 0;
}
int Calendar::yearFromString (string date)
{
    int year;
    return year=AuxiliaryMethods::convertStringToInt(date.substr(0,4));
}
int Calendar::monthFromString (string date)
{
    int month;
    return month=AuxiliaryMethods::convertStringToInt(date.substr(5,2));
}

int Calendar::dayFromString (string date)
{
    int day;
    return day=AuxiliaryMethods::convertStringToInt(date.substr(8,2));
}

int Calendar::getDays(string date)
{
        int year = yearFromString(date);
        int month =monthFromString(date);
        int day = dayFromString(date);
        int ans = 0;
        for (int i = 2000; i < year; ++ i) {
            if (isLeap(i)) {
                ans += 366;
            } else {
                ans += 365;
            }
        }
        for (int i = 1; i < month; ++ i) {
            switch(i) {
                case 1: ans += 31; break;
                case 2: ans += isLeap(year) ? 29 : 28; break;
                case 3: ans += 31; break;
                case 4: ans += 30; break;
                case 5: ans += 31; break;
                case 6: ans += 30; break;
                case 7: ans += 31; break;
                case 8: ans += 31; break;
                case 9: ans += 30; break;
                case 10: ans += 31; break;
                case 11: ans += 30; break;
                case 12: ans += 31; break;
            }
        }
        return ans += day - 1;
    }
int Calendar::daysBetweenDates(string firstDate, string endDate)
{
        return abs(getDays(firstDate) - getDays(endDate));
}
