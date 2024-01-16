#include "FabricaEmpleado.hpp"

Empleado FabricaEmpleado::crearObjeto(DoubleLinkedList<std::string> listaAtributos)
{
    Empleado nuevoEmpleado;

    if (listaAtributos.Size() >= 21)
    {
        nuevoEmpleado.setId(atoi(listaAtributos.getData(1).c_str()));
        nuevoEmpleado.setNombre(listaAtributos.getData(2));
        nuevoEmpleado.setApellido(listaAtributos.getData(3));
        nuevoEmpleado.setTipoIdentificacion(listaAtributos.getData(4));
        nuevoEmpleado.setNumIdentificacion(listaAtributos.getData(5));
        nuevoEmpleado.setSexo(sexoToBool(listaAtributos.getData(6)));
        nuevoEmpleado.setTelefonoCelular(listaAtributos.getData(7));
        nuevoEmpleado.setTelefonoFijo(listaAtributos.getData(8));
        nuevoEmpleado.setEmail(listaAtributos.getData(9));
        nuevoEmpleado.setFechaNacimiento(listaAtributos.getData(10));
        nuevoEmpleado.setCiudadNacimiento(listaAtributos.getData(11));
        nuevoEmpleado.setPaisNacimiento(listaAtributos.getData(12));
        nuevoEmpleado.setPaisResidencia(listaAtributos.getData(13));
        nuevoEmpleado.setCiudadResidencia(listaAtributos.getData(14));
        nuevoEmpleado.setDireccion(listaAtributos.getData(15));
        nuevoEmpleado.setBarrio(listaAtributos.getData(16));
        nuevoEmpleado.setActividadLaboral(listaAtributos.getData(17));
        nuevoEmpleado.setTieneHijos(tieneHijosToBool(listaAtributos.getData(18)));
        nuevoEmpleado.setNumHijos(atoi(listaAtributos.getData(19).c_str()));
        nuevoEmpleado.setNombreSucursal(listaAtributos.getData(20));
        nuevoEmpleado.setEdad(atoi(listaAtributos.getData(21).c_str()));
    }
    return nuevoEmpleado;
}

RBTree<std::string, Empleado> *FabricaEmpleado::crearArbol(DoubleLinkedList<DoubleLinkedList<std::string>> listaEmpleados)
{
    RBTree<std::string, Empleado> *arbolEmpleados = new RBTree<std::string, Empleado>;
    for (int empleados = 1; empleados <= listaEmpleados.Size(); empleados++)
    {
        Empleado nuevoEmpleado = crearObjeto(listaEmpleados.getData(empleados));
        std::string nombreCompletoEmpleado = nuevoEmpleado.getNombre() + " " + nuevoEmpleado.getApellido();
        Nodo<std::string, Empleado> *nodoEmpleado = arbolEmpleados->createNodo(nombreCompletoEmpleado, nuevoEmpleado);
        arbolEmpleados->Insert(arbolEmpleados, nodoEmpleado);
    }
    return arbolEmpleados;
}

DoubleLinkedList<std::string> FabricaEmpleado::crearListaDeAtributos(Empleado *empleado)
{
    DoubleLinkedList<std::string> listaEmpleado;
    listaEmpleado.AddLast(convertirAString(empleado->getId()));
    listaEmpleado.AddLast(empleado->getNombre());
    listaEmpleado.AddLast(empleado->getApellido());
    listaEmpleado.AddLast(empleado->getTipoIdentificacion());
    listaEmpleado.AddLast(empleado->getNumIdentificacion());
    listaEmpleado.AddLast(sexoToString(empleado->getSexo()));
    listaEmpleado.AddLast(empleado->getTelefonoCelular());
    listaEmpleado.AddLast(empleado->getTelefonoFijo());
    listaEmpleado.AddLast(empleado->getEmail());
    listaEmpleado.AddLast(empleado->getFechaNacimiento());
    listaEmpleado.AddLast(empleado->getCiudadNacimiento());
    listaEmpleado.AddLast(empleado->getPaisNacimiento());
    listaEmpleado.AddLast(empleado->getPaisResidencia());
    listaEmpleado.AddLast(empleado->getCiudadResidencia());
    listaEmpleado.AddLast(empleado->getDireccion());
    listaEmpleado.AddLast(empleado->getBarrio());
    listaEmpleado.AddLast(empleado->getActividadLaboral());
    listaEmpleado.AddLast(tieneHijosToString(empleado->getTieneHijos()));
    listaEmpleado.AddLast(convertirAString(empleado->getNumHijos()));
    listaEmpleado.AddLast(empleado->getNombreSucursal());
    listaEmpleado.AddLast(convertirAString(empleado->getEdad()));

    return listaEmpleado;
}

bool FabricaEmpleado::tieneHijosToBool(std::string tieneHijos)
{
    return tieneHijos == "s" ? true : false;
}

bool FabricaEmpleado::sexoToBool(std::string sexo)
{
    return sexo == "m" ? true : false;
}

std::string FabricaEmpleado::tieneHijosToString(bool tieneHijos)
{
    return tieneHijos ? "s" : "n";
}

std::string FabricaEmpleado::sexoToString(bool sexo)
{
    return sexo ? "m" : "f";
}

template <class T>
std::string FabricaEmpleado::convertirAString(const T &valor)
{
    std::ostringstream stream;
    stream << valor;
    return stream.str();
}
