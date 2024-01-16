#ifndef CONTROLADOR_HPP
#define CONTROLADOR_HPP

#include <iostream>
#include <direct.h>

#include "../ControlDAO/ControlDao.hpp"
#include "../Fabricas/FabricaAbstracta.hpp"
#include "../Fabricas/FabricaEmpleado/FabricaEmpleado.hpp"

#include "../Estructuras/Empleado.hpp"
#include "../Librerias/Arbol.hpp"
#include "../Librerias/ListaDoble.hpp"

#include "../Multilistas/Multilista.hpp"
#include "../Multilistas/MultilistaEmpleados/MultilitaEmpleado.hpp"
#include "../Vista/Vista.hpp"

using namespace Arbol;
using namespace ListaDoble;

// class Vista;
class Controlador
{

private:
    ControlDao controlDao;
    Multilista<Empleado> *multilistaEmpleados;
    FabricaAbtracta<Empleado> *fabricaEmpleados;
    Vista *vista;
    std::string arregloDirecciones[5];

    DoubleLinkedList<std::string> nombreAtributosEmpleado;

public:
    Controlador();
    void LlenarMultilistas();

    template <class T>
    void AgregarObjeto(
        Multilista<T> *multilista,
        DoubleLinkedList<std::string> atributos,
        std::string archivo,
        FabricaAbtracta<T> *fabricaObjeto);

    template <class T>
    void EliminarObjeto(
        Multilista<T> *multilista,
        std::string objeto,
        std::string archivo,
        FabricaAbtracta<T> *fabricaObjeto);

    template <class T>
    void ModificarObjeto(
        Multilista<T> *multilista,
        DoubleLinkedList<std::string> nombresAtributos,
        std::string objeto,
        std::string archivo,
        FabricaAbtracta<T> *fabricaObjeto);

    void ElegirMenuGlobal();
    void ElegirMenuAccion();
    void ElegirMenuObjetos(std::string m);
    DoubleLinkedList<std::string> ElegirAtributoModificar(DoubleLinkedList<std::string> atributos, DoubleLinkedList<std::string> nombresAtributos);

    // METODO AUXILIAR, SOLO PARA PROBAR
    Multilista<Empleado> *getMultilista() { return multilistaEmpleados; }

private:
    std::string ObtenerRutaRelativa(const char *nombre_archivo);
    void ConfigurarRutas();
    void ConfigurarNombresDeAtributosDeObjetos();

    template <class T>
    bool ComprobarExistenciaDeObjeto(Multilista<T> *multilista, std::string nombre);
};
#endif
