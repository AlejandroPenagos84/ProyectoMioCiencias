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
    AgregarAArbol(empleado);
    OrganizarDatos(empleado);
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
    GettersEmpleado<std::string> getterEmpleadoCiudadNacimiento = ConfigurarGettersEmpleado(&Empleado::getCiudadNacimiento, &Empleado::getAntCiudadNacimiento, &Empleado::getSigCiudadNacimiento);
    SettersEmpleado<std::string> setterEmpleadoCiudadNacimiento = ConfigurarSettersEmpleado(&Empleado::setCiudadNacimiento, &Empleado::setAntCiudadNacimiento, &Empleado::setSigCiudadNacimiento);
    OrganizarGenerico(cabeceraCiudadNacimiento, &empleado, getterEmpleadoCiudadNacimiento, setterEmpleadoCiudadNacimiento);

    GettersEmpleado<std::string> getterEmpleadoPaisNacimiento = ConfigurarGettersEmpleado(&Empleado::getPaisNacimiento, &Empleado::getAntPaisNacimiento, &Empleado::getSigPaisNacimiento);
    SettersEmpleado<std::string> setterEmpleadoPaisNacimiento = ConfigurarSettersEmpleado(&Empleado::setPaisNacimiento, &Empleado::setAntPaisNacimiento, &Empleado::setSigPaisNacimiento);
    OrganizarGenerico(cabeceraPaisNacimiento, &empleado, getterEmpleadoPaisNacimiento, setterEmpleadoPaisNacimiento);

    GettersEmpleado<std::string> getterEmpleadoCiudadResidencia = ConfigurarGettersEmpleado(&Empleado::getCiudadResidencia, &Empleado::getAntCiudadResidencia, &Empleado::getSigCiudadResidencia);
    SettersEmpleado<std::string> setterEmpleadoCiudadResidencia = ConfigurarSettersEmpleado(&Empleado::setCiudadResidencia, &Empleado::setAntCiudadResidencia, &Empleado::setSigCiudadResidencia);
    OrganizarGenerico(cabeceraCiudadResidencia, &empleado, getterEmpleadoCiudadResidencia, setterEmpleadoCiudadResidencia);

    GettersEmpleado<std::string> getterEmpleadoPaisResidencia = ConfigurarGettersEmpleado(&Empleado::getPaisResidencia, &Empleado::getAntPaisResidencia, &Empleado::getSigPaisResidencia);
    SettersEmpleado<std::string> setterEmpleadoPaisResidencia = ConfigurarSettersEmpleado(&Empleado::setPaisResidencia, &Empleado::setAntPaisResidencia, &Empleado::setSigPaisResidencia);
    OrganizarGenerico(cabeceraPaisResidencia, &empleado, getterEmpleadoPaisResidencia, setterEmpleadoPaisResidencia);

    GettersEmpleado<std::string> getterEmpleadoActividadLaboral = ConfigurarGettersEmpleado(&Empleado::getActividadLaboral, &Empleado::getAntActividadLaboral, &Empleado::getSigActividadLaboral);
    SettersEmpleado<std::string> setterEmpleadoActividadLaboral = ConfigurarSettersEmpleado(&Empleado::setActividadLaboral, &Empleado::setAntActividadLaboral, &Empleado::setSigActividadLaboral);
    OrganizarGenerico(cabeceraActividadLaboral, &empleado, getterEmpleadoActividadLaboral, setterEmpleadoActividadLaboral);
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
    if (arbolCabecera->findNodo((empleado->*getters.obtenerDato)()) == arbolCabecera->getNullNode())
        ManejarNodoNoExistente(arbolCabecera, empleado, getters, setters);
    else
        ManejarNodoExistente(arbolCabecera, empleado, getters, setters);
}

void MultilistaEmpleado::ManejarNodoNoExistente(RBTree<std::string, Cabecera<Empleado>> *arbolCabecera, Empleado *empleado, GettersEmpleado<std::string> getters, SettersEmpleado<std::string> setters)
{
    Cabecera<Empleado> cabEmpleado;
    cabEmpleado.primerDato = empleado;
    cabEmpleado.ultimoDato = NULL;
    (cabEmpleado.primerDato->*setters.setPunteroAnt)(NULL);
    (cabEmpleado.primerDato->*setters.setPunteroSig)(NULL);

    Nodo<std::string, Cabecera<Empleado>> *nodo = arbolCabecera->createNodo((empleado->*getters.obtenerDato)(), cabEmpleado);
    arbolCabecera->Insert(arbolCabecera, nodo);
}

void MultilistaEmpleado::ManejarNodoExistente(RBTree<std::string, Cabecera<Empleado>> *arbolCabecera, Empleado *empleado, GettersEmpleado<std::string> getters, SettersEmpleado<std::string> setters)
{
    Cabecera<Empleado> &cabEmpleado = arbolCabecera->findNodo((empleado->*getters.obtenerDato)())->Valor;
    if (cabEmpleado.ultimoDato == NULL)
        ManejarNodosExistenteUnDato(cabEmpleado, empleado, getters, setters);
    else
        ManejarNodoExistenteVariosDatos(cabEmpleado, empleado, getters, setters);
}

void MultilistaEmpleado::ManejarNodosExistenteUnDato(Cabecera<Empleado> &cabEmpleado, Empleado *empleado, GettersEmpleado<std::string> getters, SettersEmpleado<std::string> setters)
{
    cabEmpleado.ultimoDato = empleado;
    (cabEmpleado.ultimoDato->*setters.setPunteroAnt)(cabEmpleado.primerDato);
    (cabEmpleado.primerDato->*setters.setPunteroSig)(cabEmpleado.ultimoDato);
    (cabEmpleado.ultimoDato->*setters.setPunteroSig)(NULL);
}
void MultilistaEmpleado::ManejarNodoExistenteVariosDatos(Cabecera<Empleado> &cabEmpleado, Empleado *empleado, GettersEmpleado<std::string> getters, SettersEmpleado<std::string> setters)
{
    // Leer el codigo como set(Dato)
    (cabEmpleado.ultimoDato->*setters.setPunteroSig)(empleado);
    (empleado->*setters.setPunteroAnt)(cabEmpleado.ultimoDato);
    cabEmpleado.ultimoDato = empleado;
    (cabEmpleado.ultimoDato->*setters.setPunteroSig)(NULL);
}

void MultilistaEmpleado::Eliminar(std::string nombreEmpleado)
{
    Empleado *&empleadoAEliminar = arbolEmpleados->findNodo(nombreEmpleado)->Valor;
    if (empleadoAEliminar != NULL)
    {

        GettersEmpleado<std::string> getterEmpleadoCiudadNacimiento = ConfigurarGettersEmpleado(&Empleado::getCiudadNacimiento, &Empleado::getAntCiudadNacimiento, &Empleado::getSigCiudadNacimiento);
        SettersEmpleado<std::string> setterEmpleadoCiudadNacimiento = ConfigurarSettersEmpleado(&Empleado::setCiudadNacimiento, &Empleado::setAntCiudadNacimiento, &Empleado::setSigCiudadNacimiento);
        ManejoDeCabecerasEliminar(cabeceraCiudadNacimiento, empleadoAEliminar, getterEmpleadoCiudadNacimiento, setterEmpleadoCiudadNacimiento);

        GettersEmpleado<std::string> getterEmpleadoPaisNacimiento = ConfigurarGettersEmpleado(&Empleado::getPaisNacimiento, &Empleado::getAntPaisNacimiento, &Empleado::getSigPaisNacimiento);
        SettersEmpleado<std::string> setterEmpleadoPaisNacimiento = ConfigurarSettersEmpleado(&Empleado::setPaisNacimiento, &Empleado::setAntPaisNacimiento, &Empleado::setSigPaisNacimiento);
        ManejoDeCabecerasEliminar(cabeceraPaisNacimiento, empleadoAEliminar, getterEmpleadoPaisNacimiento, setterEmpleadoPaisNacimiento);

        GettersEmpleado<std::string> getterEmpleadoCiudadResidencia = ConfigurarGettersEmpleado(&Empleado::getCiudadResidencia, &Empleado::getAntCiudadResidencia, &Empleado::getSigCiudadResidencia);
        SettersEmpleado<std::string> setterEmpleadoCiudadResidencia = ConfigurarSettersEmpleado(&Empleado::setCiudadResidencia, &Empleado::setAntCiudadResidencia, &Empleado::setSigCiudadResidencia);
        ManejoDeCabecerasEliminar(cabeceraCiudadResidencia, empleadoAEliminar, getterEmpleadoCiudadResidencia, setterEmpleadoCiudadResidencia);

        GettersEmpleado<std::string> getterEmpleadoPaisResidencia = ConfigurarGettersEmpleado(&Empleado::getPaisResidencia, &Empleado::getAntPaisResidencia, &Empleado::getSigPaisResidencia);
        SettersEmpleado<std::string> setterEmpleadoPaisResidencia = ConfigurarSettersEmpleado(&Empleado::setPaisResidencia, &Empleado::setAntPaisResidencia, &Empleado::setSigPaisResidencia);
        ManejoDeCabecerasEliminar(cabeceraPaisResidencia, empleadoAEliminar, getterEmpleadoPaisResidencia, setterEmpleadoPaisResidencia);

        GettersEmpleado<std::string> getterEmpleadoActividadLaboral = ConfigurarGettersEmpleado(&Empleado::getActividadLaboral, &Empleado::getAntActividadLaboral, &Empleado::getSigActividadLaboral);
        SettersEmpleado<std::string> setterEmpleadoActividadLaboral = ConfigurarSettersEmpleado(&Empleado::setActividadLaboral, &Empleado::setAntActividadLaboral, &Empleado::setSigActividadLaboral);
        ManejoDeCabecerasEliminar(cabeceraActividadLaboral, empleadoAEliminar, getterEmpleadoActividadLaboral, setterEmpleadoActividadLaboral);

        empleadoAEliminar->setSigEdad(NULL);
        empleadoAEliminar->setAntEdad(NULL);
        empleadoAEliminar->setSigSexo(NULL);
        empleadoAEliminar->setAntSexo(NULL);

        EliminarDelArbol(nombreEmpleado);

        empleadoAEliminar = NULL;

        delete empleadoAEliminar;
    }
}

void MultilistaEmpleado::EliminarDelArbol(std::string nombreCompleto)
{
    Nodo<std::string, Empleado *> *nodoAEliminar = arbolEmpleados->findNodo(nombreCompleto);
    arbolEmpleados->Delete(arbolEmpleados, nodoAEliminar);
}

void MultilistaEmpleado::ManejoDeCabecerasEliminar(RBTree<std::string, Cabecera<Empleado>> *arbolCabecera, Empleado *empleado, GettersEmpleado<std::string> getters, SettersEmpleado<std::string> setters)
{

    Nodo<std::string, Cabecera<Empleado>> *nodo = arbolCabecera->findNodo((empleado->*getters.obtenerDato)());
    Cabecera<Empleado> &cabEmpleado = nodo->Valor;

    if (cabEmpleado.primerDato == empleado)
    {

        Empleado *auxEmpleado = (cabEmpleado.primerDato->*getters.obtenerPunteroSig)();

        cabEmpleado.primerDato = auxEmpleado;

        if (cabEmpleado.primerDato != NULL)
            (cabEmpleado.primerDato->*setters.setPunteroAnt)(NULL);

        // std::cout << (cabEmpleado.primerDato->*getters.obtenerPunteroAnt)() << std::endl;
    }
    else if (cabEmpleado.ultimoDato == empleado)
    {
        Empleado *empleadoAEliminar = empleado;
        Empleado *empleadoAnt = (cabEmpleado.ultimoDato->*getters.obtenerPunteroAnt)();

        cabEmpleado.ultimoDato = empleadoAnt;
        (cabEmpleado.ultimoDato->*setters.setPunteroSig)(NULL);
    }
    else
    {
        Empleado *empleadoAEliminar = empleado;

        Empleado *empleadoAnt = (empleado->*getters.obtenerPunteroAnt)();
        Empleado *empleadoSig = (empleado->*getters.obtenerPunteroSig)();

        (empleadoAnt->*setters.setPunteroSig)(empleadoSig);
        (empleadoSig->*setters.setPunteroAnt)(empleadoAnt);
    }

    (empleado->*setters.setPunteroAnt)(NULL);
    (empleado->*setters.setPunteroSig)(NULL);
}

void MultilistaEmpleado::Modificar(Empleado &empleado) {}

RBTree<std::string, Cabecera<Empleado>> *MultilistaEmpleado::getCabeceraCiudadNacimiento() { return cabeceraCiudadNacimiento; }
RBTree<std::string, Cabecera<Empleado>> *MultilistaEmpleado::getCabeceraPaisNacimiento() { return cabeceraPaisNacimiento; }
RBTree<std::string, Cabecera<Empleado>> *MultilistaEmpleado::getCabeceraPaisResidencia() { return cabeceraPaisResidencia; }
RBTree<std::string, Cabecera<Empleado>> *MultilistaEmpleado::getCabeceraCiudadResidencia() { return cabeceraCiudadResidencia; }
RBTree<std::string, Cabecera<Empleado>> *MultilistaEmpleado::getCabeceraActividadLaboral() { return cabeceraActividadLaboral; }