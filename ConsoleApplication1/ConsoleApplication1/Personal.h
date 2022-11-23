#pragma once
#include <fstream>
#include <string>

#include "Categoria.h"
using namespace std;

class Personal
{
private:
    int codigoPersonal;
    string nombreApellidoPersonal;
    string usuarioPer;
    string passwordPer;

public:
    Personal(int codigo, string nombreapellido, string user, string pass)
    {
        codigoPersonal = codigo;
        nombreApellidoPersonal = nombreapellido;
        usuarioPer = user;
        passwordPer = pass;
    }

    string GetPassword()
    {
        return passwordPer;
    }

    string GetUsuario()
    {
        return usuarioPer;
    }

    string GetNombre()
    {
        return nombreApellidoPersonal;
    }

    int GetCodigo()
    {
        return codigoPersonal;
    }

    
};
