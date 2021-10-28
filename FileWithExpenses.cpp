#include "FileWithExpenses.h"

void FileWithExpenses::addExpenseToFile(Expenses expenses)
{
    CMarkup xml;

    bool fileExists = xml.Load( "expenses.xml" );

    if (!fileExists)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Expenses");
        xml.IntoElem();
    }
    else
    {
        xml.Load( "expenses.xml" );
        xml.FindElem("Expenses");
        xml.IntoElem();
    }
    xml.AddElem("Expense");
    xml.IntoElem();
    xml.AddElem("UserId",expenses.getUserId());
    xml.AddElem("AmountId", expenses.getAmountId());
    xml.AddElem("Date", expenses.getDate());
    xml.AddElem("Item", expenses.getItem());
    xml.AddElem ("Amount", expenses.getAmount());

    xml.Save("expenses.xml");
}
vector <Expenses> FileWithExpenses::loadExpensesFromFile (int idLoggedUser)
{
    Expenses expenses;
    vector <Expenses> expense;
    CMarkup xml;

    xml.Load("expenses.xml");
    xml.FindElem("Expenses");
    xml.IntoElem();
    while(xml.FindElem("Expense"))
    {
        xml.IntoElem();
        xml.FindElem("UserId");
        while(AuxiliaryMethods::convertStringToInt(xml.GetData())==idLoggedUser)
        {
            expenses.setUserId(AuxiliaryMethods::convertStringToInt(xml.GetData()));
            xml.FindElem("AmountId");
            expenses.setAmountId(AuxiliaryMethods::convertStringToInt(xml.GetData()));
            xml.FindElem("Date");
            expenses.setDate(AuxiliaryMethods::convertStringToInt(xml.GetData()));
            xml.FindElem("Item");
            expenses.setItem(xml.GetData());
            xml.FindElem("Amount");
            expenses.setAmount(xml.GetData());
            expense.push_back(expenses);
        }
        xml.ResetMainPos();
        xml.OutOfElem();
    }
    return expense;
}


