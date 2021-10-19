#include "BalanceManager.h"

void BalanceManager::addExpense()
{
    Balance balance;
    system("cls");

    Calendar calendar;

    balance.setUserId(ID_LOGGED_USER);
    balance.setAmountId(getNewAmountId()+1);

    cout<< "-------Podaj dane wydatku------"<<endl<<endl;

    cout<<"Wybierz dat\251 wydatku: "<<endl;
    cout<<"1. Dzisiejsza data."<<endl;
    cout<<"2. Wprowad\253 inn\245 dat\251."<<endl;

    char choice='0';
    choice=AuxiliaryMethods::loadSign();
    switch (choice)
    {

    case ('1'):
    {
        balance.setDate(calendar.convertDateToInt(calendar.loadSystemData()));
    }
    case ('2'):
    {
       string date;
       cin>>date;
       if(calendar.checkIfDateIsValid(date)==true)
       balance.setDate(calendar.convertDateToInt(date));
       else
       {
        cout<<"Podano niepoprawn\245 dat\251";
       }
        break;
    }
    }
    cout<<"Podaj kwot\251: "<<endl;
    string amount;
    cin>>amount;
    balance.setAmount(AuxiliaryMethods::changeCommaToDot(amount));

    cout<<"Podaj przyczyn\251 wydatku"<<endl;
    string item;
    cin>>item;
    balance.setItem(item);

   expenses.push_back(balance);

//    fileWithExpenses.addExpenceToFile(balance);
    cout << endl << "Wydatek dodany pomy\230lnie" << endl << endl;
    system("pause");

}
void BalanceManager::addIncome()
{
    Balance balance;
    system("cls");

    Calendar calendar;

    balance.setUserId(ID_LOGGED_USER);
    balance.setAmountId(getNewAmountId()+1);

    cout<< "-------Podaj dane przychodu------"<<endl<<endl;

    cout<<"Wybierz dat\251 przychodu: "<<endl;
    cout<<"1. Dzisiejsza data."<<endl;
    cout<<"2. Wprowad\253 inn\245 dat\251."<<endl;

    char choice='0';
    choice=AuxiliaryMethods::loadSign();
    switch (choice)
    {

    case ('1'):
    {
        balance.setDate(calendar.convertDateToInt(calendar.loadSystemData()));
    }
    case ('2'):
    {
       string date;
       cin>>date;
       if(calendar.checkIfDateIsValid(date)==true)
       balance.setDate(calendar.convertDateToInt(date));
       else
       {
        cout<<"Podano niepoprawn\245 dat\251";
       }
        break;
    }
    }
    cout<<"Podaj kwot\251: "<<endl;
    string amount;
    cin>>amount;
    balance.setAmount(AuxiliaryMethods::changeCommaToDot(amount));

    cout<<"Podaj \253r\242d\210o przychodu"<<endl;
    string item;
    cin>>item;
    balance.setItem(item);

    incomes.push_back(balance);

//    fileWithIncomes.addIncomeToFile(balance);
    cout << endl << "Przych\242d dodany pomy\230lnie" << endl << endl;
    system("pause");

}

int BalanceManager::getNewAmountId()
{

}

void BalanceManager::balanceCurrentMoth()
{

}

void BalanceManager::balancePreviousMonth()
{

}
void BalanceManager::balanceSelectedMonth()
{

}
