#include <iostream>
#include <string>
using namespace std;

class Produ
{
private:
    string producto;
    int valor;

public:
        Produ(string nombre, int val) : producto(nombre), valor(val) {}

    int getValor()
    {
        return valor;
    }

    string getNombre()
    {
        return producto;
    }
};