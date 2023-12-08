#include "MultilitaEmpleado.hpp"

MultilistaEmpleado::MultilistaEmpleado()
{
    // Inicialización de todos los árboles
    arbolEmpleados = new RBTree<std::string, Empleado>;
    cabeceraCiudadNacimiento = new RBTree<std::string, Cabecera<Empleado>>;
    cabeceraPaisNacimiento = new RBTree<std::string, Cabecera<Empleado>>;
    cabeceraCiudadResidencia = new RBTree<std::string, Cabecera<Empleado>>;
    cabeceraPaisResidencia = new RBTree<std::string, Cabecera<Empleado>>;
    cabeceraActividadLaboral = new RBTree<std::string, Cabecera<Empleado>>;
}

AtributosEmpleado<std::string> MultilistaEmpleado::ConfigurarAtributosEmpleados(std::string Empleado::*atributo, Empleado *Empleado::*punteroAnt, Empleado *Empleado::*punteroSig)
{
    AtributosEmpleado<std::string> atr;
    atr.dato = atributo;
    atr.punteroAnt = punteroAnt;
    atr.punteroSig = punteroSig;
    return atr;
}

void MultilistaEmpleado::AgregarEmpleado(Empleado &empleado)
{

    std::string nombreCompleto = empleado.nombre + " " + empleado.apellido;                   ///< Crear una cadena con el nombre completo del empleado
    Nodo<std::string, Empleado> *nodo = arbolEmpleados->createNodo(nombreCompleto, empleado); ///< Crear un nodo para agregar al árbol de empleados
    arbolEmpleados->Insert(arbolEmpleados, nodo);

    AtributosEmpleado<std::string> atrCiudadNacimiento = ConfigurarAtributosEmpleados(&Empleado::ciudadNacimiento, &Empleado::antCiudadNacimiento, &Empleado::sigCiudadNacimiento);
    OrganizarGenerico(cabeceraCiudadNacimiento, &empleado, atrCiudadNacimiento);

    AtributosEmpleado<std::string> atrPaisNacimiento = ConfigurarAtributosEmpleados(&Empleado::paisNacimiento, &Empleado::antPaisNacimiento, &Empleado::sigPaisNacimiento);
    OrganizarGenerico(cabeceraPaisNacimiento, &empleado, atrPaisNacimiento);

    AtributosEmpleado<std::string> atrCiudadResidencia = ConfigurarAtributosEmpleados(&Empleado::ciudadResidencia, &Empleado::antCiudadResidencia, &Empleado::sigCiudadResidencia);
    OrganizarGenerico(cabeceraCiudadResidencia, &empleado, atrCiudadResidencia);

    AtributosEmpleado<std::string> atrPaisResidencia = ConfigurarAtributosEmpleados(&Empleado::paisResidencia, &Empleado::antPaisResidencia, &Empleado::sigPaisResidencia);
    OrganizarGenerico(cabeceraPaisResidencia, &empleado, atrPaisResidencia);

    AtributosEmpleado<std::string> atrActividadLaboral = ConfigurarAtributosEmpleados(&Empleado::actividadLaboral, &Empleado::antActividadLaboral, &Empleado::sigActividadLaboral);
    OrganizarGenerico(cabeceraActividadLaboral, &empleado, atrActividadLaboral);

    // Agregar un empleado a la lista (Esta línea parece innecesaria, considera eliminarla)
    empleados.AddLast(empleado);
}

void MultilistaEmpleado::OrganizarGenerico(RBTree<std::string, Cabecera<Empleado>> *arbolCabecera, Empleado *empleado, AtributosEmpleado<std::string> atributos)
{
    //* Si no existe un nodo con el dato especificado, eso significa que el dato no existe, por ello se agrega un nodo a un árbol
    if (arbolCabecera->findNodo(empleado->*atributos.dato) == arbolCabecera->getNullNode())
        ManejarNodoNoExistente(arbolCabecera, empleado, atributos);
    else
        //* Ya existe un nodo en el árbol con el dato del empleado
        ManejarNodoExistente(arbolCabecera, empleado, atributos);
}

void MultilistaEmpleado::ManejarNodoNoExistente(RBTree<std::string, Cabecera<Empleado>> *arbolCabecera, Empleado *empleado, AtributosEmpleado<std::string> atributos)
{
    Cabecera<Empleado> cabEmpleado;

    cabEmpleado.primerDato = empleado;
    cabEmpleado.ultimoDato = NULL;

    // Crea un nuevo nodo con la cabecera ya hecha y lo agrega al árbol
    Nodo<std::string, Cabecera<Empleado>> *nodo = arbolCabecera->createNodo(empleado->*atributos.dato, cabEmpleado);
    arbolCabecera->Insert(arbolCabecera, nodo);
}

void MultilistaEmpleado::ManejarNodoExistente(RBTree<std::string, Cabecera<Empleado>> *arbolCabecera, Empleado *empleado, AtributosEmpleado<std::string> atributos)
{
    // Se asigna a cabEmpleado la cabecera ya existente
    Cabecera<Empleado> &cabEmpleado = arbolCabecera->findNodo(empleado->*atributos.dato)->Valor;
    // Si el último dato que guarda la cabecera es NULL significa que solo hay un empleado agregado
    if (cabEmpleado.ultimoDato == NULL)
    {
        // Se asigna el nuevo empleado como último dato
        cabEmpleado.ultimoDato = empleado;
        // El último dato apunta al primer dato (anterior)
        cabEmpleado.ultimoDato->*atributos.punteroAnt = cabEmpleado.primerDato;
        // El primer dato apunta al último dato (siguiente)
        cabEmpleado.primerDato->*atributos.punteroSig = cabEmpleado.ultimoDato;

        cabEmpleado.ultimoDato->*atributos.punteroSig = NULL;
    }
    else
    {
        // Ya hay más de dos datos en la cabecera.
        // El último dato apunta al nuevo empleado
        cabEmpleado.ultimoDato->*atributos.punteroSig = empleado;
        // El nuevo empleado apunta al último dato
        empleado->*atributos.punteroAnt = cabEmpleado.ultimoDato;
        // El nuevo empleado pasa a ser el último dato
        cabEmpleado.ultimoDato = empleado;
        // Se asigna el puntero siguiente del último dato como NULL
        cabEmpleado.ultimoDato->*atributos.punteroSig = NULL;
    }
}

RBTree<std::string, Cabecera<Empleado>> *MultilistaEmpleado::getCabeceraCiudadNacimiento() { return cabeceraCiudadNacimiento; }
RBTree<std::string, Cabecera<Empleado>> *MultilistaEmpleado::getCabeceraPaisNacimiento() { return cabeceraPaisNacimiento; }
RBTree<std::string, Cabecera<Empleado>> *MultilistaEmpleado::getCabeceraPaisResidencia() { return cabeceraPaisResidencia; }
RBTree<std::string, Cabecera<Empleado>> *MultilistaEmpleado::getCabeceraCiudadResidencia() { return cabeceraCiudadResidencia; }
RBTree<std::string, Cabecera<Empleado>> *MultilistaEmpleado::getCabeceraActividadLaboral() { return cabeceraActividadLaboral; }