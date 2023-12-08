#include "MultilitaEmpleado.hpp"

MultilistaEmpleado::MultilistaEmpleado()
{
    // Inicialización de todos los arboles
    arbolEmpleados = new RBTree<std::string, Empleado>;
    cabeceraCiudadNacimiento = new RBTree<std::string, Cabecera<Empleado>>;
    cabeceraPaisNacimiento = new RBTree<std::string, Cabecera<Empleado>>;
    cabeceraCiudadResidencia = new RBTree<std::string, Cabecera<Empleado>>;
    cabeceraPaisResidencia = new RBTree<std::string, Cabecera<Empleado>>;
    cabeceraActividadLaboral = new RBTree<std::string, Cabecera<Empleado>>;
}

void MultilistaEmpleado::AgregarEmpleado(Empleado &empleado)
{
    std::string nombreCompleto = empleado.nombre + " " + empleado.apellido;                   ///< Creo un String con el nombre completo del empleado
    Nodo<std::string, Empleado> *nodo = arbolEmpleados->createNodo(nombreCompleto, empleado); ///< Creo un nodo para agregar en el arbol
    arbolEmpleados->Insert(arbolEmpleados, nodo);                                             ///< Agrego el nodo al arbol que tiene las direcciones de los empleados

    // Organizar según Ciudad De Nacmiento
    AtributosEmpleado<std::string> atrCiudadNacimiento;
    atrCiudadNacimiento.dato = &Empleado::ciudadNacimiento;
    atrCiudadNacimiento.punteroAnt = &Empleado::antCiudadNacimiento;
    atrCiudadNacimiento.punteroSig = &Empleado::sigCiudadNacimiento;
    OrganizarGenerico(cabeceraCiudadNacimiento, &empleado, atrCiudadNacimiento);

    empleados.AddLast(empleado); ///< Agrego un empleado a la lista, de hecho siento que esta innecesario esto,pero dejemoslo mientras xd
}

void MultilistaEmpleado::OrganizarGenerico(RBTree<std::string, Cabecera<Empleado>> *arbolCabecera, Empleado *empleado, AtributosEmpleado<std::string> atributos)
{
    Cabecera<Empleado> cabEmpleado; ///< Objeto tipo cabecera que guarda la dirección del primer y último dato

    //* Si no existe un nodo con el dato especificado, eso significa que el dato no existe, por ello se agrega un nodo a un árbol
    if (arbolCabecera->findNodo(empleado->*atributos.dato) == NULL)
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

    //* Establece el enlace desde el primer dato al último dato, incluso si es NULL.
    cabEmpleado.primerDato->*atributos.punteroSig = cabEmpleado.ultimoDato;

    // Crea un nuevo nodo con la cabecera ya hecha y lo agrega al árbol
    Nodo<std::string, Cabecera<Empleado>> *nodo = arbolCabecera->createNodo(empleado->*atributos.dato, cabEmpleado);
    arbolCabecera->Insert(arbolCabecera, nodo);
}

void MultilistaEmpleado::ManejarNodoExistente(RBTree<std::string, Cabecera<Empleado>> *arbolCabecera, Empleado *empleado, AtributosEmpleado<std::string> atributos)
{
    // Se asigna a cabEmpleado la cabecera ya existente
    Cabecera<Empleado> cabEmpleado = arbolCabecera->findNodo(empleado->*atributos.dato)->Valor;

    // * Si el último dato que guarda la cabecera es NULL significa que solo hay un empleado agregado
    if (cabEmpleado.ultimoDato == NULL)
    {
        // Se asigna el nuevo empleado como último dato
        cabEmpleado.ultimoDato = empleado;
        // El último dato apunta al primer dato (anterior)
        cabEmpleado.ultimoDato->*atributos.punteroAnt = cabEmpleado.primerDato;
        // El primer dato apunta al último dato (siguiente)
        cabEmpleado.primerDato->*atributos.punteroSig = cabEmpleado.ultimoDato;
    }
    else
    {
        //* Ya hay más de dos datos en la cabecera.
        // El último dato apunta al nuevo empleado
        cabEmpleado.ultimoDato->*atributos.punteroSig = empleado;
        // El nuevo empleado apunta al último dato
        empleado->*atributos.punteroAnt = cabEmpleado.ultimoDato;
        // El nuevo empleado pasa a ser el último dato
        cabEmpleado.ultimoDato = empleado;
    }
}