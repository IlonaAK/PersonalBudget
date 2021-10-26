#include "FileWithIncomes.h"

void FileWithIncomes::addIncomeToFile(Incomes incomes)
{
  CMarkup xml;

    bool fileExists = xml.Load( "incomes.xml" );

    if (!fileExists)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Incomes");
        xml.IntoElem();
    }
    else
    {
        xml.Load( "incomes.xml" );
        xml.FindElem("Incomes");
        xml.IntoElem();
    }
    xml.AddElem("Income");
    xml.IntoElem();
    xml.AddElem("UserId",incomes.getUserId());
    xml.AddElem("AmountId", incomes.getAmountId());
    xml.AddElem("Date", incomes.getDate());
    xml.AddElem("Item", incomes.getItem());
    xml.AddElem ("Amount", incomes.getAmount());

    xml.Save("incomes.xml");
}

vector <Incomes> FileWithIncomes::loadIncomesFromFile (int idLoggedUser)
{
    Incomes incomes;
    vector <Incomes> income;
    CMarkup xml;

    xml.Load("incomes.xml");
    xml.FindElem("Incomes");
    xml.IntoElem();
    while(xml.FindElem("Income"))
    {
        xml.IntoElem();
        xml.FindElem("UserId");
        incomes.setUserId(idLoggedUser);
        xml.FindElem("AmountId");
        incomes.setAmountId(AuxiliaryMethods::convertStringToInt(xml.GetData()));
        xml.FindElem("Date");
        incomes.setDate(AuxiliaryMethods::convertStringToInt(xml.GetData()));
        xml.FindElem("Item");
        incomes.setItem(xml.GetData());
        xml.FindElem("Amount");
        incomes.setAmount(xml.GetData());

        xml.ResetMainPos();
        xml.OutOfElem();
        income.push_back(incomes);
    }
    return income;
}
