#ifndef EDAD_H
#define EDAD_H

#include <iostream>
#include <sstream>
#include <ctime>

/**
 * @brief Estructura que representa una fecha con dÃ­a, mes y aÃ±o.
 */
struct Fecha
{
    int dia;  ///< DÃ­a de la fecha.
    int mes;  ///< Mes de la fecha.
    int anio; ///< AÃ±o de la fecha.
};

/**
 * @brief Convierte una cadena de texto en formato "dd/mm/yyyy" a una estructura Fecha.
 *
 * @param fechaStr Cadena de texto que representa la fecha en formato "dd/mm/yyyy".
 * @return Estructura Fecha con el dÃ­a, mes y aÃ±o.
 */
inline Fecha obtenerFechaDesdeString(const std::string &fechaStr)
{
    Fecha fecha;
    std::stringstream ss(fechaStr);
    char delimiter;

    ss >> fecha.dia >> delimiter >> fecha.mes >> delimiter >> fecha.anio;

    return fecha;
}

/**
 * @brief Calcula la edad en aÃ±os a partir de la fecha de nacimiento.
 *
 * @param fechaNacimiento Estructura Fecha que representa la fecha de nacimiento.
 * @return Edad en aÃ±os.
 */
inline int calcularEdad(const Fecha &fechaNacimiento)
{
    time_t tiempoActual = time(nullptr);
    tm *tiempoLocal = localtime(&tiempoActual);

    int edad = tiempoLocal->tm_year + 1900 - fechaNacimiento.anio;

    if (tiempoLocal->tm_mon + 1 < fechaNacimiento.mes ||
        (tiempoLocal->tm_mon + 1 == fechaNacimiento.mes && tiempoLocal->tm_mday < fechaNacimiento.dia))
    {
        --edad;
    }
    return edad;
}

#endif