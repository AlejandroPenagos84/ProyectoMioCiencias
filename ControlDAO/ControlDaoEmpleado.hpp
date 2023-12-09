#ifndef CONTROLDAOEMPLEADO_HPP
#define CONTROLDAOEMPLEADO_HPP
#include "../Librerias/ListaDoble.hpp"
#include "../Librerias/Arbol.hpp"
#include "../Estructuras/Empleado.hpp"
#include "ControlDao.hpp"

#include <fstream>
#include <string>
#include <sstream>
#include <iostream>
using namespace Arbol;
using namespace ListaDoble;

class ControlDaoEmpleado : public ControlDao<Empleado>
{
    //  En el arbol se guardará el nombre del empleado al empleado en si
    RBTree<std::string, Empleado> *arbolEmpleados;

public:
    ControlDaoEmpleado();
    void LeerDAO(const std::string &filename) override;
    void AgregarDAO(const std::string &filename, Empleado Empleado) override;
    void EliminarDAO(const std::string &filename, Empleado Empleado) override;
    void ModificarDAO(const std::string &filename, Empleado Empleado) override;
    RBTree<std::string, Empleado> *getArbol();

private:
    bool sexoToBool(std::string sexo);
    bool tieneHijosToBool(std::string tieneHijos);
};
#endif