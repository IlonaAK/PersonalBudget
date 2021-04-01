#include "PersonalBudget.h"

void PersonalBudget::userRegistration()
{
    userManager.userRegistration();
}

void PersonalBudget::viewMainMenu()
{
    system("cls");
    cout << "        MENU  G\235\340WNE   " << endl;
    cout << "*****************************" << endl;
    cout << "1. Rejestracja" << endl;
    cout << "2. Logowanie" << endl;
    cout << "3. Koniec programu" << endl;
    cout << "*****************************" << endl;
    cout << "Twoj wyb\242r: ";
}

void PersonalBudget::signupUser()
{
    userManager.signupUser();
}

void PersonalBudget::mainMenu()
{
    char choice='0';
    do
    {
        viewMainMenu();
        choice=AuxiliaryMethods::loadSign();
        switch (choice)
        {
        case ('2'):
        {
            cout <<endl<< "LOGOWANIE"<<endl;
             signupUser();
            if (userManager.getIdLoggedinUser()!=0)
                userMenu();
            break;
        }
        case ('1'):
        {
            cout <<endl<< "REJESTRACJA"<<endl;
            userRegistration();
            break;
        }


        case ('3'):
        {
            exit(0);

        }
        default:
            cout <<endl<< "Niepoprawny wyb\242r";
            Sleep(1000);
            break;
        }

    }
    while (choice!=3);
}

void PersonalBudget::viewUserMenu()
{
     system("cls");
                cout<<"    MENU U\275YTKOWNIKA"<<endl;
                cout<<"******************************"<<endl;
                cout << "1. Dodaj przych\242d"<<endl;
                cout << "2. Dodaj wydatek"<<endl;
                cout << "3. Bilans z bie\276\245cego miesi\245ca"<<endl;
                cout << "4. Bilans z poprzedniego miesi\245ca"<<endl;
                cout << "5. Bilans z wybranego miesi\245ca"<<endl;
                cout << "6. Zmie\344 has\210o" <<endl;
                cout << "8. Wyloguj si\251" <<endl;
                cout << "Tw\242j wyb\242r: ";
}
void PersonalBudget::userMenu()
{
    char choice='0';
    do
    {
        viewUserMenu();
        //personalBudget = new personalBudget();
        choice=AuxiliaryMethods::loadSign();
        switch (choice)
        {
        case ('1'):
        {
         //   bilansManager->addIncome();
            break;

        }
        case ('2'):
        {
          //  bilansManager->addExpense();
            break;
        }
        case ('3'):
        {
         //   bilansManager->balanceCurrentMonth();
            break;
        }
        case ('4'):
        {
          //  bilansManager->balancePreviousMonth();
            system("pause");
            break;
        }
         case ('5'):
        {
          //  bilansManager->balanceSelectedMonth();
            system("pause");
            break;
        }
        case ('6'):
        {
          //  userManager->changePassword();
            break;
        }

        case ('8'):
        {
            logoutUser();
            mainMenu();
            break;
        }
        default:
            cout <<endl<< "Niepoprawny wyb\242r";
            Sleep(1500);
            break;
        }
    }
    while (choice!=8);
}


void PersonalBudget::logoutUser(){
    userManager.logoutUser();
//    delete bilansManager;
//    bilansManager = NULL;
}
