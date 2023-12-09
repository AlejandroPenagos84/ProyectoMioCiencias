#ifndef CONTROLDAO_HPP
#define CONTROLDAO_HPP
#include "../Librerias/Arbol.hpp"

using namespace Arbol;
template <class T>
class ControlDao
{
public:
    virtual void LeerDAO(const std::string &filename) = 0;
    virtual void AgregarDAO(const std::string &filename, T objeto) = 0;
    virtual void EliminarDAO(const std::string &filename, T objeto) = 0;
    virtual void ModificarDAO(const std::string &filename, T objeto) = 0;
    virtual RBTree<std::string, T> *getArbol() = 0;
};

#endif
