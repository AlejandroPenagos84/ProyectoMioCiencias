#ifndef CONTROLDAO_HPP
#define CONTROLDAO_HPP
#include "../Librerias/ListaDoble.hpp"
#include <fstream>
#include <string>
#include "../Librerias/Arbol.hpp"
#include "../Estructuras/Empleado.hpp"
#include <sstream>
#include <iostream>
using namespace Arbol;
using namespace ListaDoble;

class ControlDao
{
    //  En el arbol se guardará el nombre del empleado al empleado en si
    RBTree<std::string, Empleado> *arbolEmpleados;

public:
    ControlDao();
    void LeerEmpleadoDAO(const std::string &filename);
    RBTree<std::string, Empleado> *getArbol();

private:
    bool sexoToBool(std::string sexo);
    bool tieneHijosToBool(std::string tieneHijos);
};
#endif