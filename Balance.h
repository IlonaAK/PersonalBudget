#ifndef BALANCE_H
#define BALANCE_H


#include <iostream>
#include <string>

using namespace std;

class Balance
{
    int userId;
    int amountId;
    // int date;
    string item;
    string amount;

public:
    Balance (int userId=0,int amountId=0, int date=0, string item="", string amount="")
    {
        this->userId=userId;
        this->amountId=amountId;
        this->date=date;
        this->item=item;
        this->amount=amount;
    };
    void setUserId (int userId);
    void setAmountId (int amountId);
    void setDate (int date);
    void setItem (string item);
    void setAmount (string amount);
    int date;
    int getUserId();
    int getAmountId();
    int getDate();
    string getItem();
    string getAmount();
};
#endif

