#include <iostream>
#include "Librerias/Arbol.hpp"
#include "Multilistas/Multilista.hpp"
#include "Multilistas/MultilistaEmpleados/MultilitaEmpleado.hpp"
#include "Estructuras/Cabecera.hpp"

#include "Librerias/ListaDoble.hpp"
#include "Multilistas/ManejarPunteros.hpp"
#include "ControlDAO/ControlDaoEmpleado.hpp"

#define for(i, n) for (int i = 0; i < n; ++i)
#define PRINT(x) std::cout << x
#define PRINTLN(x) std::cout << x << "\n"

using namespace ListaDoble;
using namespace Cola;
using namespace Arbol;
int main()
{
    ControlDao<Empleado> *controlDao = new ControlDaoEmpleado;

    Multilista<Empleado> *MultilistaEmpleados = new MultilistaEmpleado;
    controlDao->LeerDAO("C:\\Users\\Alejandro Penagos\\Desktop\\ProyectosCiencias\\ProyectoMio\\Archivos\\Empleados.csv");

    Queue<Nodo<std::string, Empleado> *> cola = controlDao->getArbol()->inorden();
    while (!cola.IsEmpty())
        MultilistaEmpleados->Agregar(cola.Dequeue('I')->Valor);

    if (auto *multilistaEmpleado = dynamic_cast<MultilistaEmpleado *>(MultilistaEmpleados))
    {
        // Solo si el casting es exitoso, puedes acceder a los métodos específicos de MultilistaEmpleado
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

    return 0;
}