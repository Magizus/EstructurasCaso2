#include <iostream>

using namespace std;

class Horario
{
public:
    string horaInicio;
    string horaNoAceptarMas;
    string horaFin;



    Horario(){
        
    }


    Horario(string horaInicio, string horaNoAceptarMas, string horaFin){
        this->horaInicio = horaInicio;
        this->horaNoAceptarMas = horaNoAceptarMas;
        this->horaFin = horaFin;
    }

private:
};
