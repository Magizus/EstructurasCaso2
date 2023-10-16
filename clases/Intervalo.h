
#include <iostream>
using namespace std;

class Intervalo
{
public:
    int minimo;
    int maximo;

    Intervalo()
    {
    }

    Intervalo(int minimo, int maximo)
    {
        this->minimo = minimo;
        this->maximo = maximo;
    }

    int getMaximo()
    {
        return maximo;
    }

    int getMinimo()
    {
        return minimo;
    }

private:
};