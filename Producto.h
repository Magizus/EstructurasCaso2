#include <iostream>
#include <string>
using namespace std;

class Produ
{
private:
    string Producto;
    int valor;

public:
    // Constructor de Producto
    Produ(string nombre, int val) : Producto(nombre), valor(val) {}

    int getValor() {
        return valor;
    }

    string getNombre() {
        return Producto;
    }
}; 