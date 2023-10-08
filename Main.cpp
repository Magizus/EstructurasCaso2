#include <iostream>
#include "camion.h"
using namespace std;

int main() {
    // Crear un objeto de la clase Camion placa,capacidad, tipo
    Pila<Produ> ParaCamion;
    Camion PrimerC (12534, 100, "jose", ParaCamion);

    Produ Producto1 ("Papel", 30);
    Produ Producto2 ("lapiz", 20);
    Produ Producto3 ("arma", 40);
    Produ Producto4 ("comida", 15);
    PrimerC.cargarProducto(Producto1);
    PrimerC.cargarProducto(Producto2);
    PrimerC.cargarProducto(Producto3);
    PrimerC.cargarProducto(Producto4);

    PrimerC.mostrarCargamento();
    

    return 0;
}