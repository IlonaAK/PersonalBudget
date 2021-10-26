#include "AuxiliaryMethods.h"

string AuxiliaryMethods::changeCommaToDot(string amount)
{
     for (int i=0; i<=amount.length()-1;++i)
   {
       if (amount[i]==',')
        amount [i]='.';
   }
   return amount;
}

string AuxiliaryMethods::convertIntToString(int integer)
{
    ostringstream ss;
    ss << integer;
    string str = ss.str();
    return str;
}

int AuxiliaryMethods::convertStringToInt(string word)
{
   int integer=atoi(word.c_str());
    return integer;
}

float AuxiliaryMethods::convertStringToFloat (string amount)
{
float fractionalNumber=atof(amount.c_str());

return fractionalNumber;
}

string AuxiliaryMethods::convertFirstLetterToCapitalAndOtherToLowercase(string text)
{
    if (!text.empty())
    {
        transform(text.begin(), text.end(), text.begin(), ::tolower);
        text[0] = toupper(text[0]);
    }
    return text;
}

char AuxiliaryMethods::loadSign()
{
    cin.sync();
    string enter = "";
    char sign  = {0};

    while (true)
    {
        getline(cin, enter);

        if (enter.length() == 1)
        {
            sign= enter[0];
            break;
        }
        cout << "To nie jest pojedy\344czy znak. Wpisz ponownie." << endl;
    }
    return sign;
}

string AuxiliaryMethods::loadLine()
{
    cin.sync();
    string enter = "";
    getline(cin, enter);
    return enter;
}
