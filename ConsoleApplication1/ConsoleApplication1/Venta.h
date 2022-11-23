#pragma once
using namespace std;
#include <iostream>
#include "Producto.h"
#include <vector>

class Venta
{
	
private:
    int codVenta;
    float totVen;
    int codCli;
    string fecVen;
    string estVen;
    
public:
    vector<Producto> productos;
    Venta(int codV, string fecha, string estado, int codC){
		
        codVenta = codV;
        fecVen = fecha;
        estVen = estado;
        codCli = codC;
    }
	
    void IngresarProductos(Producto product){
        if(product.GetStockProducto() > 0){
            productos.push_back(product);
        }
    }
	
    int GetTotalVenta(){
        int aux = 0;
        if(!productos.empty()){
            for(int i = 0; i < productos.size(); i++){
                if(productos[i].GetStockProducto() > 0){
                    aux += productos[i].GetPrecio();
                    productos[i].SetStock(productos[i].GetStockProducto()-1);
                }
				
            }
        }
		
        return aux;
    }
	
    int Busqueda(int codABuscar){
        for(int i = 0; i < productos.size(); i++){
            if(productos[i].GetCodProducto() == codABuscar){
                return i;
            }
        }
		
        return -1;
    }

    void Eliminar(int codABuscar){
        int index = Busqueda(codABuscar);
        if(index != -1){
			
            Producto auxProducto = productos[index];
            productos[index] = productos[productos.size()-1];
            productos[productos.size()-1] = auxProducto;
            productos.pop_back();
            cout << "Eliminado correctamente"<< endl;
        }
    }
	
    void Listar(){
        for(int i = 0; i < productos.size(); i++){
            cout << productos[i].GetNomProducto() << endl;
        }
    }
    
};
