#include "MultilitaEmpleado.hpp"

MultilistaEmpleado::MultilistaEmpleado()
{
    arbolEmpleados = new RBTree<std::string, Empleado *>;
    cabeceraCiudadNacimiento = new RBTree<std::string, Cabecera<Empleado>>;
    cabeceraPaisNacimiento = new RBTree<std::string, Cabecera<Empleado>>;
    cabeceraCiudadResidencia = new RBTree<std::string, Cabecera<Empleado>>;
    cabeceraPaisResidencia = new RBTree<std::string, Cabecera<Empleado>>;
    cabeceraActividadLaboral = new RBTree<std::string, Cabecera<Empleado>>;
}

void MultilistaEmpleado::Agregar(Empleado &empleado)
{
    OrganizarDatos(empleado);
    AgregarAArbol(empleado);
    empleados.AddLast(empleado);
}

void MultilistaEmpleado::AgregarAArbol(Empleado &empleado)
{
    std::string nombreCompleto = empleado.getNombre() + " " + empleado.getApellido();
    Nodo<std::string, Empleado *> *nodo = arbolEmpleados->createNodo(nombreCompleto, &empleado);
    arbolEmpleados->Insert(arbolEmpleados, nodo);
}

void MultilistaEmpleado::OrganizarDatos(Empleado &empleado)
{
    manejoPunteros->OrganizarPunterosAlAgregar(
        cabeceraCiudadNacimiento, &empleado,
        getterCiudadNacimiento(), setterCiudadNacimiento());

    manejoPunteros->OrganizarPunterosAlAgregar(
        cabeceraPaisNacimiento, &empleado,
        getterPaisNacimiento(), setterPaisNacimiento());

    manejoPunteros->OrganizarPunterosAlAgregar(
        cabeceraPaisResidencia, &empleado,
        getterPaisResidencia(), setterPaisResidencia());

    manejoPunteros->OrganizarPunterosAlAgregar(
        cabeceraCiudadResidencia, &empleado,
        getterCiudadResidencia(), setterCiudadResidencia());

    manejoPunteros->OrganizarPunterosAlAgregar(
        cabeceraActividadLaboral, &empleado,
        getterActividadLaboral(), setterActividadLaboral());
}

// Elimina un empleado
void MultilistaEmpleado::Eliminar(std::string nombreEmpleado)
{
    Empleado *&empleadoAEliminar = arbolEmpleados->findNodo(nombreEmpleado)->Valor;
    if (empleadoAEliminar != NULL)
        ManejarCabeceras(empleadoAEliminar, nombreEmpleado);
}

// Metodo que reune todo las cabecera y atributos con punteros para poder eiminar un empleado
void MultilistaEmpleado::ManejarCabeceras(Empleado *&empleadoAEliminar, std::string nombreEmpleado)
{
    manejoPunteros->ManejoDeCabecerasEliminar(
        cabeceraCiudadNacimiento, empleadoAEliminar,
        getterCiudadNacimiento(), setterCiudadNacimiento());

    manejoPunteros->ManejoDeCabecerasEliminar(
        cabeceraPaisNacimiento, empleadoAEliminar,
        getterPaisNacimiento(), setterPaisNacimiento());

    manejoPunteros->ManejoDeCabecerasEliminar(
        cabeceraPaisResidencia, empleadoAEliminar,
        getterPaisResidencia(), setterPaisResidencia());

    manejoPunteros->ManejoDeCabecerasEliminar(
        cabeceraCiudadResidencia, empleadoAEliminar,
        getterCiudadResidencia(), setterCiudadResidencia());

    manejoPunteros->ManejoDeCabecerasEliminar(
        cabeceraActividadLaboral, empleadoAEliminar,
        getterActividadLaboral(), setterActividadLaboral());
}

void MultilistaEmpleado::EliminarDelArbol(std::string nombreCompleto)
{
    Nodo<std::string, Empleado *> *nodoAEliminar = arbolEmpleados->findNodo(nombreCompleto);
    arbolEmpleados->Delete(arbolEmpleados, nodoAEliminar);
}

void MultilistaEmpleado::Modificar(std::string nombreEmpleado, Empleado *empleado)
{
    Empleado *&empleadoEnElArbol = arbolEmpleados->findNodo(nombreEmpleado)->Valor;

    modificarAtributos->ModificarAtributoConPunteros(
        cabeceraCiudadNacimiento, empleadoEnElArbol,
        empleado, getterCiudadNacimiento(), setterCiudadNacimiento());
}

GettersObjeto<std::string, Empleado> MultilistaEmpleado::getterCiudadNacimiento()
{
    return manejoPunteros->CofigurarGetters(
        &Empleado::getCiudadNacimiento,
        &Empleado::getAntCiudadNacimiento,
        &Empleado::getSigCiudadNacimiento);
}

SettersObjeto<std::string, Empleado> MultilistaEmpleado::setterCiudadNacimiento()
{
    return manejoPunteros->ConfigurarSetters(
        &Empleado::setCiudadNacimiento,
        &Empleado::setAntCiudadNacimiento,
        &Empleado::setSigCiudadNacimiento);
}

GettersObjeto<std::string, Empleado> MultilistaEmpleado::getterPaisNacimiento()
{
    return manejoPunteros->CofigurarGetters(
        &Empleado::getPaisNacimiento,
        &Empleado::getAntPaisNacimiento,
        &Empleado::getSigPaisNacimiento);
}

SettersObjeto<std::string, Empleado> MultilistaEmpleado::setterPaisNacimiento()
{
    return manejoPunteros->ConfigurarSetters(
        &Empleado::setPaisNacimiento,
        &Empleado::setAntPaisNacimiento,
        &Empleado::setSigPaisNacimiento);
}

GettersObjeto<std::string, Empleado> MultilistaEmpleado::getterCiudadResidencia()
{
    return manejoPunteros->CofigurarGetters(
        &Empleado::getCiudadResidencia,
        &Empleado::getAntCiudadResidencia,
        &Empleado::getSigCiudadResidencia);
}

SettersObjeto<std::string, Empleado> MultilistaEmpleado::setterCiudadResidencia()
{
    return manejoPunteros->ConfigurarSetters(
        &Empleado::setCiudadResidencia,
        &Empleado::setAntCiudadResidencia,
        &Empleado::setSigCiudadResidencia);
}

GettersObjeto<std::string, Empleado> MultilistaEmpleado::getterPaisResidencia()
{
    return manejoPunteros->CofigurarGetters(
        &Empleado::getPaisResidencia,
        &Empleado::getAntPaisResidencia,
        &Empleado::getSigPaisResidencia);
}

SettersObjeto<std::string, Empleado> MultilistaEmpleado::setterPaisResidencia()
{
    return manejoPunteros->ConfigurarSetters(
        &Empleado::setPaisResidencia,
        &Empleado::setAntPaisResidencia,
        &Empleado::setSigPaisResidencia);
}

GettersObjeto<std::string, Empleado> MultilistaEmpleado::getterActividadLaboral()
{
    return manejoPunteros->CofigurarGetters(
        &Empleado::getActividadLaboral,
        &Empleado::getAntActividadLaboral,
        &Empleado::getSigActividadLaboral);
}

SettersObjeto<std::string, Empleado> MultilistaEmpleado::setterActividadLaboral()
{
    return manejoPunteros->ConfigurarSetters(
        &Empleado::setActividadLaboral,
        &Empleado::setAntActividadLaboral,
        &Empleado::setSigActividadLaboral);
}

RBTree<std::string, Cabecera<Empleado>> *MultilistaEmpleado::getCabeceraCiudadNacimiento() { return cabeceraCiudadNacimiento; }
RBTree<std::string, Cabecera<Empleado>> *MultilistaEmpleado::getCabeceraPaisNacimiento() { return cabeceraPaisNacimiento; }
RBTree<std::string, Cabecera<Empleado>> *MultilistaEmpleado::getCabeceraPaisResidencia() { return cabeceraPaisResidencia; }
RBTree<std::string, Cabecera<Empleado>> *MultilistaEmpleado::getCabeceraCiudadResidencia() { return cabeceraCiudadResidencia; }
RBTree<std::string, Cabecera<Empleado>> *MultilistaEmpleado::getCabeceraActividadLaboral() { return cabeceraActividadLaboral; }
