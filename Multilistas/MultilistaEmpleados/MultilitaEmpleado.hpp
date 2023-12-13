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

template <class T>
struct GettersEmpleado
{
    T(Empleado::*obtenerDato)
    () const;
    Empleado *(Empleado::*obtenerPunteroAnt)() const;
    Empleado *(Empleado::*obtenerPunteroSig)() const;
};

template <class T>
struct SettersEmpleado
{
    void (Empleado::*setDato)(const T &);
    void (Empleado::*setPunteroAnt)(Empleado *);
    void (Empleado::*setPunteroSig)(Empleado *);
};

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
    void Modificar(Empleado &empleado) override;

    // Getters
    RBTree<std::string, Cabecera<Empleado>> *getCabeceraCiudadNacimiento();
    RBTree<std::string, Cabecera<Empleado>> *getCabeceraPaisNacimiento();
    RBTree<std::string, Cabecera<Empleado>> *getCabeceraCiudadResidencia();
    RBTree<std::string, Cabecera<Empleado>> *getCabeceraPaisResidencia();
    RBTree<std::string, Cabecera<Empleado>> *getCabeceraActividadLaboral();

private:
    void AgregarAArbol(Empleado &empleado);

    // Metodo para organizar los datos en las cabeceras
    void OrganizarDatos(Empleado &empleado);
    void OrganizarGenerico(RBTree<std::string, Cabecera<Empleado>> *arbolCabecera, Empleado *empleado, GettersEmpleado<std::string> getters, SettersEmpleado<std::string> setters);
    void ManejarNodoNoExistente(RBTree<std::string, Cabecera<Empleado>> *arbolCabecera, Empleado *empleado, GettersEmpleado<std::string> getters, SettersEmpleado<std::string> setters);

    void ManejarNodoExistente(RBTree<std::string, Cabecera<Empleado>> *arbolCabecera, Empleado *empleado, GettersEmpleado<std::string> getters, SettersEmpleado<std::string> setters);
    void ManejarNodosExistenteUnDato(Cabecera<Empleado> &cabEmpleado, Empleado *empleado, GettersEmpleado<std::string> getters, SettersEmpleado<std::string> setters);
    void ManejarNodoExistenteVariosDatos(Cabecera<Empleado> &cabEmpleado, Empleado *empleado, GettersEmpleado<std::string> getters, SettersEmpleado<std::string> setters);

    // Metodo para eliminar un empleado
    void EliminarDelArbol(std::string nombreCompleto);
    void ManejoDeCabecerasEliminar(RBTree<std::string, Cabecera<Empleado>> *arbolCabecera, Empleado *empleado, GettersEmpleado<std::string> getters, SettersEmpleado<std::string> setters);

    // Metodos para obtener los getters y setters especificados
    GettersEmpleado<std::string> ConfigurarGettersEmpleado(std::string (Empleado::*atributo)() const, Empleado *(Empleado::*punteroAnt)() const, Empleado *(Empleado::*punteroSig)() const);
    SettersEmpleado<std::string> ConfigurarSettersEmpleado(void (Empleado::*setAtributo)(const std::string &), void (Empleado::*setPunteroAnt)(Empleado *), void (Empleado::*setPunteroSig)(Empleado *));
};
#endif
