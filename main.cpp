#include <iostream>
#include "Librerias/Arbol.hpp"
#include "Multilistas/Multilista.hpp"
#include "Multilistas/MultilistaEmpleados/MultilitaEmpleado.hpp"
#include "Estructuras/Cabecera.hpp"

#include "Librerias/ListaDoble.hpp"

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
        Nodo<std::string, Cabecera<Empleado>> *n = multilistaEmpleado->getCabeceraActividadLaboral()->findNodo("Ingeniero de Software");

        Empleado *aux = n->Valor.primerDato;
        std::cout << aux->getNombre() << std::endl;
        std::cout << (aux->getSigActividadLaboral() == NULL) << std::endl;

        while (aux != NULL)
        {
            if (aux != NULL)
            {
                PRINTLN(aux->getNombre());
            }
            aux = aux->getSigActividadLaboral();
        }
        multilistaEmpleado->Eliminar("Will Smith");
        aux = n->Valor.primerDato;

        PRINTLN("-----------------------------------------");

        while (aux != NULL)
        {
            if (aux != NULL)
            {
                PRINTLN(aux->getNombre());
            }
            aux = aux->getSigActividadLaboral();
        }
    }

    return 0;
}