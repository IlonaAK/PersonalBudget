#ifndef BILANSMANAGER_H
#define BILANSMSNAGER_H

#include <iostream>
#include "AuxiliaryMethods.h"
#include "Calendar.h"
#include "Balance.h"+
#include <vector>
#include "FileWithExpenses.h"
#include "FileWithIncomes.h"

using namespace std;

class BalanceManager
{
    const int ID_LOGGED_USER;
    vector <Balance> incomes;
    vector <Balance> expenses;
    int getIdLoggedUser();
    int getNewAmountId();

public:
    BalanceManager();
    void addExpense();
    void addIncome();
    void balanceCurrentMoth();
    void balancePreviousMonth();
    void balanceSelectedMonth();

};
#endif
