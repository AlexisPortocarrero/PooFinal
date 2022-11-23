#pragma once
#include <string>
using namespace std;

class Cliente
{
private:
    int codClie;
    string nomApellClie;
    string dirClie;
    int rucClie;

public:
    Cliente(int cod, string nom, string dir, int ruc)
    {
        codClie = cod;
        nomApellClie = nom;
        dirClie = dir;
        rucClie = ruc;
    }

    int GetCode()
    {
        return codClie;
    }
};
