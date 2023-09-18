#ifndef MI_PILA_H
#define MI_PILA_H

#include <iostream>
#include <stack>
#include <string>


using namespace std;
class Pila {

private:
    stack<string> pila;

public:
    // Constructor por defecto
    Pila() {}

    // Método para agregar un elemento a la pila
    void push(string& elemento) {
        pila.push(elemento);
    }


     bool estaVacia()  {
        return pila.empty();
    }   



    int largo(){ 
    return pila.size();
    }




    void pop() {
        if (!pila.empty()) {
            pila.pop();
        } else {
            cout << "La pila está vacía. " << endl;
        }
    }

    
    string top() {
        if (!pila.empty()) {
            return pila.top();
        } else {
         
            return "";
        }
    }


};

#endif
