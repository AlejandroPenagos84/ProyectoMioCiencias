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
    // RBTree<std::string, T> *getArbol() = 0;
};
#endif
