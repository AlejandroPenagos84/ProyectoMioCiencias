#include "ControlDao.hpp"

DoubleLinkedList<DoubleLinkedList<std::string>> ControlDao::LeerDAO(const std::string &filename)
{
    std::fstream file;

    file.open(filename.c_str(), std::ios::in);

    if (!file.is_open())
        std::cerr << "Error al abrir el archivo." << std::endl;

    std::string lineaEmpleado;

    // Leer la primera línea y descartarla
    std::getline(file, lineaEmpleado);

    DoubleLinkedList<DoubleLinkedList<std::string>> empleados;

    // Leer el archivo linea por linea
    while (std::getline(file, lineaEmpleado))
    {
        std::stringstream ss(lineaEmpleado);

        DoubleLinkedList<std::string> columnas; ///< Creo una lista que guardará cada dato de cada empleado
        std::string columna;

        while (std::getline(ss, columna, ','))
            columnas.AddLast(columna);

        empleados.AddLast(columnas);
    }

    file.close();

    return empleados;
}
