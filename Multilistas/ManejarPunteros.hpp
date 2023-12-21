#ifndef MANEJAR_PUNTEROS_HPP
#define MANEJAR_PUNTEROS_HPP

#include "../Librerias/Arbol.hpp"
#include "../Estructuras/Cabecera.hpp"

using namespace Arbol;

// T es el tipo de dato, int, string, etc,
// S es el objeto, empleado, hijo, etc
template <class T, class S>
struct GettersObjeto
{
    T(S::*obtenerDato)
    () const;
    S *(S::*obtenerPunteroAnt)() const;
    S *(S::*obtenerPunteroSig)() const;
};

template <class T, class S>
struct SettersObjeto
{
    void (S::*setDato)(const T &);
    void (S::*setPunteroAnt)(S *);
    void (S::*setPunteroSig)(S *);
};

class ManejarPunteros
{
public:
    template <class T, class S>
    void OrganizarPunterosAlAgregar(
        RBTree<T, Cabecera<S>> *arbolCabecera,
        S *objeto,
        GettersObjeto<T, S> getters,
        SettersObjeto<T, S> setters);

    template <class T, class S>
    void ManejoDeCabecerasEliminar(
        RBTree<T, Cabecera<S>> *arbolCabecera,
        S *objeto,
        GettersObjeto<T, S> getters,
        SettersObjeto<T, S> setters);

    template <class T, class S>
    GettersObjeto<T, S> CofigurarGetters(
        T (S::*getAtributo)() const,
        S *(S::*getPunteroAnt)() const,
        S *(S::*getPunteroSig)() const);

    template <class T, class S>
    SettersObjeto<T, S> ConfigurarSetters(
        void (S::*setAtributo)(const T &),
        void (S::*setPunteroAnt)(S *),
        void (S::*setPunteroSig)(S *));

private:
    // Metodo para agregar
    template <class T, class S>
    void AgregarANodoNoExistente(
        RBTree<T, Cabecera<S>> *arbolCabecera,
        S *objeto,
        GettersObjeto<T, S> getters,
        SettersObjeto<T, S> setters);

    template <class T, class S>
    void AgregarANodoExistente(
        RBTree<T, Cabecera<S>> *arbolCabecera,
        S *objeto,
        GettersObjeto<T, S> getters,
        SettersObjeto<T, S> setters);

    template <class T, class S>
    void AgregarANodoExistenteUnDato(
        Cabecera<S> &cabecera,
        S *objeto,
        GettersObjeto<T, S> getters,
        SettersObjeto<T, S> setters);

    template <class T, class S>
    void AgregarANodoExisteVariosDatos(
        Cabecera<S> &cabecera,
        S *objeto,
        GettersObjeto<T, S> getters,
        SettersObjeto<T, S> setters);

    // Metodos para eliminar
    template <class T, class S>
    void ManejoCabeceraAlEliminarPrimerElemento(
        Cabecera<S> &cabecera,
        GettersObjeto<T, S> getters,
        SettersObjeto<T, S> setters);

    template <class T, class S>
    void ManejoCabeceraAlEliminarUltimoElemento(
        Cabecera<S> &cabecera,
        GettersObjeto<T, S> getters,
        SettersObjeto<T, S> setters);

    template <class T, class S>
    void ManejoCabeceraAlEliminarCualquierElemento(
        S *objeto,
        GettersObjeto<T, S> getters,
        SettersObjeto<T, S> setters);

    template <class T, class S>
    void ManejoArbolCabecera(RBTree<T, Cabecera<S>> *arbolCabecera, Nodo<T, Cabecera<S>> *nodo);
};

template <class T, class S>
GettersObjeto<T, S> ManejarPunteros::CofigurarGetters(
    T (S::*getAtributo)() const,
    S *(S::*getPunteroAnt)() const,
    S *(S::*getPunteroSig)() const)
{
    GettersObjeto<T, S> getters;
    getters.obtenerDato = getAtributo;
    getters.obtenerPunteroAnt = getPunteroAnt;
    getters.obtenerPunteroSig = getPunteroSig;
    return getters;
}

template <class T, class S>
SettersObjeto<T, S> ManejarPunteros::ConfigurarSetters(
    void (S::*setAtributo)(const T &),
    void (S::*setPunteroAnt)(S *),
    void (S::*setPunteroSig)(S *))
{
    SettersObjeto<T, S> setters;
    setters.setDato = setAtributo;
    setters.setPunteroAnt = setPunteroAnt;
    setters.setPunteroSig = setPunteroSig;
    return setters;
}

template <class T, class S>
void ManejarPunteros::OrganizarPunterosAlAgregar(
    RBTree<T, Cabecera<S>> *arbolCabecera,
    S *objeto,
    GettersObjeto<T, S> getters,
    SettersObjeto<T, S> setters)
{
    if (arbolCabecera->findNodo((objeto->*getters.obtenerDato)()) == arbolCabecera->getNullNode())
        AgregarANodoNoExistente(arbolCabecera, objeto, getters, setters);
    else
        AgregarANodoExistente(arbolCabecera, objeto, getters, setters);
}

template <class T, class S>
void ManejarPunteros::AgregarANodoNoExistente(
    RBTree<T, Cabecera<S>> *arbolCabecera,
    S *objeto,
    GettersObjeto<T, S> getters,
    SettersObjeto<T, S> setters)
{
    Cabecera<S> cabecera;
    cabecera.primerDato = objeto;
    cabecera.ultimoDato = NULL;
    (cabecera.primerDato->*setters.setPunteroAnt)(NULL);
    (cabecera.primerDato->*setters.setPunteroSig)(NULL);

    Nodo<std::string, Cabecera<S>> *nodo = arbolCabecera->createNodo((objeto->*getters.obtenerDato)(), cabecera);
    arbolCabecera->Insert(arbolCabecera, nodo);
}

template <class T, class S>
void ManejarPunteros::AgregarANodoExistente(
    RBTree<T, Cabecera<S>> *arbolCabecera,
    S *objeto,
    GettersObjeto<T, S> getters,
    SettersObjeto<T, S> setters)
{
    Cabecera<S> &cabecera = arbolCabecera->findNodo((objeto->*getters.obtenerDato)())->Valor;
    if (cabecera.ultimoDato == NULL)
        AgregarANodoExistenteUnDato(cabecera, objeto, getters, setters);
    else
        AgregarANodoExisteVariosDatos(cabecera, objeto, getters, setters);
}

template <class T, class S>
void ManejarPunteros::AgregarANodoExistenteUnDato(
    Cabecera<S> &cabecera,
    S *objeto,
    GettersObjeto<T, S> getters,
    SettersObjeto<T, S> setters)
{
    cabecera.ultimoDato = objeto;
    (cabecera.ultimoDato->*setters.setPunteroAnt)(cabecera.primerDato);
    (cabecera.primerDato->*setters.setPunteroSig)(cabecera.ultimoDato);
    (cabecera.ultimoDato->*setters.setPunteroSig)(NULL);
}

template <class T, class S>
void ManejarPunteros::AgregarANodoExisteVariosDatos(
    Cabecera<S> &cabecera,
    S *objeto,
    GettersObjeto<T, S> getters,
    SettersObjeto<T, S> setters)
{
    (cabecera.ultimoDato->*setters.setPunteroSig)(objeto);
    (objeto->*setters.setPunteroAnt)(cabecera.ultimoDato);
    cabecera.ultimoDato = objeto;
    (cabecera.ultimoDato->*setters.setPunteroSig)(NULL);
}

template <class T, class S>
void ManejarPunteros::ManejoDeCabecerasEliminar(
    RBTree<T, Cabecera<S>> *arbolCabecera,
    S *objeto,
    GettersObjeto<T, S> getters,
    SettersObjeto<T, S> setters)
{
    Nodo<T, Cabecera<S>> *nodo = arbolCabecera->findNodo((objeto->*getters.obtenerDato)());
    Cabecera<S> &cabecera = nodo->Valor;

    if (cabecera.primerDato == objeto)
        ManejoCabeceraAlEliminarPrimerElemento(cabecera, getters, setters);
    else if (cabecera.ultimoDato == objeto)
        ManejoCabeceraAlEliminarUltimoElemento(cabecera, getters, setters);
    else
        ManejoCabeceraAlEliminarCualquierElemento(objeto, getters, setters);

    (objeto->*setters.setPunteroAnt)(NULL);
    (objeto->*setters.setPunteroSig)(NULL);
    ManejoArbolCabecera(arbolCabecera, nodo);
}

template <class T, class S>
void ManejarPunteros::ManejoCabeceraAlEliminarPrimerElemento(
    Cabecera<S> &cabecera,
    GettersObjeto<T, S> getters,
    SettersObjeto<T, S> setters)
{
    S *sigObjeto = (cabecera.primerDato->*getters.obtenerPunteroSig)();
    cabecera.primerDato = sigObjeto;

    if (cabecera.primerDato != NULL)
        (cabecera.primerDato->*setters.setPunteroAnt)(NULL);
}

template <class T, class S>
void ManejarPunteros::ManejoCabeceraAlEliminarUltimoElemento(
    Cabecera<S> &cabecera,
    GettersObjeto<T, S> getters,
    SettersObjeto<T, S> setters)
{
    S *objetoAnt = (cabecera.ultimoDato->*getters.obtenerPunteroAnt)();
    cabecera.ultimoDato = objetoAnt;
    (cabecera.ultimoDato->*setters.setPunteroSig)(NULL);
}

template <class T, class S>
void ManejarPunteros::ManejoCabeceraAlEliminarCualquierElemento(
    S *objeto,
    GettersObjeto<T, S> getters,
    SettersObjeto<T, S> setters)
{
    S *objetoAnt = (objeto->*getters.obtenerPunteroAnt)();
    S *objetoSig = (objeto->*getters.obtenerPunteroSig)();
    (objetoAnt->*setters.setPunteroSig)(objetoSig);
    (objetoSig->*setters.setPunteroAnt)(objetoAnt);
}

template <class T, class S>
void ManejarPunteros::ManejoArbolCabecera(RBTree<T, Cabecera<S>> *arbolCabecera, Nodo<T, Cabecera<S>> *nodo)
{
    if (nodo->Valor.primerDato == NULL && nodo->Valor.ultimoDato == NULL)
        arbolCabecera->Delete(arbolCabecera, nodo);
}
#endif