#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include "almacen.h"

using namespace std;

class Utilidad
{
private:
    queue<Camion> colaDeCamiones;
    Almacen almacen;

public:
    // Constructor
    Utilidad(int capacidadAlmacen, string tiposProductos[])
    {
        string productosRandom[capacidadAlmacen]; // lista para crear tipos de producto random basado en la capacidad de pilas del almacen
        colaDeCamiones = new queue<Camion>();

        for (int i = 0; i < capacidadAlmacen; i++)
        {
            productosRandom[i] = tiposProductos[rand() % sizeof(tiposProductos - 1) + 0]
        }
        almacen = new Almacen(capacidadAlmacen, productosRandom);
    }

    // Método para ingresar un camión al frente de la cola
    void ingresarCamion(Camion camionLLegada)
    {
        colaDeCamiones.push(camionLLegada);
    }

    void MostrarCamiones()
    {
        if (colaDeCamiones.empty())
        {
            cout << "La cola de camiones está vacía." << endl;
        }
        else
        {
            cout << "Camiones en la cola:" << endl;

            // Crear una cola temporal para mostrar los camiones sin alterar la original
            queue<Camion> colaTemporal = colaDeCamiones;

            while (!colaTemporal.empty())
            {
                Camion camion = colaTemporal.front();
                cout << "Placa del camion: " << camion.getPlaca() << endl;
                cout << "Tipo de producto: " << camion.getTproducto() << endl;
                // También puedes mostrar otros detalles del camión aquí si lo deseas
                colaTemporal.pop();
            }
        }
    }
    void ingresarCamion(Camion camionLLegada)
    {
        colaDeCamiones.push(camionLLegada);
    }

    Camion obtenerCamionFrontal()
    {
        if (!colaDeCamiones.empty())
        {
            return colaDeCamiones.front();
        }
        else
        {
            throw runtime_error("La cola de camiones está vacía.");
        }
    }

    void eliminarCamionFrontal()
    {
        if (!colaDeCamiones.empty())
        {
            colaDeCamiones.pop();
        }
        else
        {
            cout << "La cola de camiones está vacía." << endl;
        }
    }

    bool colaVacia()
    {
        return colaDeCamiones.empty();
    }

    int tamanoCola()
    {
        return colaDeCamiones.size();
    }
    // Método para agregar productos a una pila en el almacén
    void agregarProducto(string &tipoProducto, int cantidad)
    {
        if (almacen.find(tipoProducto) != almacen.end())
        {
            almacen[tipoProducto].push(cantidad);
        }
    }

    // Método para restar productos de una pila en el almacén
    bool restarProducto(string &tipoProducto, int cantidad)
    {
        if (almacen.find(tipoProducto) != almacen.end())
        {
            stack<int> &pila = almacen[tipoProducto];
            if (!pila.empty() && pila.size() >= cantidad)
            {
                for (int i = 0; i < cantidad; i++)
                {
                    pila.pop();
                }
                return true; // Se restaron los productos con éxito
            }
        }
        return false; // No se pudo restar la cantidad solicitada de productos
    }
};
