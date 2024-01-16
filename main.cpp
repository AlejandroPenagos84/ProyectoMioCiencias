#include <iostream>
#include "Librerias/Arbol.hpp"
#include "Multilistas/Multilista.hpp"
#include "Multilistas/MultilistaEmpleados/MultilitaEmpleado.hpp"
#include "Estructuras/Cabecera.hpp"
#include "Librerias/ListaDoble.hpp"
#include "Multilistas/ManejarPunteros.hpp"
#include "ControlDAO/ControlDao.hpp"
#include "Fabricas/FabricaAbstracta.hpp"
#include "Fabricas/FabricaEmpleado/FabricaEmpleado.hpp"

#include "Controlador/Controlador.hpp"

#include <fstream>
#include <cstdlib>
#include <direct.h>

#define for(i, n) for (int i = 0; i < n; ++i)
#define PRINT(x) std::cout << x
#define PRINTLN(x) std::cout << x << "\n"

using namespace ListaDoble;
using namespace Cola;
using namespace Arbol;

int main()
{
    Controlador control;
    /*
    // Construir una ruta relativa
    const char *nombre_archivo = "\\Archivos\\Empleados.csv";

    // Obtener el directorio de trabajo actual
    char buffer[FILENAME_MAX];
    if (getcwd(buffer, sizeof(buffer)) == NULL)
    {
        std::cerr << "Error al obtener el directorio actual." << std::endl;
        return 1;
    }

    // Concatenar el nombre del archivo a la ruta del directorio actual
    std::string ruta_relativa = std::string(buffer) + nombre_archivo;
    std::cout << ruta_relativa << std::endl;

    ControlDao controlDao;

    Multilista<Empleado> *MultilistaEmpleados = new MultilistaEmpleado;
    FabricaAbtracta<Empleado> *FabricaEmpleados = new FabricaEmpleado;

    Queue<Nodo<std::string, Empleado> *> cola = FabricaEmpleados->crearArbol(controlDao.LeerDAO(ruta_relativa))->inorden();

    while (!cola.IsEmpty())
        MultilistaEmpleados->Agregar(cola.Dequeue('I')->Valor);

    // Intentar realizar el casting dinámico
    MultilistaEmpleado *multilistaEmpleado = dynamic_cast<MultilistaEmpleado *>(MultilistaEmpleados);

    // Verificar si el casting fue exitoso
    if (multilistaEmpleado != NULL)
    {
        // Ahora puedes acceder a los métodos específicos de MultilistaEmpleado
        Nodo<std::string, Cabecera<Empleado>> *n = multilistaEmpleado->getCabeceraCiudadNacimiento()->findNodo("New York");

        Empleado *aux = n->Valor.primerDato;

        while (aux != NULL)
        {
            if (aux != NULL)
            {
                PRINTLN(aux->getNombre());
            }
            aux = aux->getSigCiudadNacimiento();
        }

        MultilistaEmpleados->Eliminar("Bob Smith");
        PRINTLN("-----------------------------------------");

        aux = n->Valor.primerDato;

        while (aux != NULL)
        {
            if (aux != NULL)
            {
                PRINTLN(aux->getNombre());
            }
            aux = aux->getSigCiudadNacimiento();
        }
    }
    else
    {
        // El casting no fue exitoso, manejar el caso en el que MultilistaEmpleados no es un MultilistaEmpleado
        PRINTLN("No se pudo realizar el casting a MultilistaEmpleado.");
    }
    */
    return 0;
}
