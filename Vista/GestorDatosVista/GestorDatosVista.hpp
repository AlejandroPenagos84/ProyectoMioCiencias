#ifndef GESTOR_DATOS_HPP
#define GESTOR_DATOS_HPP
#include "../../Librerias/ListaDoble.hpp"
#include <string>

using namespace ListaDoble;
class GestorDatosVista
{
public:
    virtual DoubleLinkedList<std::string> SolicitarDatosParaAgregar() = 0;
    virtual int ElegirAtributo(DoubleLinkedList<std::string>) = 0;
    virtual void MostrarAtributos(DoubleLinkedList<std::string>) = 0;
};
#endif