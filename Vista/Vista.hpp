#ifndef VISTA_HPP
#define VISTA_HPP

#include "../Librerias/ListaDoble.hpp"
#include "GestorDatosVista/GestorDatosVista.hpp"
#include "GestorDatosVista/GestorDatosVistaEmpleado.hpp"

#define PRINT(x) std::cout << x
#define PRINTLN(x) std::cout << x << "\n"
#define INPUT(X) std::cin >> x;

using namespace ListaDoble;

class Vista
{
private:
    GestorDatosVista *gestorDatosEmpleado;

public:
    Vista();

    // Menus Para facilitar el uso del programa
    int MenuGlobal();
    int MenuObjetos();
    int MenuAccion();
    void Titulo();

    int MostrarMenuModificar(DoubleLinkedList<std::string> atributos);
    std::string IngresarNuevoDato(std::string atributo, std::string antDato);
    std::string SolicitarInfo(std::string atributo, std::string accion);
    void Imprimir(std::string m);

    DoubleLinkedList<std::string> SolicitarDatosEmpleado();

private:
};

#endif