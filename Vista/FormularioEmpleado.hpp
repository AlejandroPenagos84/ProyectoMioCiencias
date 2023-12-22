#ifndef FORMULARIOEMPLEADO_HPP
#define FORMULARIOEMPLEADO_HPP
#include "Formulario.hpp"
#include "../Estructuras/Empleado.hpp"
#include <iostream>
#include <stdexcept>
#include <cctype>
#include <limits>
#include <algorithm>

#define PRINTLN(x) std::cout << x << "\n"
#define PRINT(x) std::cout << x
const std::string mensajeErrorLetras = "Error : Solo se pueden ingresar letras.";
const std::string mensajeErrorNumeros = "Error : Solo se pueden ingresar número";
class FormularioEmpleado : public Formulario
{
public:
    DoubleLinkedList<std::string> SolicitarDatos() ;
    void SolicitarInformacionAlpha(std::string mensajeAtributo, DoubleLinkedList<std::string> &atributosEmpleados);
    void SolicitarInformacionNum(std::string mensajeAtributo, DoubleLinkedList<std::string> &atributosEmpleados);
    void SolicitarTelefono(std::string mensajeAtributo, DoubleLinkedList<std::string> &atributosEmpleados);
};
#endif
