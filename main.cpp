#include <iostream>
#include "Librerias/Arbol.hpp"
#include "MultilistasEmpleados/MultilitaEmpleado.hpp"
#include "Librerias/ListaDoble.hpp"
#include "ControlDAO/ControlDao.hpp"

#define for(i, n) for (int i = 0; i < n; ++i)
#define PRINT(x) std::cout << x
#define PRINTLN(x) std::cout << x << std::endl

using namespace ListaDoble;
using namespace Cola;
using namespace Arbol;
int main()
{
    ControlDao controlDao;
    MultilistaEmpleado multilista;
    controlDao.LeerEmpleadoDAO("C:\\Users\\Alejandro Penagos\\Desktop\\ProyectosCiencias\\ProyectoMio\\Archivos\\Empleados.csv");

    Queue<Nodo<std::string, Empleado> *> cola = controlDao.getArbol()->inorden();
    while (!cola.IsEmpty())
    {
        multilista.AgregarEmpleado(cola.Dequeue('I')->Valor);
    }

    Nodo<std::string, Cabecera<Empleado>> *n = multilista.getCabeceraCiudadNacimiento()->findNodo("New York");

    Empleado *aux = n->Valor.primerDato;

    while (aux != NULL)
    {
        PRINTLN(aux->nombre);
        PRINTLN(aux->ciudadNacimiento);
        aux = aux->sigCiudadNacimiento;
    }

    /*
    std::cout << cola.Dequeue('D')->Clave << std::endl;
    std::cout << cola.Dequeue('D')->Clave << std::endl;
    std::cout << cola.Dequeue('D')->Clave << std::endl;
    std::cout << cola.Dequeue('D')->Clave << std::endl;
    std::cout << cola.Dequeue('D')->Clave << std::endl;
    */
}