#ifndef BILANS_H
#define BILANS_H

#include <iostream>

using namespace std;

class Bilans
{
    int amountId;
    int userId;
    string date;
    string item;
    string amount;

public:
    Bilans();
    void setAmountId (int amountId);
    void setUserId (int userId);
    void setDate (string date);
    void setItem (string item);
    void setAmount (string amount);

    int getAmountId();
    int getUserId();
    string getDate();
    string getItem();
    string getAmount();
};
#endif

