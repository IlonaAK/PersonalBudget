#ifndef BALANCE_H
#define BALANCE_H


#include <iostream>

using namespace std;

class Balance
{
    int amountId;
    int userId;
    string date;
    string item;
    string amount;

public:
    void setAmountId (int amountId);
    void setUserId (int userId);
    void setDate (int date);
    void setItem (string item);
    void setAmount (string amount);

    int getAmountId();
    int getUserId();
    string getDate();
    string getItem();
    string getAmount();
};
#endif

