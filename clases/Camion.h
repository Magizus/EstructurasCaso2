#include <iostream>
#include "Pila.h"
#include "Producto.h"

using namespace std;

class Camion
{
private:
    int capacidadT;
    int espacioOcupado = 0;
    string tproducto;
    Pila<Produ> cargamento;

public:
    Camion(int cap, string tprod, Pila<Produ> cargamento) : capacidadT(cap), tproducto(tprod), cargamento(cargamento) {}

    Camion()
    {
    }

    void cargarProducto(Produ &producto)
    {
        if (capacidadT - espacioOcupado >= producto.getValor())
        {
            cargamento.push(producto);
            espacioOcupado += producto.getValor();
            cout << "Se ingreso el producto\n";
        }
        else
        {
            cout << "No hay espacio suficiente para el producto\n";
        }
    }
    // Método para descargar un producto del camión
    void descargarProducto()
    {
        if (!cargamento.isEmpty())
        {
            cargamento.pop();
        }
        else
        {
            cout << "El cargamento está vacío." << endl;
        }
    }

    /*
        void mostrarCargamento() {
        if (Cargamento.isEmpty()) {
            cout << "El camión está vacio." << endl;
        } else {
            cout << "Lista de productos en el camion:" << endl;
            Pila<Produ> tempPila = Cargamento; // Creamos una pila temporal para no alterar la original
            while (!tempPila.isEmpty()) {
                Produ producto = tempPila.top();
                cout << "Nombre: " << producto.getNombre() << ", Valor: " << producto.getValor() << endl;
                tempPila.pop();
            }
        }
    }
    */
    Pila<Produ> getPila()
    {
        return cargamento;
    }

    int getEspacioO()
    {
        return espacioOcupado;
    }
    string getTproducto()
    {
        return tproducto;
    }
};