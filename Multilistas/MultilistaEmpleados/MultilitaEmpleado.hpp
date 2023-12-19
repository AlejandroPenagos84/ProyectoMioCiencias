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

    // Se guardan en arreglos normales las cabeceras de rangos
    Cabecera<Empleado> *edad;
    Cabecera<Empleado> *numHijos;
    Cabecera<Empleado> *sexo;

public:
    MultilistaEmpleado();

    void Agregar(Empleado &empleado) override;
    void Eliminar(std::string nombreEmpleado) override;
    void Modificar(std::string nombreEmpleado, Empleado empleado) override;

    // Getters
    RBTree<std::string, Cabecera<Empleado>> *getCabeceraCiudadNacimiento();
    RBTree<std::string, Cabecera<Empleado>> *getCabeceraPaisNacimiento();
    RBTree<std::string, Cabecera<Empleado>> *getCabeceraCiudadResidencia();
    RBTree<std::string, Cabecera<Empleado>> *getCabeceraPaisResidencia();
    RBTree<std::string, Cabecera<Empleado>> *getCabeceraActividadLaboral();

private:
    // Metodos para agregar un empleado
    void AgregarAArbol(Empleado &empleado);
    void OrganizarDatos(Empleado &empleado);

    // Metodo para eliminar un empleado}
    void EliminarDelArbol(std::string nombreCompleto);
    void ManejarCabeceras(Empleado *&empleadoAEliminar, std::string nombreEmpleado);
};

#endif
