#include "FabricaEmpleado.hpp"

Empleado FabricaEmpleado::crearObjeto(DoubleLinkedList<std::string> listaAtributos)
{
    Empleado nuevoEmpleado;

    if (listaAtributos.Size() >= 21)
    {
        nuevoEmpleado.setId(std::stoi(listaAtributos.getData(1)));
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
        nuevoEmpleado.setNumHijos(std::stoi(listaAtributos.getData(19)));
        nuevoEmpleado.setNombreSucursal(listaAtributos.getData(20));
        nuevoEmpleado.setEdad(std::stoi(listaAtributos.getData(21)));
    }
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

bool FabricaEmpleado::tieneHijosToBool(std::string tieneHijos)
{
    return tieneHijos == "s" ? true : false;
}

bool FabricaEmpleado::sexoToBool(std::string sexo)
{
    return sexo == "m" ? true : false;
}