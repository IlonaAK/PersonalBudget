#ifndef FILEWITHINCOMES_H
#define FILEWITHINCOMES_H

#include <iostream>
#include "File.h"
#include <vector>
#include "Balance.h"

using namespace std;

class FileWithIncomes: public File
{
    const string NAME_FILE_WITH_INCOMES;
    getDataIncome(string incomeData);
    int idOfLastIncome;

public:

    FileWithIncomes(string nameFileWithIncomes): NAME_FILE_WITH_INCOMES(nameFileWithIncomes){
    idOfLastIncome=0;
    };

    void addIncomeToFile(Balance balance);
    vector <Balance> loadIncomesFromFile ();
    void saveAllIncomesToFile(vector <Balance> &incomes);
};
#endif
