#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <fstream>
#include <json/value.h>
#include "clases/Pila.h"
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
    std::ifstream config_file("./config/Bodega.json", std::ifstream::binary);
    Json::Value config;
    config_file >> config;

    cout << config;
    // Instanciar Config y otros attr
    cout << "Iniciando construccion de ambiente." << endl;
    configuracionAmbiente = new Configuracion(config["capacidadAlmacen"],
                                              config["capacidadCamion"],
                                              config["horarioDescarga"],
                                              config["horarioCarga"],
                                              config["tiempoDescarga"],
                                              config["tiempoCarga"],
                                              config["producto"],
                                              // Pre-llenado de informacion
                                              config["tiposProductos"]);

    cout << "Cargando informacion pre-definida." << endl;
    utilidad = new Utilidad(configuracionAmbiente.capacidadAlmacen, configuracionAmbiente.tiposProductos)
  }

  void empezarSimulacion()
  {
    // Aqui comienza la simulacion a enviar señales a la clase Utilidad
  }

  // Método para agregar una nueva pila de productos a la lista (si no existe)

  void pasarElementosAux(Pila<Camion> &pilaCamion, Pila<Almacen> &pilaAlmacen)
  {
    int MaxLargo = 10;
    if (MaxLargo - sizeof(pilaAlmacen) >= sizeof(pilaCamion))
    {
      pasarElementosFull(pilaCamion, pilaAlmacen);
    }
    else if (MaxLargo - sizeof(pilaAlmacen) < sizeof(pilaCamion))
    {
      bool R = respuesta();
      if (R == true)
      {
        pasarElementosParcial(pilaCamion, pilaAlmacen, MaxLargo - sizeof(pilaAlmacen));
      }
    }
    else if (MaxLargo - sizeof(pilaAlmacen) == 0)
    {
      cout << "No queda campo para este tipo de producto";
    }
  }

  // Función para pasar elementos de la Lista A a la Lista B
  void pasarElementosFull(Pila<Camion> &pilaCamion, Pila<Almacen> &pilaAlmacen)
  {
    while (!pilaCamion.isEmpty())
    {
      Camion elemento = pilaCamion.top(); // Obtener el elemento superior de A
      pilaCamion.pop();                   // Eliminar el elemento superior de A
      Pila<Produ> productos = elemento.getPila();
      while (productos.isEmpty())
      {
        pilaAlmacen.push(productos.pop()); // Agregar el elemento a B
      }
    }
  }

  void pasarElementosParcial(Pila<Camion> &pilaCamion, Pila<Almacen> &pilaAlmacen, int cantPasar)
  {

    for (int i = 0; i < cantPasar; i++)
    {
      if (!pilaCamion.estaVacia())
      {
        string elemento = pilaCamion.top(); // Obtener el elemento superior de la pilaCamion
        pilaCamion.pop();                   // Eliminar el elemento superior de la pilaCamion
        pilaAlmacen.push(elemento);         // Agregar el elemento a la pilaAlmacen
      }
      else
      {
        cout << "La pilaCamion está vacía. No se pueden pasar más elementos." << endl;
        break;
      }
    }
  }

  bool respuesta()
  {
    int opcion;

    cout << "No hay capacidad suficiente para guardar todo lo del camion." << endl;
    cout << "Desea guardar lo maximo posible o no desea guardar nada." << endl;
    cout << "1. Guardar lo maximo posible" << endl;
    cout << "2. No guardar." << endl;
    cout << "Ingrese 1 o 2: ";

    cin >> opcion;

    while (opcion != 1 && opcion != 2)
    {
      cout << "Opción no válida. Por favor, ingrese 1 o 2: ";
      cin >> opcion;
    }

    if (opcion == 1)
    {
      return true;
    }
    else
    {
      return false;
    }
  }
};
