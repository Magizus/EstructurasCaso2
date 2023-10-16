#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include "../clases/Almacen.h"

using namespace std;

class Utilidad
{
private:
    queue<Camion> colaDeCamiones;
    Almacen almacen;

public:
    // Constructor

    Utilidad()
    {
    }

    Utilidad(Intervalo capacidadAlmacen, vector<string> tiposProductos)
    {
        vector<string> tiposRandom; // lista para crear tipos de producto random basado en la capacidad de pilas del almacen
        this -> colaDeCamiones = queue<Camion>();

        for (int i = 0; i < 3; i++)
        {
            tiposRandom.push_back(tiposProductos[rand() % tiposProductos.size()]);
        }
        
        almacen = Almacen(capacidadAlmacen.getMaximo(), tiposRandom);
        }

    // Método para ingresar un camión al frente de la cola
    void ingresarCamion(Camion camionllegada)
    {
        colaDeCamiones.push(camionllegada);
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

    int RevisarCola()
    {
        cout << "Validando si hay camiones en la fila." << endl;
        if (tamanoCola() > 0)
        {
            cout << "Hay camiones en la fila." << endl;
            procesarCola();
            return 1;
        }
        else
        {
            cout << "No hay camiones en la fila." << endl;
            return 0;
        }
    }

    void procesarCola()
    {
        Camion camion = obtenerCamionFrontal();
        cout << "Validando tipo de producto." << endl;
        if (almacen.getIndex(camion.getTproducto()) != -1)
        {
            cout << "Ingresando un camion" << endl;
            almacen.DepositarA(camion);
        }
        eliminarCamionFrontal();
    }
};
