#include "MultilitaEmpleado.hpp"

MultilistaEmpleado::MultilistaEmpleado()
{
    arbolEmpleados = new RBTree<std::string, Empleado>;
    cabeceraCiudadNacimiento = new RBTree<std::string, Cabecera<Empleado>>;
    cabeceraPaisNacimiento = new RBTree<std::string, Cabecera<Empleado>>;
    cabeceraCiudadResidencia = new RBTree<std::string, Cabecera<Empleado>>;
    cabeceraPaisResidencia = new RBTree<std::string, Cabecera<Empleado>>;
    cabeceraActividadLaboral = new RBTree<std::string, Cabecera<Empleado>>;
}

void MultilistaEmpleado::Agregar(Empleado &empleado)
{

    std::string nombreCompleto = empleado.getNombre() + " " + empleado.getApellido();
    Nodo<std::string, Empleado> *nodo = arbolEmpleados->createNodo(nombreCompleto, empleado);
    arbolEmpleados->Insert(arbolEmpleados, nodo);

    GettersEmpleado<std::string> getterEmpleadoCiudadNacimiento = ConfigurarGettersEmpleado(&Empleado::getCiudadNacimiento, &Empleado::getAntCiudadNacimiento, &Empleado::getSigCiudadNacimiento);
    SettersEmpleado<std::string> setterEmpleadoCiudadNacimiento = ConfigurarSettersEmpleado(&Empleado::setCiudadNacimiento, &Empleado::setAntCiudadNacimiento, &Empleado::setSigCiudadNacimiento);
    OrganizarGenerico(cabeceraCiudadNacimiento, &empleado, getterEmpleadoCiudadNacimiento, setterEmpleadoCiudadNacimiento);
    empleados.AddLast(empleado);
}

GettersEmpleado<std::string> MultilistaEmpleado::ConfigurarGettersEmpleado(std::string (Empleado::*atributo)() const, Empleado *(Empleado::*punteroAnt)() const, Empleado *(Empleado::*punteroSig)() const)
{
    GettersEmpleado<std::string> getters;
    getters.obtenerDato = atributo;
    getters.obtenerPunteroAnt = punteroAnt;
    getters.obtenerPunteroSig = punteroSig;
    return getters;
}

SettersEmpleado<std::string> MultilistaEmpleado::ConfigurarSettersEmpleado(void (Empleado::*setAtributo)(const std::string &), void (Empleado::*setPunteroAnt)(Empleado *), void (Empleado::*setPunteroSig)(Empleado *))
{
    SettersEmpleado<std::string> setters;
    setters.setDato = setAtributo;
    setters.setPunteroAnt = setPunteroAnt;
    setters.setPunteroSig = setPunteroSig;
    return setters;
}

void MultilistaEmpleado::OrganizarGenerico(RBTree<std::string, Cabecera<Empleado>> *arbolCabecera, Empleado *empleado, GettersEmpleado<std::string> getters, SettersEmpleado<std::string> setters)
{
    //* Si no existe un nodo con el dato especificado, eso significa que el dato no existe, por ello se agrega un nodo a un árbol
    if (arbolCabecera->findNodo((empleado->*getters.obtenerDato)()) == arbolCabecera->getNullNode())
        ManejarNodoNoExistente(arbolCabecera, empleado, getters, setters);
    else
        //* Ya existe un nodo en el árbol con el dato del empleado
        ManejarNodoExistente(arbolCabecera, empleado, getters, setters);
}

void MultilistaEmpleado::ManejarNodoNoExistente(RBTree<std::string, Cabecera<Empleado>> *arbolCabecera, Empleado *empleado, GettersEmpleado<std::string> getters, SettersEmpleado<std::string> setters)
{
    Cabecera<Empleado> cabEmpleado;

    cabEmpleado.primerDato = empleado;
    cabEmpleado.ultimoDato = NULL;

    // Crea un nuevo nodo con la cabecera ya hecha y lo agrega al árbol
    Nodo<std::string, Cabecera<Empleado>> *nodo = arbolCabecera->createNodo((empleado->*getters.obtenerDato)(), cabEmpleado);
    arbolCabecera->Insert(arbolCabecera, nodo);
}

void MultilistaEmpleado::ManejarNodoExistente(RBTree<std::string, Cabecera<Empleado>> *arbolCabecera, Empleado *empleado, GettersEmpleado<std::string> getters, SettersEmpleado<std::string> setters)
{
    Cabecera<Empleado> &cabEmpleado = arbolCabecera->findNodo((empleado->*getters.obtenerDato)())->Valor;
    if (cabEmpleado.ultimoDato == NULL)
    {
        cabEmpleado.ultimoDato = empleado;
        (cabEmpleado.ultimoDato->*setters.setPunteroAnt)(cabEmpleado.primerDato);
        (cabEmpleado.primerDato->*setters.setPunteroSig)(cabEmpleado.ultimoDato);
        (cabEmpleado.ultimoDato->*setters.setPunteroSig)(NULL);
    }
    else
    {
        // Leer el codigo como set(Dato)
        (cabEmpleado.ultimoDato->*setters.setPunteroSig)(empleado);
        (empleado->*setters.setPunteroAnt)(cabEmpleado.ultimoDato);
        cabEmpleado.ultimoDato = empleado;
        (cabEmpleado.ultimoDato->*setters.setPunteroSig)(NULL);
    }
}

void MultilistaEmpleado::Eliminar(Empleado &empleado)
{
}

void MultilistaEmpleado::Modificar(Empleado &empleado) {}

RBTree<std::string, Cabecera<Empleado>> *MultilistaEmpleado::getCabeceraCiudadNacimiento() { return cabeceraCiudadNacimiento; }
RBTree<std::string, Cabecera<Empleado>> *MultilistaEmpleado::getCabeceraPaisNacimiento() { return cabeceraPaisNacimiento; }
RBTree<std::string, Cabecera<Empleado>> *MultilistaEmpleado::getCabeceraPaisResidencia() { return cabeceraPaisResidencia; }
RBTree<std::string, Cabecera<Empleado>> *MultilistaEmpleado::getCabeceraCiudadResidencia() { return cabeceraCiudadResidencia; }
RBTree<std::string, Cabecera<Empleado>> *MultilistaEmpleado::getCabeceraActividadLaboral() { return cabeceraActividadLaboral; }