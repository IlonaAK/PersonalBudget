#ifndef CALENDAR_H
#define CALENDAR_H

#include <iostream>
#include <windows.h>
#include <winbase.h>

#include "AuxiliaryMethods.h"

using namespace std;

class Calendar
{
    int year;
    int month;
    int day;
    string date;
public:

    string loadSystemData();
    int daysInMonth(int year, int month);
    bool isLeap(int year);
    int yearFromString(string date);
    int monthFromString(string date);
    int dayFromString(string date);
    int getDays(string date);
    int daysBetweenDates(string firstDate, string endDate);
    int convertDateToInt(string date);
    bool checkIfDateIsValid(string date);

};
#endif
