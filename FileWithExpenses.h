#ifndef FILEWITHEXPENSES_H
#define FILEWITHEXPENSES_H

#include <iostream>
#include <vector>
#include "File.h"
#include "Balance.h"

using namespace std;

class FileWithExpenses: public File
{
    const string NAME_FILE_WITH_EXPENSES;

    getDataExpense(string expenseData);
    int idOfLastExpense;

public:
    FileWithExpenses(string nameFileWithExpenses): NAME_FILE_WITH_EXPENSES(nameFileWithExpenses){
    idOfLastExpense=0;
    };
    void addExpenseToFile(Balance balance);
    vector <Balance> loadExpensesFromFile ();
    void saveAllExpensesToFile(vector <Balance> &expenses);
};
#endif
