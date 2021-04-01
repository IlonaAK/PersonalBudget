#ifndef FILES_H
#define FILES_H

#include <iostream>

using namespace std;

class File
{
    const string nameOfFile;
    int idLastAmount;
    string nameOfTemporaryFile;
    void removeFile(string nameFileWithSuffix);
    void changeNameOfFile(string oldName, string newName);


//public:
    /*PlikZAdresatami(string nazwaPlikuZAdresatami) : NAZWA_PLIKU_Z_ADRESATAMI(nazwaPlikuZAdresatami)
    {
        idOstatniegoAdresata=0;
    };
    void dopiszAdresataDoPliku(Adresat adresat);
    vector <Adresat>wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika);
    int pobierzIdOstatniegoAdresata();
    string zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat);
    void edytujAdresataWPliku(int idAdresata, string liniaZDanymiAdresataOddzielonePionowymiKreskami);
    void usunAdresataZPliku (int idUsuwanegoAdresata);*/
};
#endif
