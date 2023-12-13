#ifndef FABRICA_EMPLEADO_HPP
#define FABRICA_EMPLEADO_HPP
#include "../FabricaAbstracta.hpp"
#include "../../Estructuras/Empleado.hpp"

class FabricaEmpleado : public FabricaAbtracta<Empleado>
{
public:
    Empleado crearObjeto(DoubleLinkedList<std::string> listaAtributos);
    RBTree<std::string, Empleado> *crearArbol(DoubleLinkedList<DoubleLinkedList<std::string>> listaEmpleados);

private:
    bool tieneHijosToBool(std::string tieneHijos);
    bool sexoToBool(std::string sexo);
};
#endif