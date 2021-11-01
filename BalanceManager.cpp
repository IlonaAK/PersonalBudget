#include "BalanceManager.h"

void BalanceManager::addExpense()
{
    Expenses expense;
    system("cls");
    char choice='0';

    expense.setUserId(ID_LOGGED_USER);
    expense.setAmountId(getNewExpenseId());
    cout << "-------Podaj dane wydatku------" << endl << endl;

    cout << "Podaj dat\251 wydatku: " << endl;
    cout << "1. Dzisiejsza data." << endl;
    cout << "2. Wprowad\253 inn\245 dat\251 (RRRR-MM-DD)." << endl;
    Calendar calendar;

    choice=AuxiliaryMethods::loadSign();
    switch (choice)
    {
        case ('1'):
        {
            expense.setDate(calendar.convertDateToInt(calendar.loadSystemData()));
            cout << "Wydatek zostanie wprowadzony z dzisiejsz\245 dat\245 " << calendar.loadSystemData() << endl;
            break;
        }
        case ('2'):
        {
            string date;
            do
            {
                cout << "Podaj dat\251: " << endl;
                date = AuxiliaryMethods::loadLine();

                if(calendar.checkIfDateIsValid(date))
                {
                    expense.setDate(calendar.convertDateToInt(date));
                }
                else
                {
                    cout << "Podano niepoprawn\245 dat\251" << endl << endl;
                    system("pause");
                }
            }
            while(!calendar.checkIfDateIsValid(date));
            break;
        }
    }
    cout << "Podaj przyczyn\251 wydatku" << endl;
    expense.setItem(AuxiliaryMethods::loadLine());

    cout << "Podaj kwot\251: "<< endl;
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

    cout << "-------Podaj dane przychodu------" << endl << endl;

    cout << "Wybierz dat\251 przychodu: " << endl;
    cout << "1. Dzisiejsza data." << endl;
    cout << "2. Wprowad\253 inn\245 dat\251 (RRRR-MM-DD)." << endl;

    char choice='0';
    choice=AuxiliaryMethods::loadSign();
    switch (choice)
    {
    case ('1'):
    {
        income.setDate(calendar.convertDateToInt(calendar.loadSystemData()));
        cout << "Przych\242d zostanie wprowadzony z dzisiejsz\245 dat\245 " << calendar.loadSystemData() << endl;
        break;
    }
    case ('2'):
    {
        string date;
        do
        {
            cout << "Podaj dat\251: " << endl;
            date=AuxiliaryMethods::loadLine();

            if(calendar.checkIfDateIsValid(date))
                income.setDate(calendar.convertDateToInt(date));
            else
            {
                cout << "Podano niepoprawn\245 dat\251" << endl << endl;
                system("pause");
            }
        }
        while(!calendar.checkIfDateIsValid(date));
        break;
    }
    }
    cout << "Podaj \253r\242d\210o przychodu" << endl;
    income.setItem(AuxiliaryMethods::loadLine());

    cout << "Podaj kwot\251: " << endl;
    income.setAmount(AuxiliaryMethods::changeCommaToDot(AuxiliaryMethods::loadLine()));

    incomes.push_back(income);

    fileWithIncomes.addIncomeToFile(income);
    cout << endl << "Przych\242d dodany pomy\230lnie" << endl << endl;
    system("pause");


}

int BalanceManager::getNewIncomeId()
{
    return ((fileWithIncomes.loadAllIncomesFromFile()).empty()) ? 1 : (fileWithIncomes.loadAllIncomesFromFile()).back().getAmountId() + 1;
}
int BalanceManager::getNewExpenseId()
{
    return ((fileWithExpenses.loadAllExpensesFromFile()).empty()) ? 1 : (fileWithExpenses.loadAllExpensesFromFile()).back().getAmountId() + 1;
}

void BalanceManager::balanceCurrentMonth()
{
    Calendar calendar;
    string dateFirst, dateLast;
    dateFirst=calendar.loadSystemData().replace(8,2, "01");
    dateLast=calendar.loadSystemData().replace(8,2,AuxiliaryMethods::convertIntToString(calendar.daysInMonth(calendar.yearFromString(calendar.loadSystemData()),calendar.monthFromString(calendar.loadSystemData()))));

    cout << "Bilans przychod\242w i wydatk\242w z aktualnego miesi\245ca" << endl;
    cout << "Od " << dateFirst << " do " << dateLast << endl << endl;

    float sumOfExpenses=0, sumOfIncomes=0;

    for (int i=0; i<incomes.size(); i++)
    {
        sort(incomes.begin(), incomes.end(), [](const Balance& a, const Balance&b)
        {
            return a.date<b.date;
        });

        if(calendar.convertDateToInt(dateFirst)<=incomes[i].getDate()&&incomes[i].getDate()<=calendar.convertDateToInt(dateLast))
        {
            cout << "Data przychodu: " << calendar.convertDateToString(incomes[i].getDate()) << "  \215r\242d\210o: " << incomes[i].getItem() << " Kwota: " << incomes[i].getAmount() << endl;

            sumOfIncomes+=AuxiliaryMethods::convertStringToFloat(incomes[i].getAmount());
        }
    }
    for (int i=0; i<expenses.size(); i++)
    {
        sort(expenses.begin(), expenses.end(), [](const Balance& a, const Balance&b)
        {
            return a.date<b.date;
        });

        if(calendar.convertDateToInt(dateFirst)<=expenses[i].getDate()&&expenses[i].getDate()<=calendar.convertDateToInt(dateLast))
        {

            cout<<"Data wydatku: "<<calendar.convertDateToString(expenses[i].getDate())<<"  Przyczyna: "<<expenses[i].getItem()<<" Kwota: "<<expenses[i].getAmount()<<endl;

            sumOfExpenses+=AuxiliaryMethods::convertStringToFloat(expenses[i].getAmount());
        }
    }
    cout << endl <<"Suma przychod\242w: " << sumOfIncomes<< endl << endl;
    cout << "Suma wydatk\242w: " << sumOfExpenses << endl << endl;
    cout << "Ko\344cowe saldo: " << sumOfIncomes-sumOfExpenses << endl << endl ;

    system("pause");

}

void BalanceManager::balancePreviousMonth()
{
    Calendar calendar;
    string dateFirst, dateLast;
    dateFirst=calendar.loadSystemData().replace(5,2,calendar.previousMonth()).replace(8,2,"01");
    dateLast=calendar.loadSystemData().replace(5,2,calendar.previousMonth()).replace(8,2,AuxiliaryMethods::convertIntToString(calendar.daysInMonth(calendar.yearFromString(calendar.loadSystemData()),AuxiliaryMethods::convertStringToInt(calendar.previousMonth()))));
    cout << "Bilans przychod\242w i wydatk\242w z poprzedniego miesi\245ca" << endl;

    cout<<"Od "<<dateFirst<<" do "<<dateLast<<endl<<endl;

    float sumOfExpenses=0, sumOfIncomes=0;

    for (int i=0; i<incomes.size(); i++)
    {
        sort(incomes.begin(), incomes.end(), [](const Balance& a, const Balance&b)
        {
            return a.date<b.date;
        });
        if(calendar.convertDateToInt(dateFirst)<=incomes[i].getDate()&&incomes[i].getDate()<=calendar.convertDateToInt(dateLast))
        {
            cout << "Data przychodu: " << calendar.convertDateToString(incomes[i].getDate()) << "  \215r\242d\210o: " << incomes[i].getItem() << " Kwota: " << incomes[i].getAmount() << endl;
            sumOfIncomes+=AuxiliaryMethods::convertStringToFloat(incomes[i].getAmount());
        }
    }
    for (int i=0; i<expenses.size(); i++)
    {
        sort(expenses.begin(), expenses.end(), [](const Balance& a, const Balance&b)
        {
            return a.date<b.date;
        });
        if(calendar.convertDateToInt(dateFirst)<=expenses[i].getDate()&&expenses[i].getDate()<=calendar.convertDateToInt(dateLast))
        {
            cout << "Data wydatku: " << calendar.convertDateToString(expenses[i].getDate()) << "  Przyczyna: " << expenses[i].getItem() << " Kwota: " << expenses[i].getAmount() << endl;
            sumOfExpenses+=AuxiliaryMethods::convertStringToFloat(expenses[i].getAmount());
        }

    }
    cout << endl << "Suma przychod\242w: " << sumOfIncomes << endl << endl;
    cout << "Suma wydatk\242w: " << sumOfExpenses << endl << endl;
    cout << "Ko\344cowe saldo: " << sumOfIncomes-sumOfExpenses << endl << endl;

    system("pause");

}
void BalanceManager::balanceSelectedPeriod()
{
    Calendar calendar;
    string dateFirst, dateLast;
    cout << "Podaj z jakiego okresu chcesz zobaczy\206 bilans przychod\242w i wydatk\242w." << endl;
    cout << "Podaj dat\251 rozpoczynaj\245c\245 wybrany okres (RRRR-MM-DD): " << endl;
    cin >> dateFirst;
    cout << "Podaj dat\251 ko\344cz\245c\245 wybrany okres (RRRR-MM-DD): " << endl;
    cin >> dateLast;
    cout << "Bilans przychod\242w i wydatk\242w z wybranego okresu" << endl;

    cout << "Od "<< dateFirst << " do " << dateLast << endl << endl;

    float sumOfExpenses=0, sumOfIncomes=0;

    for (int i=0; i<incomes.size(); i++)
    {
        sort(incomes.begin(), incomes.end(), [](const Balance& a, const Balance&b)
        {
            return a.date<b.date;
        });

        if(calendar.convertDateToInt(dateFirst)<=incomes[i].getDate()&&incomes[i].getDate()<=calendar.convertDateToInt(dateLast))
        {
            cout << "Data przychodu: " << calendar.convertDateToString(incomes[i].getDate())<< "  \215r\242d\210o: " << incomes[i].getItem() << " Kwota: " << incomes[i].getAmount() << endl;
            sumOfIncomes+=AuxiliaryMethods::convertStringToFloat(incomes[i].getAmount());
        }
    }
    for (int i=0; i<expenses.size(); i++)
    {
        sort(expenses.begin(), expenses.end(), [](const Balance& a, const Balance&b)
        {
            return a.date<b.date;
        });
        if(calendar.convertDateToInt(dateFirst)<=expenses[i].getDate()&&expenses[i].getDate()<=calendar.convertDateToInt(dateLast))
        {
            cout << "Data wydatku: " << calendar.convertDateToString(expenses[i].getDate()) << "  Przyczyna: " << expenses[i].getItem() << " Kwota: " << expenses[i].getAmount() << endl;
            sumOfExpenses+=AuxiliaryMethods::convertStringToFloat(expenses[i].getAmount());
        }
    }
    cout << endl << "Suma przychod\242w: " << sumOfIncomes << endl << endl;
    cout << "Suma wydatk\242w: " << sumOfExpenses << endl << endl;
    cout << "Ko\344cowe saldo: " << sumOfIncomes-sumOfExpenses << endl << endl;

    system("pause");
}

