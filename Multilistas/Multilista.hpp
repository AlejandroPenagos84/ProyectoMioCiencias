#ifndef MULTILISTA_HPP
#define MULTILISTA_HPP

template <class T>
class Multilista
{
public:
    virtual void Agregar(T &) = 0;
    virtual void Eliminar(std::string) = 0;
    virtual void Modificar(T &) = 0;
};
#endif