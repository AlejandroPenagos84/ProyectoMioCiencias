#ifndef EMPLEADO_HPP
#define EMPLEADO_HPP
#include <iostream>

class Empleado
{

public:
    // Getters
    int getId() const { return id; }
    std::string getNombre() const { return nombre; }
    std::string getApellido() const { return apellido; }
    std::string getTipoIdentificacion() const { return tipoIdentificacion; }
    std::string getNumIdentificacion() const { return numIdentificacion; }
    bool getSexo() const { return sexo; }
    std::string getTelefonoCelular() const { return telefonoCelular; }
    std::string getTelefonoFijo() const { return telefonoFijo; }
    std::string getEmail() const { return email; }
    std::string getFechaNacimiento() const { return fechaNacimiento; }
    std::string getCiudadNacimiento() const { return ciudadNacimiento; }
    std::string getPaisNacimiento() const { return paisNacimiento; }
    std::string getPaisResidencia() const { return paisResidencia; }
    std::string getCiudadResidencia() const { return ciudadResidencia; }
    std::string getDireccion() const { return direccion; }
    std::string getBarrio() const { return barrio; }
    std::string getActividadLaboral() const { return actividadLaboral; }
    bool getTieneHijos() const { return tieneHijos; }
    int getNumHijos() const { return numHijos; }
    std::string getNombreSucursal() const { return nombreSucursal; }
    int getEdad() const { return edad; }

    Empleado *getAntSexo() const { return antSexo; }
    Empleado *getSigSexo() const { return sigSexo; }
    Empleado *getAntCiudadNacimiento() const { return antCiudadNacimiento; }
    Empleado *getSigCiudadNacimiento() const { return sigCiudadNacimiento; }
    Empleado *getAntPaisNacimiento() const { return antPaisNacimiento; }
    Empleado *getSigPaisNacimiento() const { return sigPaisNacimiento; }
    Empleado *getAntCiudadResidencia() const { return antCiudadResidencia; }
    Empleado *getSigCiudadResidencia() const { return sigCiudadResidencia; }
    Empleado *getAntPaisResidencia() const { return antPaisResidencia; }
    Empleado *getSigPaisResidencia() const { return sigPaisResidencia; }
    Empleado *getAntActividadLaboral() const { return antActividadLaboral; }
    Empleado *getSigActividadLaboral() const { return sigActividadLaboral; }
    Empleado *getAntEdad() const { return antEdad; }
    Empleado *getSigEdad() const { return sigEdad; }
    Empleado *getAntNumHijos() const { return antNumHijos; }
    Empleado *getSigNumHijos() const { return sigNumHijos; }

    // Setters
    void setId(int nuevoId) { id = nuevoId; }
    void setNombre(const std::string &nuevoNombre) { nombre = nuevoNombre; }
    void setApellido(const std::string &nuevoApellido) { apellido = nuevoApellido; }
    void setTipoIdentificacion(const std::string &nuevoTipoIdentificacion) { tipoIdentificacion = nuevoTipoIdentificacion; }
    void setNumIdentificacion(const std::string &nuevoNumIdentificacion) { numIdentificacion = nuevoNumIdentificacion; }
    void setSexo(const bool &nuevoSexo) { sexo = nuevoSexo; }
    void setTelefonoCelular(const std::string &nuevoTelefonoCelular) { telefonoCelular = nuevoTelefonoCelular; }
    void setTelefonoFijo(const std::string &nuevoTelefonoFijo) { telefonoFijo = nuevoTelefonoFijo; }
    void setEmail(const std::string &nuevoEmail) { email = nuevoEmail; }
    void setFechaNacimiento(const std::string &nuevaFechaNacimiento) { fechaNacimiento = nuevaFechaNacimiento; }
    void setCiudadNacimiento(const std::string &nuevaCiudadNacimiento) { ciudadNacimiento = nuevaCiudadNacimiento; }
    void setPaisNacimiento(const std::string &nuevoPaisNacimiento) { paisNacimiento = nuevoPaisNacimiento; }
    void setPaisResidencia(const std::string &nuevoPaisResidencia) { paisResidencia = nuevoPaisResidencia; }
    void setCiudadResidencia(const std::string &nuevaCiudadResidencia) { ciudadResidencia = nuevaCiudadResidencia; }
    void setDireccion(const std::string &nuevaDireccion) { direccion = nuevaDireccion; }
    void setBarrio(const std::string &nuevoBarrio) { barrio = nuevoBarrio; }
    void setActividadLaboral(const std::string &nuevaActividadLaboral) { actividadLaboral = nuevaActividadLaboral; }
    void setTieneHijos(const bool &nuevoTieneHijos) { tieneHijos = nuevoTieneHijos; }
    void setNumHijos(const int &nuevoNumHijos) { numHijos = nuevoNumHijos; }
    void setNombreSucursal(const std::string &nuevoNombreSucursal) { nombreSucursal = nuevoNombreSucursal; }
    void setEdad(const int &nuevaEdad) { edad = nuevaEdad; }

    void setAntSexo(Empleado *nuevoAntSexo) { antSexo = nuevoAntSexo; }
    void setSigSexo(Empleado *nuevoSigSexo) { sigSexo = nuevoSigSexo; }
    void setAntCiudadNacimiento(Empleado *nuevoAntCiudadNacimiento) { antCiudadNacimiento = nuevoAntCiudadNacimiento; }
    void setSigCiudadNacimiento(Empleado *nuevoSigCiudadNacimiento) { sigCiudadNacimiento = nuevoSigCiudadNacimiento; }
    void setAntPaisNacimiento(Empleado *nuevoAntPaisNacimiento) { antPaisNacimiento = nuevoAntPaisNacimiento; }
    void setSigPaisNacimiento(Empleado *nuevoSigPaisNacimiento) { sigPaisNacimiento = nuevoSigPaisNacimiento; }
    void setAntCiudadResidencia(Empleado *nuevoAntCiudadResidencia) { antCiudadResidencia = nuevoAntCiudadResidencia; }
    void setSigCiudadResidencia(Empleado *nuevoSigCiudadResidencia) { sigCiudadResidencia = nuevoSigCiudadResidencia; }
    void setAntPaisResidencia(Empleado *nuevoAntPaisResidencia) { antPaisResidencia = nuevoAntPaisResidencia; }
    void setSigPaisResidencia(Empleado *nuevoSigPaisResidencia) { sigPaisResidencia = nuevoSigPaisResidencia; }
    void setAntActividadLaboral(Empleado *nuevoAntActividadLaboral) { antActividadLaboral = nuevoAntActividadLaboral; }
    void setSigActividadLaboral(Empleado *nuevoSigActividadLaboral) { sigActividadLaboral = nuevoSigActividadLaboral; }
    void setAntEdad(Empleado *nuevoAntEdad) { antEdad = nuevoAntEdad; }
    void setSigEdad(Empleado *nuevoSigEdad) { sigEdad = nuevoSigEdad; }
    void setAntNumHijos(Empleado *nuevoAntNumHijos) { antNumHijos = nuevoAntNumHijos; }
    void setSigNumHijos(Empleado *nuevoSigNumHijos) { sigNumHijos = nuevoSigNumHijos; }

private:
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

    // Numero De Hijos
    Empleado *antNumHijos;
    Empleado *sigNumHijos;
};

#endif