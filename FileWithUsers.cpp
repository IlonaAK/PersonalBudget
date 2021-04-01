#include "FileWithUsers.h"

void FileWithUsers::addUserToFile(User user)
{
    CMarkup xml;

    bool fileExists = xml.Load( "users.xml" );

    if (!fileExists)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Users");
        xml.IntoElem();
        xml.AddElem("User");
        xml.IntoElem();
        xml.AddElem("UserId", "1");
        xml.AddElem("Login", user.getLogin());
        xml.AddElem("Name", user.getName());
        xml.AddElem ("Surname", user.getSurname());
        xml.AddElem("Password", user.getPassword());
        xml.Save("users.xml");
    }
    else
    {
        xml.FindElem("Users");
        xml.IntoElem();
        xml.AddElem("User");
        xml.IntoElem();
        xml.AddElem("UserId", user.getId());
        xml.AddElem("Login", user.getLogin());
        xml.AddElem("Name", user.getName());
        xml.AddElem ("Surname", user.getSurname());
        xml.AddElem("Password", user.getPassword());;
        xml.Save("users.xml");

    }
}

vector <User> FileWithUsers::loadUsersFromFile()
{
    User user;
    vector <User>users;
    CMarkup xml;
    xml.Load("users.xml");
    xml.FindElem("Users");
    xml.IntoElem();
    while(xml.FindElem("User"))
    {
        xml.IntoElem();
        xml.FindElem("UserId");
        string userId= xml.GetData ();
        user.setId(AuxiliaryMethods::convertStringToInt(userId));
        xml.FindElem("Login");
        string login =xml.GetData();
        user.setLogin(login);
        xml.FindElem("Name");
        string name=xml.GetData();
        user.setName(name);
        xml.FindElem("Surname");
        string surname =xml.GetData();
        user.setSurname(surname);
        xml.FindElem("Password");
        string password =xml.GetData();
        user.setPassword(password);
        users.push_back(user);
        xml.OutOfElem();
    }
    return users;
}


