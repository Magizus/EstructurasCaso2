#include <iostream>
#include <stack>
#include "camion.h"

using namespace std;

class Almacen
{
private:
    string tiposPermitidos[];
    Pila<Produ> inventario[];
    int capacidadT;
    int EspacioUsado = 0;

public:
    Almacen()
    {
    }

    Almacen(int capacidadAlmacen, string tiposPermitidos[])
    {
        capacidadT = capacidadAlmacen;
        this.tiposPermitidos = tiposPermitidos;
        inventario[capacidadT];
        for (int i = 0; i < capacidadT; i++)
        {
            pilaDeProducto = new Pila<Produ>();
            inventario[i] = pilaDeProducto;

            cout << "Se ha creado una nueva pila para el producto '" << tiposPermitidos[i] << "'." << endl;
        }
    }

    void DepositarA(Camion &Camion)
    {
        Pila<Produ> PilaC = Camion.getPila();

        while (!PilaC.isEmpty())
        {
            Produ producto = PilaC.top();

            if (capacidadT - EspacioUsado >= producto.getValor())
            {
                almacen.push(producto);
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
