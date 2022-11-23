#pragma once
using namespace std;
#include "Categoria.h"

class Producto
{
private:
    int codProducto;
    string nomProducto;
    float preProducto;
    int stkProducto;
    int codCategoria;

public:
    Producto(int cod, string nom, float pre, int stk, Categoria unaCategoria ){
        codProducto = cod;
        nomProducto = nom;
        preProducto = pre;
        stkProducto = stk;
        codCategoria = unaCategoria.GetCodigo();
    }
	
    int GetCodProducto(){
        return codProducto;
    }
	
    string GetNomProducto(){
        return nomProducto;
    }
	
    float GetPrecio(){
        return preProducto;
    }
	
    int GetStockProducto(){
        return stkProducto;
    }
	
    void SetStock(int stk){
        stkProducto = stk;
    }

    int GetCodCategoria(){
        return codCategoria;
    }
    
};
