#ifndef FILEWITHEXPENSES_H
#define FILEWITHEXPENSES_H

#include <iostream>
#include <vector>
#include "File.h"
#include "Expenses.h"
#include "AuxiliaryMethods.h"
#include "Markup.h"

using namespace std;

class FileWithExpenses: public File
{
    const string NAME_FILE_WITH_EXPENSES;
    int idOfLastExpense;

public:
    FileWithExpenses(string nameFileWithExpenses): NAME_FILE_WITH_EXPENSES(nameFileWithExpenses)
    {
        idOfLastExpense=0;
    };
    void addExpenseToFile(Expenses expenses);
    vector <Expenses> loadExpensesFromFile (int idLoggedUser);
    vector <Expenses> loadAllExpensesFromFile();
};
#endif
