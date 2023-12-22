#ifndef MODIFICAR_ATRIBUTOS_HPP
#define MODIFICAR_ATRIBUTOS_HPP
#include "ManejarPunteros.hpp"

using namespace Arbol;

class ModificarAtributos
{
private:
    ManejarPunteros *manejoPunterosModificar;

public:
    ModificarAtributos()
    {
        manejoPunterosModificar = new ManejarPunteros();
    }

    template <class T, class S>
    void ModificarAtributoSinPunteros(
        S *objetoEnArbol, S *nuevoElemento,
        T (S::*obtenerDato)() const, void (S::*setDato)(const T &));

    template <class T, class S>
    void ModificarAtributoConPunteros(
        RBTree<T, Cabecera<S>> *arbolCabecera,
        S *objetoEnArbol, S *nuevoElemento,
        GettersObjeto<T, S> getters,
        SettersObjeto<T, S> setters);
};

template <class T, class S>
void ModificarAtributos::ModificarAtributoSinPunteros(
    S *objetoEnArbol, S *nuevoElemento, T (S::*obtenerDato)() const, void (S::*setDato)(const T &))
{
    if ((objetoEnArbol->*obtenerDato)() != (nuevoElemento->*obtenerDato)())
        (objetoEnArbol->*setDato)((nuevoElemento->*obtenerDato)());
}

template <class T, class S>
void ModificarAtributos::ModificarAtributoConPunteros(
    RBTree<T, Cabecera<S>> *arbolCabecera, S *objetoEnArbol, S *nuevoElemento, GettersObjeto<T, S> getters, SettersObjeto<T, S> setters)
{
    if ((objetoEnArbol->*getters.obtenerDato)() != (nuevoElemento->*getters.obtenerDato)())
    {
        manejoPunterosModificar->ManejoDeCabecerasEliminar(arbolCabecera, objetoEnArbol, getters, setters);
        (objetoEnArbol->*setters.setDato)((nuevoElemento->*getters.obtenerDato)());
        manejoPunterosModificar->OrganizarPunterosAlAgregar(arbolCabecera, objetoEnArbol, getters, setters);
    }
}
#endif