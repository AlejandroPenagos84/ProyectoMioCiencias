#include <iostream>
#include "Librerias/Arbol.hpp"
#include "MultilistasEmpleados/MultilitaEmpleado.hpp"
#include "Librerias/ListaDoble.hpp"

#include "ControlDAO/ControlDaoEmpleado.hpp"
#include "Vista/Formulario.hpp"
#include "Vista/FormularioEmpleado.hpp"

#define for(i, n) for (int i = 0; i < n; ++i)
#define PRINT(x) std::cout << x
#define PRINTLN(x) std::cout << x << std::endl

using namespace ListaDoble;
using namespace Cola;
using namespace Arbol;
int main()
{
    ControlDao<Empleado> *controlDao = new ControlDaoEmpleado;

    MultilistaEmpleado multilista;
    controlDao->LeerDAO("C:\\Users\\Alejandro Penagos\\Desktop\\ProyectosCiencias\\ProyectoMio\\Archivos\\Empleados.csv");

    Queue<Nodo<std::string, Empleado> *> cola = controlDao->getArbol()->inorden();
    while (!cola.IsEmpty())
    {
        multilista.AgregarEmpleado(cola.Dequeue('I')->Valor);
    }

    Nodo<std::string, Cabecera<Empleado>> *n = multilista.getCabeceraPaisNacimiento()->findNodo("USA");

    Empleado *aux = n->Valor.primerDato;

    while (aux != NULL)
    {
        PRINTLN(aux->nombre);
        PRINTLN(aux->paisNacimiento);
        aux = aux->sigPaisNacimiento;
    }

    Formulario<Empleado> *formularioEmpleados = new FormularioEmpleado;
    formularioEmpleados->SolicitarDatos();
}