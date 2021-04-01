#ifndef PERSONALBUDGET_H
#define PERSONALBUDGET_H

#include <iostream>
#include "UserManager.h"
#include "AuxiliaryMethods.h"
#include <windows.h>
#include "BilansManager.h"

using namespace std;

class PersonalBudget
{
    UserManager userManager;
    BilansManager *bilansManager;
    //const string nameFileWith;


    void viewMainMenu();
    void viewUserMenu();
    void signupUser();
    void userRegistration();
    void logoutUser();

public:
    PersonalBudget(MainMenu()) {
        ;
    };
    void mainMenu();
    void userMenu();
};
#endif
