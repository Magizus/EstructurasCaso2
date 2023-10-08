#include <iostream>
#include <stack>
#include "camion.h"


using namespace std;

class Bodega
{
private:
    string TipoP;
    Pila <Produ> Almacen ;
    int capacidadT;
    int EspacioUsado = 0;


public:
    string getNombre() {
        return TipoP;
    }

    void DepositarA( Camion& Camion) {
        Pila<Produ> PilaC = Camion.getPila();

        while(!PilaC.isEmpty()){
            Produ producto = PilaC.top();

            if (capacidadT-EspacioUsado >= producto.getValor()){
                Almacen.push(producto);
                EspacioUsado += producto.getValor();
                //mensaje de producto metido
                PilaC.pop();
            }else{
                //mensaje de no espacio
                break;
            }
        }
        
        
    }

};

