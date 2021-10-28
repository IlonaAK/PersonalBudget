#include "FileWithUsers.h"

void FileWithUsers::addUserToFile(User users)
{
    CMarkup xml;

    bool fileExists = xml.Load( "users.xml" );

    if (!fileExists)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Users");
        xml.IntoElem();
    }
    else
    {
        xml.Load( "users.xml" );
        xml.FindElem("Users");
        xml.IntoElem();
    }
    xml.AddElem("User");
    xml.IntoElem();
    xml.AddElem("UserId",users.getId());
    xml.AddElem("Login", users.getLogin());
    xml.AddElem("Name", users.getName());
    xml.AddElem ("Surname", users.getSurname());
    xml.AddElem("Password", users.getPassword());
    xml.Save("users.xml");
}

vector <User> FileWithUsers::loadUsersFromFile()
{
    User user;
    vector <User> users;
    CMarkup xml;

    xml.Load("users.xml");
    xml.FindElem("Users");
    xml.IntoElem();
    while(xml.FindElem("User"))
    {
        xml.IntoElem();
        xml.FindElem("UserId");
        user.setId(AuxiliaryMethods::convertStringToInt(xml.GetData ()));
        xml.FindElem("Login");
        user.setLogin(xml.GetData());
        xml.FindElem("Name");
        user.setName(xml.GetData());
        xml.FindElem("Surname");
        user.setSurname(xml.GetData());
        xml.FindElem("Password");
        user.setPassword(xml.GetData());
        xml.ResetMainPos();
        xml.OutOfElem();
        users.push_back(user);
    }
    return users;
}

void FileWithUsers::saveAllUsersToFile(vector<User> &users)
{
    CMarkup xml;

    xml.Load("users.xml");
    xml.FindElem("Users");
    xml.ResetChildPos();
    while ( xml.FindChildElem() )
    {
    xml.RemoveChildElem();
    }
    xml.IntoElem();
    for (int i=0; i<users.size();i++)
    {
    xml.AddElem("User");
    xml.IntoElem();
    xml.AddElem("UserId",users[i].getId());
    xml.AddElem("Login", users[i].getLogin());
    xml.AddElem("Name", users[i].getName());
    xml.AddElem ("Surname", users[i].getSurname());
    xml.AddElem("Password", users[i].getPassword());
    xml.ResetMainPos();
    xml.OutOfElem();
    }
    xml.Save("users.xml");
}




