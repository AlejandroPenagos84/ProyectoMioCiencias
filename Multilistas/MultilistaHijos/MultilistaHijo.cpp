#include "MultilistaHijo.hpp"

MultilistaHijo::MultilistaHijo()
{
    arbolHijos = new RBTree<std::string, Hijo *>;
    cabeceraEdad = new RBTree<int, Cabecera<Hijo>>;
    size = 0;
}

void MultilistaHijo::Agregar(Hijo *hijo)
{
    OrganizarDatos(hijo);
    AgregarAArbol(hijo);
    size++;
}

void MultilistaHijo::OrganizarDatos(Hijo *hijo)
{
    manejoPunteros->OrganizarPunterosAlAgregar(cabeceraEdad, hijo, getterEdad(), setterEdad());
}

void MultilistaHijo::AgregarAArbol(Hijo *hijo)
{
    std::string nombre = hijo->getNombre();
    arbolHijos->Insert(arbolHijos, arbolHijos->createNodo(nombre, hijo));
}

void MultilistaHijo::Eliminar(std::string nombreHijo)
{
    Hijo *&hijoAEliminar = arbolHijos->findNodo(nombreHijo)->Valor;

    if (hijoAEliminar != NULL)
    {
        ManejarCabeceras(hijoAEliminar, nombreHijo);
        EliminarDelArbol(nombreHijo);
        size--;
    }
    hijoAEliminar = NULL;
}

void MultilistaHijo::ManejarCabeceras(Hijo *&hijoAEliminar, std::string nombreHijo)
{
    manejoPunteros->ManejoDeCabecerasEliminar(cabeceraEdad, hijoAEliminar, getterEdad(), setterEdad());
}

void MultilistaHijo::EliminarDelArbol(std::string nombreHijo)
{
    Nodo<std::string, Hijo *> *nodoAEliminar = arbolHijos->findNodo(nombreHijo);
    arbolHijos->Delete(arbolHijos, nodoAEliminar);
    size--;
}

void MultilistaHijo::Modificar(std::string nombreHijo, Hijo *hijo)
{
    Eliminar(nombreHijo);
    Agregar(hijo);
}

Hijo *MultilistaHijo::getObjeto(std::string nombreHijo) { return arbolHijos->findNodo(nombreHijo)->Valor; }

int MultilistaHijo::getSize() { return size; }

GettersObjeto<int, Hijo>
MultilistaHijo::getterEdad()
{
    return manejoPunteros->CofigurarGetters(
        &Hijo::getEdad,
        &Hijo::getAntEdad,
        &Hijo::getSigEdad);
}

SettersObjeto<int, Hijo> MultilistaHijo::setterEdad()
{
    return manejoPunteros->ConfigurarSetters(
        &Hijo::setEdad,
        &Hijo::setAntEdad,
        &Hijo::setSigEdad);
}

RBTree<int, Cabecera<Hijo>> *MultilistaHijo::getCabeceraEdad() { return cabeceraEdad; }