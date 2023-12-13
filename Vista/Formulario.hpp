#ifndef FORMULARIO_HPP
#define FORMULARIO_HPP
#include "../Librerias/ListaDoble.hpp"
#include <string>

using namespace ListaDoble;
class Formulario
{
public:
    virtual DoubleLinkedList<std::string> SolicitarDatos() = 0;
};
#endif