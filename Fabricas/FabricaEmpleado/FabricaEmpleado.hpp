#ifndef FABRICA_EMPLEADO_HPP
#define FABRICA_EMPLEADO_HPP
#include "../FabricaAbstracta.hpp"
#include "../../Estructuras/Empleado.hpp"
#include <cstdlib>
#include <sstream>

class FabricaEmpleado : public FabricaAbtracta<Empleado>
{
public:
    Empleado crearObjeto(DoubleLinkedList<std::string> listaAtributos);
    RBTree<std::string, Empleado> *crearArbol(DoubleLinkedList<DoubleLinkedList<std::string>> listaEmpleados);
    DoubleLinkedList<std::string> *crearListaDeAtributos(Empleado empleado);

private:
    bool tieneHijosToBool(std::string tieneHijos);
    bool sexoToBool(std::string sexo);
    std::string sexoToString(bool sexo);
    std::string tieneHijosToString(bool tieneHijos);

    template <class T>
    std::string convertirAString(const T &valor);
};
#endif