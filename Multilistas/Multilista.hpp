#ifndef MULTILISTA_HPP
#define MULTILISTA_HPP
#include "ManejarPunteros.hpp"
#include "ModificarAtributos.hpp"
template <class T>
class Multilista
{
protected:
    ManejarPunteros *manejoPunteros;
    ModificarAtributos *modificarAtributos;

public:
    Multilista();
    virtual void Agregar(T &) = 0;
    virtual void Eliminar(std::string) = 0;
    virtual void Modificar(std::string, T *) = 0;
    virtual T *getObjeto(std::string) = 0;
    virtual int getSize() = 0;
};

template <class T>
Multilista<T>::Multilista()
{
    manejoPunteros = new ManejarPunteros();
    modificarAtributos = new ModificarAtributos();
}

#endif
