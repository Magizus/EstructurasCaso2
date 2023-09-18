#include "Pilas.h"
#include <iostream>
#include <string>


bool respuesta() {
    int opcion;
    
    cout << "No hay capacidad suficiente para guardar todo lo del camion." << endl;
    cout << "Desea guardar lo maximo posible o no desea guardar nada." << endl;
    cout << "1. Guardar lo maximo posible" << endl;
    cout << "2. No guardar." <<endl;
    cout << "Ingrese 1 o 2: ";
    
    cin >> opcion;
    
    while (opcion != 1 && opcion != 2) {
       cout << "Opción no válida. Por favor, ingrese 1 o 2: ";
       cin >> opcion;
    }

    if (opcion == 1){
        return true;
    }else{
        return false;
    }
  
}

void pasarElementosAux(Pila& PilaCamion, Pila& PilaAlmacen) {
    int MaxLargo = 10;
    if(MaxLargo - PilaAlmacen.largo()>= PilaCamion.largo()){
        pasarElementosFull(PilaCamion,PilaAlmacen);
    }
    else if(MaxLargo - PilaAlmacen.largo() < PilaCamion.largo())
    {
        bool R = respuesta();
        if(R == true){
            pasarElementosParcial( PilaCamion, PilaAlmacen, MaxLargo - PilaAlmacen.largo());
        }
    }else if (MaxLargo - PilaAlmacen.largo() == 0){
        cout<< "No queda campo para este tipo de producto";
    }
}

// Función para pasar elementos de la Lista A a la Lista B
void pasarElementosFull(Pila& PilaCamion, Pila& PilaAlmacen) {
    while (!PilaCamion.estaVacia()) {
        string elemento = PilaCamion.top(); // Obtener el elemento superior de A
        PilaCamion.pop(); // Eliminar el elemento superior de A
        PilaAlmacen.push(elemento); // Agregar el elemento a B
    }
}

void pasarElementosParcial(Pila& pilaCamion, Pila& pilaAlmacen, int cantPasar){ 
    
    for (int i = 0; i < cantPasar; i++) {
        if (!pilaCamion.estaVacia()) {
            string elemento = pilaCamion.top(); // Obtener el elemento superior de la pilaCamion
            pilaCamion.pop(); // Eliminar el elemento superior de la pilaCamion
            pilaAlmacen.push(elemento); // Agregar el elemento a la pilaAlmacen
            } 
            else 
            {
            cout << "La pilaCamion está vacía. No se pueden pasar más elementos." << endl;
            break;
            }
    }
}





