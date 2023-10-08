
#include <iostream>
#include "Pila.h"
#include "Producto.h"


using namespace std;

class Camion
{
private:
    int placa;
    int capacidadT;
    int EspacioOcupado = 0;
    string Tproducto;
    Pila<Produ> Cargamento;  

public:
    
    Camion(int p, int cap,  string tprod, Pila<Produ> cargamento) : placa(p), capacidadT(cap), Tproducto(tprod), Cargamento(cargamento) {}


    
   void cargarProducto( Produ& producto) {
        if (capacidadT-EspacioOcupado >= producto.getValor()){
            Cargamento.push(producto);
            EspacioOcupado += producto.getValor();
            cout << "Se ingreso el producto\n";

        }else{
            cout << "No hay espacio suficiente para el producto\n";

        }
        
        
    }
    // Método para descargar un producto del camión
    void descargarProducto() {
        if (!Cargamento.isEmpty()) {
            Cargamento.pop();
        } else {
            cout << "El cargamento está vacío." << endl;
        }
    }

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









    
};