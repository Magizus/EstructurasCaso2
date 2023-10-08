
#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class Pila {
private:
    vector<T> elementos;

public:
    
    void push( T& elemento) {
        elementos.push_back(elemento);
    }

    // Método para eliminar y devolver el elemento superior de la pila
    T pop() {
        if (!isEmpty()) {
            T elementoSuperior = elementos.back();
            elementos.pop_back();
            return elementoSuperior;
        } else {
            throw std::runtime_error("La pila está vacía");
        }
    }

    // Método para obtener el elemento superior de la pila sin eliminarlo
    T top()  {
        if (!isEmpty()) {
            return elementos.back();
        } else {
            throw std::runtime_error("La pila está vacía");
        }
    }

    // Método para verificar si la pila está vacía
    bool isEmpty()  {
        return elementos.empty();
    }
};



