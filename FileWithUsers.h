#ifndef FILEWITHUSERS_H
#define FILEWITHUSERS_H

#include <vector>
#include <iostream>
#include <stdlib.h>
#include <string>

#include "User.h"
#include "Markup.h"
#include "AuxiliaryMethods.h"
#include "File.h"

using namespace std;

class FileWithUsers: public File
{
const string NAME_FILE_WITH_USERS;

public:

     FileWithUsers (string nameFileWithUsers): NAME_FILE_WITH_USERS(nameFileWithUsers){};
     void addUserToFile(User users);
     vector <User> loadUsersFromFile();
};
#endif
