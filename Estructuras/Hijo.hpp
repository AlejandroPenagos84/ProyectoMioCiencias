#ifndef HIJO_HPP
#define HIJO_HPP
#include <iostream>

class Hijo
{
public:
    // Getters
    std::string getNombre() const { return nombre; }
    std::string getFechaNacimiento() const { return fechaNacimiento; }
    int getEdad() const { return edad; }
    std::string getPadre() const { return padre; }

    Hijo *getAntEdad() const { return antEdad; }
    Hijo *getSigEdad() const { return sigEdad; }

    // Setters
    void setNombre(const std::string &nuevoNombre) { nombre = nuevoNombre; }
    void setFechaNacimiento(const std::string &nuevaFechaNacimiento) { fechaNacimiento = nuevaFechaNacimiento; }
    void setEdad(const int &nuevaEdad) { edad = nuevaEdad; }
    void setPadre(const std::string &nuevoPadre) { padre = nuevoPadre; }

    void setAntEdad(Hijo *nuevoAntEdad) { antEdad = nuevoAntEdad; }
    void setSigEdad(Hijo *nuevoSigEdad) { sigEdad = nuevoSigEdad; }

private:
    std::string nombre;
    std::string fechaNacimiento;
    int edad;
    std::string padre;

    // Edad
    Hijo *antEdad;
    Hijo *sigEdad;
};
#endif