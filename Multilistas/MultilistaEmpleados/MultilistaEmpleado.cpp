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
    GettersObjeto<std::string, Empleado> getterEmpleadoCiudadNacimiento =
        manejoPunteros.CofigurarGetters(&Empleado::getCiudadNacimiento,
                                        &Empleado::getAntCiudadNacimiento,
                                        &Empleado::getSigCiudadNacimiento);

    SettersObjeto<std::string, Empleado> setterEmpleadoCiudadNacimiento =
        manejoPunteros.ConfigurarSetters(
            &Empleado::setCiudadNacimiento,
            &Empleado::setAntCiudadNacimiento,
            &Empleado::setSigCiudadNacimiento);

    manejoPunteros.OrganizarPunterosAlAgregar(
        cabeceraCiudadNacimiento,
        &empleado, getterEmpleadoCiudadNacimiento,
        setterEmpleadoCiudadNacimiento);
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
    manejoPunteros.ManejoDeCabecerasEliminar(
        cabeceraCiudadNacimiento, empleadoAEliminar,
        getterCiudadNacimiento(), setterCiudadNacimiento());
}

// Metodo que elimina de un arbol
void MultilistaEmpleado::EliminarDelArbol(std::string nombreCompleto)
{
    Nodo<std::string, Empleado *> *nodoAEliminar = arbolEmpleados->findNodo(nombreCompleto);
    arbolEmpleados->Delete(arbolEmpleados, nodoAEliminar);
}

void MultilistaEmpleado::Modificar(std::string nombreEmpleado, Empleado empleado) {}

GettersObjeto<std::string, Empleado> MultilistaEmpleado::getterCiudadNacimiento()
{
    return manejoPunteros.CofigurarGetters(
        &Empleado::getCiudadNacimiento,
        &Empleado::getAntCiudadNacimiento,
        &Empleado::getSigCiudadNacimiento);
}

SettersObjeto<std::string, Empleado> MultilistaEmpleado::setterCiudadNacimiento()
{
    return manejoPunteros.ConfigurarSetters(
        &Empleado::setCiudadNacimiento,
        &Empleado::setAntCiudadNacimiento,
        &Empleado::setSigCiudadNacimiento);
}

GettersObjeto<std::string, Empleado> MultilistaEmpleado::getterPaisNacimiento()
{
    return manejoPunteros.CofigurarGetters(
        &Empleado::getPaisNacimiento,
        &Empleado::getAntPaisNacimiento,
        &Empleado::getSigPaisNacimiento);
}

SettersObjeto<std::string, Empleado> MultilistaEmpleado::setterPaisNacimiento()
{
    return manejoPunteros.ConfigurarSetters(
        &Empleado::setPaisNacimiento,
        &Empleado::setAntPaisNacimiento,
        &Empleado::setSigPaisNacimiento);
}

GettersObjeto<std::string, Empleado> MultilistaEmpleado::getterCiudadResidencia() {}
SettersObjeto<std::string, Empleado> MultilistaEmpleado::setterCiudadResidencia() {}
GettersObjeto<std::string, Empleado> MultilistaEmpleado::getterPaisResidencia() {}
SettersObjeto<std::string, Empleado> MultilistaEmpleado::setterPaisResidencia() {}
GettersObjeto<std::string, Empleado> MultilistaEmpleado::getterActividadLaboral() {}
SettersObjeto<std::string, Empleado> MultilistaEmpleado::setterActividadLaboral() {}

RBTree<std::string, Cabecera<Empleado>> *MultilistaEmpleado::getCabeceraCiudadNacimiento() { return cabeceraCiudadNacimiento; }
RBTree<std::string, Cabecera<Empleado>> *MultilistaEmpleado::getCabeceraPaisNacimiento() { return cabeceraPaisNacimiento; }
RBTree<std::string, Cabecera<Empleado>> *MultilistaEmpleado::getCabeceraPaisResidencia() { return cabeceraPaisResidencia; }
RBTree<std::string, Cabecera<Empleado>> *MultilistaEmpleado::getCabeceraCiudadResidencia() { return cabeceraCiudadResidencia; }
RBTree<std::string, Cabecera<Empleado>> *MultilistaEmpleado::getCabeceraActividadLaboral() { return cabeceraActividadLaboral; }
