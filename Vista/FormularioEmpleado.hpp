#ifndef FORMULARIOEMPLEADO_HPP
#define FORMULARIOEMPLEADO_HPP
#include "Formulario.hpp"
#include "../Estructuras/Empleado.hpp"
#include <iostream>
#include <stdexcept>
#include <cctype>
#include <limits>
#include <algorithm>

#define PRINTLN(x) std::cout << x << std::endl
#define PRINT(x) std::cout << x
#define mensajeErrorLetras "Error : Solo se pueden ingresar letras."
#define mensajeErrorNumeros "Error : Solo se pueden ingresar número"

class FormularioEmpleado : public Formulario<Empleado>
{
public:
    FormularioEmpleado();
    Empleado SolicitarDatos() override;
    void SolicitarInformacionAlpha(std::string mensajeAtributo, Empleado &empleado, std::string Empleado::*atributo);
    void SolicitarInformacionNum(std::string mensajeAtributo, Empleado &empleado, std::string Empleado::*atributo);
    void SolicitarTelefono(std::string mensajeAtributo, Empleado &empleado, std::string Empleado::*atributo);
};
#endif
