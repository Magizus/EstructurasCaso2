
#include "Intervalo.h"
#include "Horario.h"
#include <iostream>
using namespace std;

class Configuracion
{
public:
  Intervalo capacidadAlmacen;
  Intervalo capacidadCamion;
  Horario horarioDescarga;
  Horario horarioCarga;
  Intervalo tiempoDescarga;
  Intervalo tiempoCarga;
  vector<string> tiposProductos;


  Configuracion(){

  }

  Configuracion(
      Intervalo capacidadAlmacen, Intervalo capacidadCamion, Horario horarioDescarga,
      Horario horarioCarga,
      Intervalo tiempoDescarga,
      Intervalo tiempoCarga,
      vector<string> tiposProductos)
  {
    capacidadAlmacen = capacidadAlmacen;
    capacidadCamion = capacidadCamion;
    horarioDescarga = horarioDescarga;
    horarioCarga = horarioCarga;
    tiempoDescarga = tiempoDescarga;
    tiempoCarga = tiempoCarga;
    tiposProductos = tiposProductos;
  }

private:
};