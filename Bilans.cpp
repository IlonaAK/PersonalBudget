#include "Bilans.h"

void Bilans::setAmountId (int newAmountId)
{
    if(newAmountId >= 0)
    amountId=newAmountId;
}
void Bilans::setUserId (int newUserId)
{
    if(newUserId >= 0)
    userId=newUserId;
}

void Bilans::setDate (string newDate)
{
    date=newDate;
}

void Bilans::setItem (string newItem)
{
    item=newItem;
}
void Bilans::setAmount (string newAmount)
{
    amount=newAmount;
}

int Bilans::getAmountId()
{
    return amountId;
}
int Bilans::getUserId()
{
    return userId;
}

string Bilans::getDate()
{
    return date;
}

string Bilans::getItem()
{
    return item;
}
string Bilans::getAmount()
{
    return amount;
}
