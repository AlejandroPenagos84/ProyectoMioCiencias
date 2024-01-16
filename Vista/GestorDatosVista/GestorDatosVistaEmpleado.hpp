#ifndef GESTOR_DATOS_VISTA_HPP
#define GESTOR_DATOS_VISTA_HPP
#include "GestorDatosVista.hpp"
#include "Edad.hpp"

#include <iostream>
#include <stdexcept>
#include <cctype>
#include <limits>
#include <algorithm>

#define PRINTLN(x) std::cout << x << "\n"
#define PRINT(x) std::cout << x

const std::string mensajeErrorLetras = "Error : Solo se pueden ingresar letras.";
const std::string mensajeErrorNumeros = "Error : Solo se pueden ingresar número";

class GestorDatosVistaEmpleado : public GestorDatosVista
{
public:
    DoubleLinkedList<std::string> SolicitarDatosParaAgregar();
    int ElegirAtributo(DoubleLinkedList<std::string> atributos);

protected:
    void MostrarAtributos(DoubleLinkedList<std::string> atributos);

private:
    void SolicitarInformacionAlpha(std::string mensajeAtributo, DoubleLinkedList<std::string> &atributosEmpleados);
    void SolicitarInformacionNum(std::string mensajeAtributo, DoubleLinkedList<std::string> &atributosEmpleados);
    bool EsStringAlfabeticoConEspacios(const std::string &str);
    bool EsStringConNumeros(const std::string &str);

    template <class T>
    std::string convertirAString(const T &valor);
};

#endif
