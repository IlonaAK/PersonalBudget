#ifndef FILE_H
#define FILE_H

#include <iostream>
#include "Markup.h"


using namespace std;

class File
{
public:
    string nameOfTemporaryFile;
    void removeFile(string nameFileWithSuffix);
    void changeNameOfFile(string oldName, string newName);
    File(){};
};
#endif
