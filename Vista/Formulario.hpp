#ifndef FORMULARIO_HPP
#define FORMULARIO_HPP

template <class T>
class Formulario
{
public:
    virtual T SolicitarDatos() = 0;
};
#endif