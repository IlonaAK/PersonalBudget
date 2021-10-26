#ifndef BALANCEMANAGER_H
#define BALANCEMANAGER_H

#include <iostream>
#include "AuxiliaryMethods.h"
#include "Calendar.h"
#include <vector>
#include <windows.h>
#include <sstream>
#include "Incomes.h"
#include "Expenses.h"
#include "FileWithExpenses.h"
#include "FileWithIncomes.h"

using namespace std;

class BalanceManager
{
    const int ID_LOGGED_USER;
    vector <Incomes> incomes;
    vector <Expenses> expenses;

    FileWithIncomes fileWithIncomes;
    FileWithExpenses fileWithExpenses;

    int getNewIncomeId();
    int getNewExpenseId();
    int getIdLoggedUser();

public:
    BalanceManager(string nameFileWithIncomes, string nameFileWithExpenses, int idLoggedUser)
        : fileWithIncomes(nameFileWithIncomes), fileWithExpenses (nameFileWithExpenses), ID_LOGGED_USER(idLoggedUser)
    {
        incomes=fileWithIncomes.loadIncomesFromFile(ID_LOGGED_USER);
        expenses=fileWithExpenses.loadExpensesFromFile(ID_LOGGED_USER);
    };
    void addIncome();
    void addExpense();
    void balanceCurrentMoth();
    void balancePreviousMonth();
    void balanceSelectedMonth();

};
#endif
