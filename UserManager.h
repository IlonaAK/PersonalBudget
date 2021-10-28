#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include<vector>
#include <iostream>
#include <vector>
#include <windows.h>
#include <sstream>


#include "User.h"
#include "FileWithUsers.h"

using namespace std;

class UserManager
{
    int idLoggedUser;
    vector <User> users;
    User giveDataOfNewUser();
    int getIdOfNewUser();
    bool ifLoginExist(string login);
    FileWithUsers fileWithUsers;

public:
    UserManager(string nameOfFileWithUsers) : fileWithUsers(nameOfFileWithUsers)
    {
        users=fileWithUsers.loadUsersFromFile();
        idLoggedUser=0;
    };

    void signupUser();
    void userRegistration();
    void displayAllUser();
    void changePassword();
    void logoutUser();
    int getIdLoggedinUser();
    void loadUsersFromFile();

};
#endif
