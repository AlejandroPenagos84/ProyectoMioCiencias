#ifndef FABRICA_ABSTRACTA_HPP
#define FABRICA_ABSTRACTA_HPP
#include <string>
#include "../Librerias/ListaDoble.hpp"
#include "../Librerias/Arbol.hpp"
#include <iostream>

using namespace ListaDoble;
using namespace Arbol;

template <class T>
class FabricaAbtracta
{
public:
    virtual T crearObjeto(DoubleLinkedList<std::string>) = 0;
    virtual RBTree<std::string, T> *crearArbol(DoubleLinkedList<DoubleLinkedList<std::string>>) = 0;
    virtual DoubleLinkedList<std::string> *crearListaDeAtributos(T) = 0;
};
#endif