#ifndef EMPLEADO_HPP
#define EMPLEADO_HPP
#include <iostream>

struct Empleado
{
    // Atributos Del Empleado
    int id;
    std::string nombre;
    std::string apellido;
    std::string tipoIdentificacion;
    std::string numIdentificacion;
    bool sexo;
    std::string telefonoCelular;
    std::string telefonoFijo;
    std::string email;
    std::string fechaNacimiento;
    std::string ciudadNacimiento;
    std::string paisNacimiento;
    std::string paisResidencia;
    std::string ciudadResidencia;
    std::string direccion;
    std::string barrio;
    std::string actividadLaboral;
    bool tieneHijos;
    int numHijos;
    // Lista hijos
    std::string nombreSucursal;
    int edad;

    // Punteros Especificos
    // Sexo
    Empleado *antSexo;
    Empleado *sigSexo;

    // Ciudad Nacimiento
    Empleado *antCiudadNacimiento;
    Empleado *sigCiudadNacimiento;

    // Pais Nacimiento
    Empleado *antPaisNacimiento;
    Empleado *sigPaisNacimiento;

    // Ciudad Residencia
    Empleado *antCiudadResidencia;
    Empleado *sigCiudadResidencia;

    // Pais Residencia
    Empleado *antPaisResidencia;
    Empleado *sigPaisResidencia;

    // Actividad Laboral
    Empleado *antActividadLaboral;
    Empleado *sigActividadLaboral;

    // Edad
    Empleado *antEdad;
    Empleado *sigEdad;
};

#endif