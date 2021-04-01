#ifndef FILEWITHUSERS_H
#define FILEWITHUSERS_H

#include <vector>
#include <iostream>

#include "User.h"
#include "Markup.h"
#include "AuxiliaryMethods.h"

using namespace std;

class FileWithUsers
{
    const string nameOfFileWithUsers;
    User getDataUser(string daneJednegoUzytkownikaOddzielonePionowymiKreskami);

public:
   // FileWithUsers(string NAMEOFFILEWITHUSERS) : nameOfFileWithUsers(NAMEOFILEWITHUSERS) {};
    void addUserToFile(User user);
    vector <User> loadUsersFromFile ();
    void saveAllUsersToFile(vector <User> &users);
};
#endif
