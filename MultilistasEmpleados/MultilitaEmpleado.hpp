/**
 * @file MultilistaEmpleado.hpp
 * @brief Archivo de encabezado que contiene la declaración de la clase MultilistaEmpleado y otras estructuras relacionadas.
 */

#ifndef MULTILISTA_EMPLEADO_HPP
#define MULTILISTA_EMPLEADO_HPP

#include "../Librerias/ListaDoble.h"
#include "../Estructuras/Empleado.hpp"
#include "../Librerias/Arbol.h"
#include "../Estructuras/Cabecera.hpp"

#include <string>
#include <iostream>

// Se utiliza el espacio de nombres para evitar conflictos con nodos de diferentes bibliotecas.
using namespace ListaDoble;
using namespace Arbol;

/**
 * @class AtributosEmpleado
 * @brief Estructura que define los atributos utilizados para organizar a los empleados en la multilista.
 *
 * Esta estructura define los atributos necesarios para organizar a los empleados en la multilista.
 * @tparam T Tipo de dato del miembro que se utilizará como clave para la organización.
 */
template <class T>
struct AtributosEmpleado
{
    T Empleado::*dato;               ///< Puntero a miembro que representa el dato a utilizar para la organización.
    Empleado *Empleado::*punteroAnt; ///< Puntero a miembro que representa el enlace anterior en la organización.
    Empleado *Empleado::*punteroSig; ///< Puntero a miembro que representa el enlace siguiente en la organización.
};

/**
 * @class MultilistaEmpleado
 * @brief Clase que representa una multilista de empleados.
 *
 * La clase MultilistaEmpleado gestiona una multilista de empleados, utilizando una lista doble, un árbol y varias
 * estructuras de cabeceras para facilitar la organización de los datos.
 */
class MultilistaEmpleado
{
private:
    // Lista que guardará los empleados
    DoubleLinkedList<Empleado> empleados;

    // Árbol que guardará la dirección de los empleados para facilitar la búsqueda y organización.
    RBTree<std::string, Empleado *> *arbolEmpleados = new RBTree<std::string, Empleado *>();

    // Árboles de Cabeceras
    // Los árboles almacenan datos de estructuras genéricas.

    // Estructura de los árboles:
    // - Clave: string (nombre)
    // - Valor: Cabecera que guarda la dirección del primer y último dato según corresponda (ciudad de nacimiento, país, etc.).

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
    /**
     * Constructor de la clase
     *
     */
    MultilistaEmpleado();

    /**
     * @brief Agrega un nuevo empleado a la multilista.
     *
     * @param empleado El empleado que se va a agregar.
     */
    void AgregarEmpleado(Empleado empleado);

    /**
     * @brief Organiza un empleado en la multilista según los atributos especificados.
     *
     * Esta función organiza un empleado en la multilista utilizando la información
     * proporcionada en la estructura AtributosEmpleado.
     *
     * @param arbolCabecera Árbol que contiene las cabeceras de la multilista.
     * @param empleado Puntero al empleado que se organizará en la multilista.
     * @param atributos Estructura que define los atributos utilizados para la organización.
     */
    void OrganizarGenerico(RBTree<std::string, Cabecera<Empleado>> *arbolCabecera, Empleado *empleado, AtributosEmpleado<std::string> atributos);
    Nodo<std::string, Cabecera<Empleado>> *ManejoNoNodoExistente();
    void ManejoNodoExistente();
};
#endif
