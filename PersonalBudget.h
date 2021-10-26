#ifndef PERSONALBUDGET_H
#define PERSONALBUDGET_H

#include <iostream>
#include "UserManager.h"
#include "AuxiliaryMethods.h"
#include <windows.h>
#include "BalanceManager.h"
#include "FileWithExpenses.h"
#include "FileWithIncomes.h"

using namespace std;

class PersonalBudget
{
    UserManager userManager;
    BalanceManager *balanceManager;
    const string NAME_FILE_WITH_EXPENSES;
    const string NAME_FILE_WITH_INCOMES;

    void viewMainMenu();
    void viewUserMenu();
    void signupUser();
    void userRegistration();
    void logoutUser();

public:
    PersonalBudget(string nameFileWithUsers, string nameFileWithIncomes, string nameFileWithExpenses): userManager(nameFileWithUsers), NAME_FILE_WITH_INCOMES(nameFileWithIncomes), NAME_FILE_WITH_EXPENSES(nameFileWithExpenses)
    {
        balanceManager=NULL;
        mainMenu();
    };

    ~PersonalBudget()
    {
        delete balanceManager;
        balanceManager = NULL;
    };
    void mainMenu();
    void userMenu();

};
#endif
