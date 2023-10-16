#include <iostream>
#include <stack>
#include "camion.h"

using namespace std;

class Almacen
{
private:
    vector<string> tiposPermitidos;
    vector<Pila<Produ>> inventario;
    int capacidadT;
    int EspacioUsado = 0;

public:
    Almacen()
    {
    }

    Almacen(int capacidadAlmacen, vector<string> tiposPermitidos)
    {
        capacidadT = capacidadAlmacen;
        tiposPermitidos = tiposPermitidos;
        for (int i = 0; i < sizeof(tiposPermitidos); i++)
        {
            
            Pila pilaDeProducto =  Pila<Produ>();
            inventario[i] = pilaDeProducto;

            cout << "Se ha creado una nueva pila para el producto " << tiposPermitidos[i] << "." << endl;
        }
    }

    int getIndex(string K) 
    { 
        auto it = find(tiposPermitidos.begin(), tiposPermitidos.end(), K); 
  
        // If element was found 
        if (it != tiposPermitidos.end())  
        { 
        // calculating the index  of K 
            int index = it - tiposPermitidos.begin(); 
            return index;
        } 
         else 
         { 
        return -1;
    } 
} 

    void DepositarA(Camion &Camion)
    {
        Pila<Produ> PilaC = Camion.getPila();
        int indexT = getIndex(Camion.getTproducto());
    
        while (!PilaC.isEmpty())
        {
            Produ producto = PilaC.top();

            if (capacidadT - EspacioUsado >= producto.getValor())
            {
                inventario[indexT].push(producto);
                EspacioUsado += producto.getValor();
                // mensaje de producto metido
                PilaC.pop();
            }
            else
            {
                // mensaje de no espacio
                break;
            }
        }
    }






};
