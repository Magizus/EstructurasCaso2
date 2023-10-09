#include <iostream>
#include "Utilidad.h"
using namespace std;

int main() {
    // Crear un objeto de la clase Camion placa,capacidad, tipo
    Pila<Produ> ParaCamion;
    Camion PrimerC (12534, 100, "papel", ParaCamion);
    Camion SegundoC (4584, 100, "camisas", ParaCamion);
    Utilidad ColaCamiones;    
   

    Produ Producto1 ("Papel", 30);
    Produ Producto2 ("Papel", 20);
    Produ Producto3 ("arma", 40);
    Produ Producto4 ("comida", 15);

    PrimerC.cargarProducto(Producto1);
    PrimerC.cargarProducto(Producto2);
    SegundoC.cargarProducto(Producto3);
    SegundoC.cargarProducto(Producto4);

    ColaCamiones.ingresarCamion(PrimerC);
    ColaCamiones.ingresarCamion(SegundoC);
    ColaCamiones.MostrarCamiones();

    return 0;
}