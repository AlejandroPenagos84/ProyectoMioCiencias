#ifndef MULTILISTA_HIJO_HPP
#define MULTILISTA_HIJO_HPP

#include "../../Librerias/Arbol.hpp"
#include "../../Librerias/ListaDoble.hpp"
#include "../../Estructuras/Hijo.hpp"
#include "../../Estructuras/Cabecera.hpp"
#include "../Multilista.hpp"

using namespace Arbol;

class MultilistaHijo : public Multilista<Hijo>
{
private:
    // Arbol que guarda los hijos
    RBTree<std::string, Hijo *> *arbolHijos;

    // Arbol Cabeceras
    RBTree<int, Cabecera<Hijo>> *cabeceraEdad;

    int size;

public:
    MultilistaHijo();

    void Agregar(Hijo *hijo);
    void Eliminar(std::string nombreHijo);
    void Modificar(std::string nombreHijo, Hijo *hijo);
    Hijo *getObjeto(std::string nombreHijo);
    int getSize();

private:
    // Metodos para agregar un hijo
    void AgregarAArbol(Hijo *hijo);
    void OrganizarDatos(Hijo *hijo);

    // Metodo para eliminar un hijo
    void EliminarDelArbol(std::string nombreHijo);
    void ManejarCabeceras(Hijo *&hijoAEliminar, std::string nombreHijo);

    GettersObjeto<int, Hijo> getterEdad();
    SettersObjeto<int, Hijo> setterEdad();

    RBTree<int, Cabecera<Hijo>> *getCabeceraEdad();
};
#endif