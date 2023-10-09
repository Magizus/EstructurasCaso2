
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
  {
    float tiempoDescargaporProducto;
    float tiempoCargaporProducto;
  }
  producto;
  string tiposProductos[];

  Configuracion()
  {
  }
  Configuracion(
      Intervalo capacidadAlmacen, Intervalo capacidadCamion, Horario horarioDescarga,
      Horario horarioCarga,
      Intervalo tiempoDescarga,
      Intervalo tiempoCarga, {
        float tiempoDescargaporProducto;
        float tiempoCargaporProducto;
      } producto,
      array<string> tiposProductos)
  {
    this.capacidadAlmacen = capacidadAlmacen;
    this.capacidadCamion = capacidadCamion;
    this.horarioDescarga = horarioDescarga;
    this.horarioCarga = horarioCarga;
    this.tiempoDescarga = tiempoDescarga;
    this.tiempoCarga = tiempoCarga;
    this.producto = producto;
    this.tiposProductos = tiposProductos;
  }

private:
};