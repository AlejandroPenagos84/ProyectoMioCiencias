/**
 * @file MultilistaEmpleado.hpp
 * @brief Archivo de encabezado que contiene la declaración de la clase MultilistaEmpleado y otras estructuras relacionadas.
 */

#ifndef MULTILISTA_EMPLEADO_HPP
#define MULTILISTA_EMPLEADO_HPP

#include "../../Librerias/ListaDoble.hpp"
#include "../../Librerias/Arbol.hpp"
#include "../../Estructuras/Empleado.hpp"
#include "../../Estructuras/Cabecera.hpp"
#include "../Multilista.hpp"

#include <string>
#include <iostream>

using namespace ListaDoble;
using namespace Arbol;

class MultilistaEmpleado : public Multilista<Empleado>
{
private:
    DoubleLinkedList<Empleado> empleados;

    // Árbol que guardará la dirección de los empleados para facilitar la búsqueda y organización.
    RBTree<std::string, Empleado *> *arbolEmpleados;

    // Árboles de Cabeceras
    RBTree<std::string, Cabecera<Empleado>> *cabeceraCiudadNacimiento;
    RBTree<std::string, Cabecera<Empleado>> *cabeceraPaisNacimiento;
    RBTree<std::string, Cabecera<Empleado>> *cabeceraCiudadResidencia;
    RBTree<std::string, Cabecera<Empleado>> *cabeceraPaisResidencia;
    RBTree<std::string, Cabecera<Empleado>> *cabeceraActividadLaboral;
    RBTree<int, Cabecera<Empleado>> *cabeceraEdad;
    RBTree<int, Cabecera<Empleado>> *cabeceraNumeroHijos;
    RBTree<bool, Cabecera<Empleado>> *cabeceraSexo;
    int size;

public:
    MultilistaEmpleado();

    void Agregar(Empleado &empleado);
    void Eliminar(std::string nombreEmpleado);
    void Modificar(std::string nombreEmpleado, Empleado *empleado);
    Empleado *getObjeto(std::string nombreEmpleado);

    // Getters
    RBTree<std::string, Cabecera<Empleado>> *getCabeceraCiudadNacimiento();
    RBTree<std::string, Cabecera<Empleado>> *getCabeceraPaisNacimiento();
    RBTree<std::string, Cabecera<Empleado>> *getCabeceraCiudadResidencia();
    RBTree<std::string, Cabecera<Empleado>> *getCabeceraPaisResidencia();
    RBTree<std::string, Cabecera<Empleado>> *getCabeceraActividadLaboral();
    RBTree<int, Cabecera<Empleado>> *getCabeceraEdad();
    RBTree<int, Cabecera<Empleado>> *getNumHijos();
    RBTree<bool, Cabecera<Empleado>> *getSexo();
    int getSize();

private:
    // Metodos para agregar un empleado
    void AgregarAArbol(Empleado &empleado);
    void OrganizarDatos(Empleado &empleado);

    // Metodo para eliminar un empleado}
    void EliminarDelArbol(std::string nombreCompleto);
    void ManejarCabeceras(Empleado *&empleadoAEliminar, std::string nombreEmpleado);

    GettersObjeto<std::string, Empleado> getterCiudadNacimiento();
    SettersObjeto<std::string, Empleado> setterCiudadNacimiento();
    GettersObjeto<std::string, Empleado> getterPaisNacimiento();
    SettersObjeto<std::string, Empleado> setterPaisNacimiento();
    GettersObjeto<std::string, Empleado> getterCiudadResidencia();
    SettersObjeto<std::string, Empleado> setterCiudadResidencia();
    GettersObjeto<std::string, Empleado> getterPaisResidencia();
    SettersObjeto<std::string, Empleado> setterPaisResidencia();
    GettersObjeto<std::string, Empleado> getterActividadLaboral();
    SettersObjeto<std::string, Empleado> setterActividadLaboral();
    GettersObjeto<int, Empleado> getterEdad();
    SettersObjeto<int, Empleado> setterEdad();
    GettersObjeto<int, Empleado> getterNumeroHijos();
    SettersObjeto<int, Empleado> setterNumeroHijos();
    GettersObjeto<bool, Empleado> getterSexo();
    SettersObjeto<bool, Empleado> setterSexo();
};

#endif
