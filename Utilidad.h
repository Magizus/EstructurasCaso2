#include <iostream>
#include <queue>
#include "almacen.h"
using namespace std;

class Utilidad {
private:

    queue<Camion> ColaDeCamiones;


public:
   
    Utilidad() {}

    // Método para ingresar un camión al frente de la cola
    void ingresarCamion(Camion camionLLegada) {
        ColaDeCamiones.push(camionLLegada);
    }

    void MostrarCamiones() {
    if (ColaDeCamiones.empty()) {
        cout << "La cola de camiones está vacía." << endl;
    } else {
        cout << "Camiones en la cola:" << endl;

        // Crear una cola temporal para mostrar los camiones sin alterar la original
        queue<Camion> colaTemporal = ColaDeCamiones;

        while (!colaTemporal.empty()) {
            Camion camion = colaTemporal.front();
            cout << "Placa del camion: " << camion.getPlaca() << endl;
            cout << "Tipo de producto: " << camion.getTproducto() << endl;
            // También puedes mostrar otros detalles del camión aquí si lo deseas
            colaTemporal.pop();
            }
        }
    }
    
    void ingresarCamion(Camion camionLLegada) {
        ColaDeCamiones.push(camionLLegada);
    }

    Camion obtenerCamionFrontal() {
        if (!ColaDeCamiones.empty()) {
            return ColaDeCamiones.front();
        } else {
            throw runtime_error("La cola de camiones está vacía.");
        }
    }

    void eliminarCamionFrontal() {
        if (!ColaDeCamiones.empty()) {
            ColaDeCamiones.pop();
        } else {
            cout << "La cola de camiones está vacía." << endl;
        }
    }
    
    bool colaVacia() {
        return ColaDeCamiones.empty();
    }

    
    int tamanoCola() {
        return ColaDeCamiones.size();
    }
};


