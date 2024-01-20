#ifndef GESTOR_DATOS_HPP
#define GESTOR_DATOS_HPP

#include "../../Librerias/ListaDoble.hpp"
#include <string>
#include <sstream>

using namespace ListaDoble;

#define PRINTLN(x) std::cout << x << "\n"
#define PRINT(x) std::cout << x

const std::string mensajeErrorLetras = "Error : Solo se pueden ingresar letras.";
const std::string mensajeErrorNumeros = "Error : Solo se pueden ingresar número";

class GestorDatosVista
{
public:
    virtual DoubleLinkedList<std::string> SolicitarDatosParaAgregar() = 0;
    virtual int ElegirAtributo(DoubleLinkedList<std::string> &) = 0;
    virtual void MostrarAtributos(DoubleLinkedList<std::string> &) = 0;

protected:
    virtual void ModificarAtributos(DoubleLinkedList<std::string> &atributos, int pos, std::string nuevoDato) = 0;

    inline void SolicitarInformacionAlpha(std::string mensajeAtributo, DoubleLinkedList<std::string> &atributosEmpleados);
    inline void SolicitarInformacionNum(std::string mensajeAtributo, DoubleLinkedList<std::string> &atributosEmpleados);
    inline std::string IngresarNuevoDato(std::string antDato);

    template <class T>
    inline std::string convertirAString(const T &valor);

private:
    inline bool EsStringAlfabeticoConEspacios(const std::string &str);
    inline bool EsStringConNumeros(const std::string &str);
};

inline void GestorDatosVista::SolicitarInformacionAlpha(std::string mensajeAtributo, DoubleLinkedList<std::string> &atributosEmpleados)
{
    std::string atributo;
    do
    {
        PRINT(mensajeAtributo);
        std::getline(std::cin, atributo);
        if (!EsStringAlfabeticoConEspacios(atributo))
            std::cerr << mensajeErrorLetras << std::endl;
        else
            atributosEmpleados.AddLast(atributo);
    } while (!EsStringAlfabeticoConEspacios(atributo));
}

inline bool GestorDatosVista::EsStringAlfabeticoConEspacios(const std::string &str)
{
    for (size_t i = 0; i < str.length(); ++i)
    {
        char c = str[i];
        if (!std::isalpha(c) && !std::isspace(c))
        {
            return false;
        }
    }
    return true;
}

inline void GestorDatosVista::SolicitarInformacionNum(std::string mensajeAtributo, DoubleLinkedList<std::string> &atributosEmpleados)
{
    std::string atributo;
    do
    {
        PRINT(mensajeAtributo);
        std::getline(std::cin, atributo);
        if (!EsStringConNumeros(atributo))
            std::cerr << mensajeErrorNumeros << std::endl;
        else
            atributosEmpleados.AddLast(atributo);

    } while (!EsStringConNumeros(atributo));
}

inline bool GestorDatosVista::EsStringConNumeros(const std::string &str)
{
    for (size_t i = 0; i < str.length(); ++i)
    {
        char c = str[i];
        if (!std::isalnum(c))
        {
            return false;
        }
    }
    return true;
}

template <class T>
inline std::string GestorDatosVista::convertirAString(const T &valor)
{
    std::ostringstream stream;
    stream << valor;
    return stream.str();
}

std::string GestorDatosVista::IngresarNuevoDato(std::string antDato)
{
    std::cin.ignore();
    std::string nuevoDato;
    PRINTLN("Anterior Dato: " + antDato);
    PRINT("Ingresa el nuevo dato: ");
    std::getline(std::cin, nuevoDato);
    PRINTLN("");
    return nuevoDato;
}
#endif