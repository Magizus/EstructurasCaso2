#include <iostream>
#include <vector>
#include "json.hpp"
#include <fstream>
#include "./clases/Pila.h"
#include "clases/Almacen.h"
#include "clases/Configuracion.h"
#include "logica/Utilidad.h"
using namespace std;

class Simulacion
{
private:
  Utilidad utilidad;
  Configuracion configuracionAmbiente;

public:
  // Constructor
  Simulacion()
  {
    cout << "Comenzando Inicializacion." << endl;
    // Conseguir Config
    cout << "Leyendo archivo de configuracion." << endl;
    ifstream jsonFileStream("./config/Bodega.json");
    nlohmann ::json jsonData = nlohmann::json::parse(jsonFileStream);

    // Instanciar Config y otros attr
    Intervalo capacidadAlmacen = Intervalo(jsonData["capacidadAlmacen"]["minCapacidad"], jsonData["capacidadAlmacen"]["maxCapacidad"]);
    Intervalo capacidadCamion = Intervalo(jsonData["capacidadCamion"]["minCapacidad"], jsonData["capacidadCamion"]["maxCapacidad"]);
    Horario horarioDescarga = Horario(jsonData["horarioDescarga"]["horaInicio"], jsonData["horarioDescarga"]["horaNoAceptarMas"], jsonData["horarioDescarga"]["horaFin"]);
    Horario horarioCarga = Horario(jsonData["horarioCarga"]["horaInicio"], jsonData["horarioCarga"]["horaNoAceptarMas"], jsonData["horarioCarga"]["horaFin"]);
    Intervalo tiempoDescarga = Intervalo(jsonData["tiempoDescarga"]["minimoTiempo"], jsonData["tiempoDescarga"]["maximoTiempo"]);
    Intervalo tiempoCarga = Intervalo(jsonData["tiempoCarga"]["minimoTiempo"], jsonData["tiempoCarga"]["maximoTiempo"]);
    vector<string> tiposProductos = jsonData["tiposProductos"];

    cout << "Iniciando construccion de ambiente." << endl;
    configuracionAmbiente = Configuracion(capacidadAlmacen,
                                          capacidadCamion,
                                          horarioDescarga,
                                          horarioCarga,
                                          tiempoDescarga,
                                          tiempoCarga,
                                          // Pre-llenado de informacion
                                          tiposProductos);

    cout << "Cargando informacion pre-definida." << endl;
    utilidad = Utilidad(configuracionAmbiente.capacidadAlmacen, configuracionAmbiente.tiposProductos);
  }

  int capacidadC()
  {
    int numeroAleatorio = rand() % (configuracionAmbiente.capacidadCamion.getMaximo() - configuracionAmbiente.capacidadCamion.getMinimo() + 1) + configuracionAmbiente.capacidadCamion.getMinimo();
    return numeroAleatorio;
  }

  string tipoC()
  {

    int x = rand() % sizeof(configuracionAmbiente.tiposProductos);
    return configuracionAmbiente.tiposProductos[x];
  }

  Produ produC(string nombre)
  {

    int numeroAleatorio;
    do
    {
      numeroAleatorio = (rand() % 201) + 100;
    } while (numeroAleatorio % 5 != 0);

    Produ nuevoP = Produ(nombre, numeroAleatorio);

    return nuevoP;
  }

  int calcularT(){
    int tiempo = rand() % (configuracionAmbiente.tiempoDescarga.getMaximo() - configuracionAmbiente.tiempoDescarga.getMinimo() + 1) + configuracionAmbiente.tiempoDescarga.getMinimo();
    return tiempo*5;
  }

  void empezarSimulacion()
  {

    for (int i = 0; i < 100; i++)
    {
      int probC = rand() % 5;
      if (probC < 3)
      {
        int a = capacidadC();
        string b = tipoC();

        Pila<Produ> cargamento;
        Camion camion = Camion(a, b, cargamento);
        for (int i = 0; i < 3; i++)
        {
          Produ c = produC(b);
          if (a - camion.getEspacioO() > c.getValor())
          {
            camion.cargarProducto(c);
          }
        }
        utilidad.ingresarCamion(camion);
      }
      int tiempo = calcularT();
      int z = utilidad.RevisarCola();
      if (z = 1){
       
        i += tiempo / 5;
        cout<<"Se proceso un camion y duro "<< tiempo/5 <<" minutos"<<endl;
      }
    }
  }
};
