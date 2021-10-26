#include "BalanceManager.h"

void BalanceManager::addExpense()
{
    Expenses expense;
    system("cls");
    char choice='0';

    expense.setUserId(ID_LOGGED_USER);
    expense.setAmountId(getNewExpenseId());
    cout<< "-------Podaj dane wydatku------"<<endl<<endl;

    cout<<"Podaj dat\251 wydatku: "<<endl;
    cout<<"1. Dzisiejsza data."<<endl;
    cout<<"2. Wprowad\253 inn\245 dat\251 (RRRR-MM-DD)."<<endl;
    Calendar calendar;

    choice=AuxiliaryMethods::loadSign();
    switch (choice)
    {
    case ('1'):
    {
        expense.setDate(calendar.loadSystemData());
        cout<<"Wydatek zostanie wprowadzony z dzisiejsz\245 dat\245 "<< calendar.loadSystemData()<<endl;
        break;
    }
    case ('2'):
    {
        cout<<"Podaj dat\251: "<<endl;
        string date = AuxiliaryMethods::loadLine();

        if(calendar.checkIfDateIsValid(date)==true)
        {
            expense.setDate(calendar.convertDateToInt(date));
        }
        else
        {
            cout<<"Podano niepoprawn\245 dat\251"<<endl<<endl;
            system("pause");
        }
        break;
    }
    }
    cout<<"Podaj przyczyn\251 wydatku"<<endl;
    expense.setItem(AuxiliaryMethods::loadLine());

    cout<<"Podaj kwot\251: "<<endl;
    expense.setAmount(AuxiliaryMethods::changeCommaToDot(AuxiliaryMethods::loadLine()));

    expenses.push_back(expense);

    fileWithExpenses.addExpenseToFile(expense);
    cout << endl << "Wydatek dodany pomy\230lnie" << endl << endl;
    system("pause");

}
void BalanceManager::addIncome()
{
    Incomes income;
    system("cls");

    Calendar calendar;

    income.setUserId(ID_LOGGED_USER);
    income.setAmountId(getNewIncomeId());

    cout<< "-------Podaj dane przychodu------"<<endl<<endl;

    cout<<"Wybierz dat\251 przychodu: "<<endl;
    cout<<"1. Dzisiejsza data."<<endl;
    cout<<"2. Wprowad\253 inn\245 dat\251 (RRRR-MM-DD)."<<endl;

    char choice='0';
    choice=AuxiliaryMethods::loadSign();
    switch (choice)
    {
    case ('1'):
    {
        income.setDate(calendar.loadSystemData());
        cout<<"Przych\242d zostanie wprowadzony z dzisiejsz\245 dat\245 "<< calendar.loadSystemData()<<endl;
        break;
    }
    case ('2'):
    {
        cout<<"Podaj dat\251: "<<endl;
        string date=AuxiliaryMethods::loadLine();

        if(calendar.checkIfDateIsValid(date)==true)
            income.setDate(calendar.convertDateToInt(date));
        else
        {
            cout<<"Podano niepoprawn\245 dat\251"<<endl<<endl;
            system("pause");
            break;
        }
        break;
    }
    }
    cout<<"Podaj \253r\242d\210o przychodu"<<endl;
    income.setItem(AuxiliaryMethods::loadLine());

    cout<<"Podaj kwot\251: "<<endl;
    income.setAmount(AuxiliaryMethods::changeCommaToDot(AuxiliaryMethods::loadLine()));

    incomes.push_back(income);

    fileWithIncomes.addIncomeToFile(income);
    cout << endl << "Przych\242d dodany pomy\230lnie" << endl << endl;
    system("pause");


}

int BalanceManager::getNewIncomeId()
{
    if (incomes.empty() == true)
        return 1;
    else
        return incomes.back().getAmountId() + 1;
}

int BalanceManager::getNewExpenseId()
{
    if (expenses.empty() == true)
        return 1;
    else
        return expenses.back().getAmountId() + 1;
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
