#include "UserManager.h"

void UserManager::userRegistration()
{
    User user = giveDataOfNewUser();

    users.push_back(user);
    fileWithUsers.addUserToFile(user);

    cout << endl << "Konto za\210o\276ono pomy\230lnie" << endl << endl;
    system("pause");
}
User UserManager::giveDataOfNewUser()
{
    User user;

    user.setId(getIdOfNewUser());

    string login;
    do
    {
        cout  <<endl<< "Podaj login: ";
        cin>> login;
        user.setLogin(login);
    }
    while (ifLoginExist(user.getLogin()) == true);

    string name;

    cout<< "Podaj imi\251: ";
    cin>>name;
    user.setName(name);
    string surname;
    cout<<"Podaj nazwisko: ";
    cin>>surname;
    user.setSurname(surname);
    string password;
    cout << "Podaj has\210o: ";
    cin>> password;
    user.setPassword(password);

    return user;
}

int UserManager::getIdOfNewUser()
{
    if (users.empty() == true)
        return 1;
    else
        return users.back().getId() + 1;
}
bool UserManager::ifLoginExist(string login)
{
    vector <User>::iterator itr = users.begin();

    for (int i =0; i<users.size(); i++)
    {
        if(users[i].getLogin()==login)
        {
            cout << endl << "Istnieje u\276ytkownik o takim loginie." << endl;
            return true;
        }
    }
    return false;
}

void UserManager::loadUsersFromFile()
{
    users = fileWithUsers.loadUsersFromFile();
}

void UserManager::changePassword()
{
    string newPassword = "";
    cout << "Podaj nowe has\210o: ";
    newPassword = AuxiliaryMethods::loadLine();

    for (vector <User>::iterator itr = users.begin(); itr != users.end(); itr++)
    {
        if (itr -> getId() == idLoggedUser)
        {
            itr -> setPassword(newPassword);
            cout << "Has\210o zosta\210o zmienione." << endl << endl;
            system("pause");
        }
    }
    //fileWithUsers.saveAllUsersToFile(users);
}

void UserManager::signupUser()
{
    User user;
    string login = "", password = "";
  bool ifPasswordIsCorrect=false;
  bool ifLoginExist=false;
  bool ifLimitIsReached=false;
    idLoggedUser=0;

    cout << "Podaj login: ";
    cin >> login;

    vector <User>::iterator itr = users.begin();
    while ((itr != users.end())&&(ifPasswordIsCorrect==false)&&(ifLimitIsReached==false))
    {
        if (itr -> getLogin()== login)
        {
            ifLoginExist=true;
            for (int numberOfTests=3; numberOfTests>0; numberOfTests--)
            {
                cout << "Podaj has\210o (pozosta\210o pr\242b: "<< numberOfTests <<"): ";
                cin >> password;
                if (itr -> getPassword() == password)
                {
                    ifPasswordIsCorrect=true;
                    cout << endl << "Zalogowa\210e\230 si\251." << endl << endl;
                    system("pause");
                    idLoggedUser=itr -> getId();
                    numberOfTests=0;
                }
                if ((numberOfTests==1)&&(ifPasswordIsCorrect==false))
                    ifLimitIsReached=true;
            }
        }
        else
            itr++;
    }
    if (ifLoginExist==false)
    {
        cout << "Nie ma u\276ytkownika z takim loginem!" << endl << endl;
        system("pause");
    }
    if (ifLimitIsReached==true)
    {
        cout << "Wyczerpano limit pr\242b!" << endl << endl;
        system("pause");
    }
}

int UserManager::getIdLoggedinUser()
{
    return idLoggedUser;
}

void UserManager::logoutUser()
{
    idLoggedUser=0;
}
