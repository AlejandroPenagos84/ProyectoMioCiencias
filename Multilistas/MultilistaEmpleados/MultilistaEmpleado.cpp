#include "MultilitaEmpleado.hpp"

MultilistaEmpleado::MultilistaEmpleado()
{
    arbolEmpleados = new RBTree<std::string, Empleado *>;
    cabeceraCiudadNacimiento = new RBTree<std::string, Cabecera<Empleado>>;
    cabeceraPaisNacimiento = new RBTree<std::string, Cabecera<Empleado>>;
    cabeceraCiudadResidencia = new RBTree<std::string, Cabecera<Empleado>>;
    cabeceraPaisResidencia = new RBTree<std::string, Cabecera<Empleado>>;
    cabeceraActividadLaboral = new RBTree<std::string, Cabecera<Empleado>>;
    cabeceraEdad = new RBTree<int, Cabecera<Empleado>>;
    cabeceraNumeroHijos = new RBTree<int, Cabecera<Empleado>>;
    cabeceraSexo = new RBTree<bool, Cabecera<Empleado>>;

    size = 0;
}

void MultilistaEmpleado::Agregar(Empleado &empleado)
{
    OrganizarDatos(empleado);
    AgregarAArbol(empleado);
    empleados.AddLast(empleado);
    size++;
}

void MultilistaEmpleado::AgregarAArbol(Empleado &empleado)
{
    std::string nombreCompleto = empleado.getNombre() + " " + empleado.getApellido();
    arbolEmpleados->Insert(arbolEmpleados, arbolEmpleados->createNodo(nombreCompleto, &empleado));
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

    manejoPunteros->OrganizarPunterosAlAgregar(
        cabeceraEdad, &empleado,
        getterEdad(), setterEdad());

    manejoPunteros->OrganizarPunterosAlAgregar(
        cabeceraNumeroHijos, &empleado,
        getterNumeroHijos(), setterNumeroHijos());

    manejoPunteros->OrganizarPunterosAlAgregar(
        cabeceraSexo, &empleado,
        getterSexo(), setterSexo());
}

// Elimina un empleado
void MultilistaEmpleado::Eliminar(std::string nombreEmpleado)
{
    Empleado *&empleadoAEliminar = arbolEmpleados->findNodo(nombreEmpleado)->Valor;
    if (empleadoAEliminar != NULL)
    {
        ManejarCabeceras(empleadoAEliminar, nombreEmpleado);
        arbolEmpleados->Delete(arbolEmpleados, arbolEmpleados->findNodo(nombreEmpleado));
    }
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

    manejoPunteros->ManejoDeCabecerasEliminar(
        cabeceraEdad, empleadoAEliminar,
        getterEdad(), setterEdad());

    manejoPunteros->ManejoDeCabecerasEliminar(
        cabeceraNumeroHijos, empleadoAEliminar,
        getterNumeroHijos(), setterNumeroHijos());

    manejoPunteros->ManejoDeCabecerasEliminar(
        cabeceraSexo, empleadoAEliminar,
        getterSexo(), setterSexo());
}

void MultilistaEmpleado::EliminarDelArbol(std::string nombreCompleto)
{
    Nodo<std::string, Empleado *> *nodoAEliminar = arbolEmpleados->findNodo(nombreCompleto);
    arbolEmpleados->Delete(arbolEmpleados, nodoAEliminar);
    size--;
}

void MultilistaEmpleado::Modificar(std::string nombreEmpleado, Empleado *empleado)
{
    Empleado *&empleadoEnElArbol = arbolEmpleados->findNodo(nombreEmpleado)->Valor;

    // Modificar Atributos que tienen Punteros
    modificarAtributos->ModificarAtributoConPunteros(
        cabeceraCiudadNacimiento, empleadoEnElArbol,
        empleado, getterCiudadNacimiento(), setterCiudadNacimiento());

    modificarAtributos->ModificarAtributoConPunteros(
        cabeceraPaisNacimiento, empleadoEnElArbol,
        empleado, getterPaisNacimiento(), setterPaisNacimiento());

    modificarAtributos->ModificarAtributoConPunteros(
        cabeceraPaisResidencia, empleadoEnElArbol,
        empleado, getterPaisResidencia(), setterPaisResidencia());

    modificarAtributos->ModificarAtributoConPunteros(
        cabeceraCiudadResidencia, empleadoEnElArbol,
        empleado, getterCiudadResidencia(), setterCiudadResidencia());

    modificarAtributos->ModificarAtributoConPunteros(
        cabeceraActividadLaboral, empleadoEnElArbol,
        empleado, getterActividadLaboral(), setterActividadLaboral());

    modificarAtributos->ModificarAtributoConPunteros(
        cabeceraEdad, empleadoEnElArbol,
        empleado, getterEdad(), setterEdad());

    modificarAtributos->ModificarAtributoConPunteros(
        cabeceraNumeroHijos, empleadoEnElArbol,
        empleado, getterNumeroHijos(), setterNumeroHijos());

    modificarAtributos->ModificarAtributoConPunteros(
        cabeceraSexo, empleadoEnElArbol,
        empleado, getterSexo(), setterSexo());

    // Modificar Atributos que no tienen punteros
    modificarAtributos->ModificarAtributoSinPunteros(
        empleadoEnElArbol, empleado, &Empleado::getNombre, &Empleado::setNombre);

    modificarAtributos->ModificarAtributoSinPunteros(
        empleadoEnElArbol, empleado, &Empleado::getApellido, &Empleado::setApellido);

    modificarAtributos->ModificarAtributoSinPunteros(
        empleadoEnElArbol, empleado, &Empleado::getTipoIdentificacion, &Empleado::setTipoIdentificacion);

    modificarAtributos->ModificarAtributoSinPunteros(
        empleadoEnElArbol, empleado, &Empleado::getNumIdentificacion, &Empleado::setNumIdentificacion);

    modificarAtributos->ModificarAtributoSinPunteros(
        empleadoEnElArbol, empleado, &Empleado::getTelefonoCelular, &Empleado::setTelefonoCelular);

    modificarAtributos->ModificarAtributoSinPunteros(
        empleadoEnElArbol, empleado, &Empleado::getTelefonoFijo, &Empleado::setTelefonoFijo);

    modificarAtributos->ModificarAtributoSinPunteros(
        empleadoEnElArbol, empleado, &Empleado::getEmail, &Empleado::setEmail);

    modificarAtributos->ModificarAtributoSinPunteros(
        empleadoEnElArbol, empleado, &Empleado::getFechaNacimiento, &Empleado::setFechaNacimiento);

    modificarAtributos->ModificarAtributoSinPunteros(
        empleadoEnElArbol, empleado, &Empleado::getDireccion, &Empleado::setDireccion);

    modificarAtributos->ModificarAtributoSinPunteros(
        empleadoEnElArbol, empleado, &Empleado::getBarrio, &Empleado::setBarrio);

    modificarAtributos->ModificarAtributoSinPunteros(
        empleadoEnElArbol, empleado, &Empleado::getTieneHijos, &Empleado::setTieneHijos);
}

Empleado *MultilistaEmpleado::getObjeto(std::string nombreEmpleado)
{
    return arbolEmpleados->findNodo(nombreEmpleado)->Valor;
}

int MultilistaEmpleado::getSize() { return size; }

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

GettersObjeto<int, Empleado> MultilistaEmpleado::getterEdad()
{
    return manejoPunteros->CofigurarGetters(
        &Empleado::getEdad,
        &Empleado::getAntEdad,
        &Empleado::getSigEdad);
}

SettersObjeto<int, Empleado> MultilistaEmpleado::setterEdad()
{
    return manejoPunteros->ConfigurarSetters(
        &Empleado::setEdad,
        &Empleado::setAntEdad,
        &Empleado::setSigEdad);
}

GettersObjeto<int, Empleado> MultilistaEmpleado::getterNumeroHijos()
{
    return manejoPunteros->CofigurarGetters(
        &Empleado::getNumHijos,
        &Empleado::getAntNumHijos,
        &Empleado::getSigNumHijos);
}

SettersObjeto<int, Empleado> MultilistaEmpleado::setterNumeroHijos()
{
    return manejoPunteros->ConfigurarSetters(
        &Empleado::setNumHijos,
        &Empleado::setAntNumHijos,
        &Empleado::setSigNumHijos);
}

GettersObjeto<bool, Empleado> MultilistaEmpleado::getterSexo()
{
    return manejoPunteros->CofigurarGetters(
        &Empleado::getSexo,
        &Empleado::getAntSexo,
        &Empleado::getSigSexo);
}

SettersObjeto<bool, Empleado> MultilistaEmpleado::setterSexo()
{
    return manejoPunteros->ConfigurarSetters(
        &Empleado::setSexo,
        &Empleado::setAntSexo,
        &Empleado::setSigSexo);
}

RBTree<std::string, Cabecera<Empleado>> *MultilistaEmpleado::getCabeceraCiudadNacimiento() { return cabeceraCiudadNacimiento; }
RBTree<std::string, Cabecera<Empleado>> *MultilistaEmpleado::getCabeceraPaisNacimiento() { return cabeceraPaisNacimiento; }
RBTree<std::string, Cabecera<Empleado>> *MultilistaEmpleado::getCabeceraPaisResidencia() { return cabeceraPaisResidencia; }
RBTree<std::string, Cabecera<Empleado>> *MultilistaEmpleado::getCabeceraCiudadResidencia() { return cabeceraCiudadResidencia; }
RBTree<std::string, Cabecera<Empleado>> *MultilistaEmpleado::getCabeceraActividadLaboral() { return cabeceraActividadLaboral; }
RBTree<int, Cabecera<Empleado>> *MultilistaEmpleado::getCabeceraEdad() { return cabeceraEdad; }
RBTree<int, Cabecera<Empleado>> *MultilistaEmpleado::getNumHijos() { return cabeceraNumeroHijos; }
RBTree<bool, Cabecera<Empleado>> *MultilistaEmpleado::getSexo() { return cabeceraSexo; }