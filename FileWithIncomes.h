#ifndef FILEWITHINCOMES_H
#define FILEWITHINCOMES_H

#include <iostream>
#include "File.h"
#include <vector>
#include "Incomes.h"
#include "Markup.h"
#include "AuxiliaryMethods.h"

using namespace std;

class FileWithIncomes: public File
{
    const string NAME_FILE_WITH_INCOMES;
    int idOfLastIncome;

public:
    FileWithIncomes(string nameFileWithIncomes): NAME_FILE_WITH_INCOMES(nameFileWithIncomes)
    {
        idOfLastIncome=0;
    };

    void addIncomeToFile(Incomes incomes);
    vector <Incomes> loadIncomesFromFile (int idLoggedUser);
    vector <Incomes> loadAllIncomesFromFile();
};
#endif
