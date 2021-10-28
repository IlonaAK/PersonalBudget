#ifndef AUXILIARYMETHODS_H
#define AUXILIARYMETHODS_H

#include <iostream>
#include <sstream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <algorithm>

using namespace std;

class AuxiliaryMethods
{
public:
    static int convertStringToInt(string word);
    static string convertIntToString(int integer);
    static float convertStringToFloat(string word);
    static string changeCommaToDot(string amount);
    static string convertFirstLetterToCapitalAndOtherToLowercase(string text);
    static char loadSign();
    static string loadLine();

};
#endif

