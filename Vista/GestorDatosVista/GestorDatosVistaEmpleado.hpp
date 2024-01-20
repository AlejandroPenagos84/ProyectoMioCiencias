#ifndef GESTOR_DATOS_VISTA_EMPLEADO_HPP
#define GESTOR_DATOS_VISTA_EMPLEADO_HPP
#include "GestorDatosVista.hpp"
#include "Edad.hpp"

#include <iostream>
#include <stdexcept>
#include <cctype>
#include <limits>
#include <algorithm>

class GestorDatosVistaEmpleado : public GestorDatosVista
{
public:
    DoubleLinkedList<std::string> SolicitarDatosParaAgregar();
    int ElegirAtributo(DoubleLinkedList<std::string> &atributos);

protected:
    void MostrarAtributos(DoubleLinkedList<std::string> &atributos);
    void ModificarAtributos(DoubleLinkedList<std::string> &atributos, int pos, std::string nuevoDato);

private:
};

#endif
