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

    DoubleLinkedList<int> numeros;

    std::cout << numeros.Size();

    ControlDao controlDao;
    controlDao.LeerEmpleadoDAO("C:\\Users\\Alejandro Penagos\\Desktop\\ProyectosCiencias\\ProyectoMio\\Archivos\\Empleados.csv");

    Queue<Nodo<std::string, Empleado> *> cola = controlDao.getArbol()->inorden();
}