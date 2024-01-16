#ifndef CONTROLDAO_HPP
#define CONTROLDAO_HPP
#include "../Librerias/Arbol.hpp"
#include "../Librerias/ListaDoble.hpp"
#include <cstdlib>
#include <string>
#include <fstream>
#include <string>
#include <sstream>

using namespace Arbol;
using namespace ListaDoble;

class ControlDao
{
public:
    DoubleLinkedList<DoubleLinkedList<std::string>> LeerDAO(const std::string &filename);
    void Agregar(const std::string &filename, DoubleLinkedList<std::string> objeto);
    void Eliminar(const std::string &filename, std::string idAEliminar);
    void Modificar(const std::string &filename, std::string idAModificar, DoubleLinkedList<std::string> objetoModificado);
    std::string ObtenerUltimoID(const std::string &filename);
};
#endif
