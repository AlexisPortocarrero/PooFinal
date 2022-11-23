#pragma once
#include <string>
using namespace std;
#include <iostream>

class Categoria
{
private:
    int codCategoria;
    string nomCat;
	

public:
    Categoria(int cod, string nom){
        codCategoria = cod;
        nomCat = nom;
    }
	
    int GetCodigo(){
        return codCategoria;
    }

    string GetName(){
        return nomCat;
    }
    
};
