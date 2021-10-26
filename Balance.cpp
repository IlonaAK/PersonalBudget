#include "Balance.h"

void Balance::setUserId (int newUserId)
{
    if(newUserId >= 0)
    userId=newUserId;
}
void Balance::setAmountId (int newAmountId)
{
    if(newAmountId >= 0)
    amountId=newAmountId;
}

void Balance::setDate (int newDate)
{
    date=newDate;
}

void Balance::setItem (string newItem)
{
    item=newItem;
}
void Balance::setAmount (string newAmount)
{
    amount=newAmount;
}
int Balance::getUserId()
{
    return userId;
}
int Balance::getAmountId()
{
    return amountId;
}

int Balance::getDate()
{
    return date;
}

string Balance::getItem()
{
    return item;
}
string Balance::getAmount()
{
    return amount;
}
