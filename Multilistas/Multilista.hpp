#ifndef MULTILISTA_HPP
#define MULTILISTA_HPP
#include "ManejarPunteros.hpp"

template <class T>
class Multilista
{
public:
    ManejarPunteros manejoPunteros;
    virtual void Agregar(T &) = 0;
    virtual void Eliminar(std::string) = 0;
    virtual void Modificar(std::string, T) = 0;
};

#endif
