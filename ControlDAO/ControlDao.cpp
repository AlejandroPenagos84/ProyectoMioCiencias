#include "ControlDao.hpp"

ControlDao::ControlDao()
{
    arbolEmpleados = new RBTree<std::string, Empleado>();
}

// Función para leer empleados desde un archivo CSV
void ControlDao::LeerEmpleadoDAO(const std::string &filename)
{
    std::fstream file;

    file.open(filename, std::ios::in);

    std::string lineaEmpleado; ///< Obtiene toda una linea con todos los datos de un empleado

    // Leer la primera línea y descartarla
    std::getline(file, lineaEmpleado);

    // Leer el archivo linea por linea
    while (std::getline(file, lineaEmpleado))
    {
        std::stringstream ss(lineaEmpleado); ///< Se utiliará para manipular los caracteres, es decir para poder separar la linea cuando encuentre una coma

        DoubleLinkedList<std::string> columnas; ///< Creo una lista que guardará cada dato de cada empleado
        std::string columna;

        while (std::getline(ss, columna, ','))
            columnas.AddLast(columna);

        Empleado nuevoEmpleado; ///< Creo un empleado
        // Le asigno los datos del archivo al empleado

        if (columnas.Size() >= 20)
        {
            nuevoEmpleado.nombre = columnas.getData(1);
            nuevoEmpleado.apellido = columnas.getData(2);
            nuevoEmpleado.tipoIdentificacion = columnas.getData(3);
            nuevoEmpleado.numIdentificacion = columnas.getData(4);
            nuevoEmpleado.sexo = sexoToBool(columnas.getData(5));
            nuevoEmpleado.telefonoCelular = columnas.getData(6);
            nuevoEmpleado.telefonoFijo = columnas.getData(7);
            nuevoEmpleado.email = columnas.getData(8);
            nuevoEmpleado.fechaNacimiento = columnas.getData(9);
            nuevoEmpleado.ciudadNacimiento = columnas.getData(10);
            nuevoEmpleado.paisNacimiento = columnas.getData(11);
            nuevoEmpleado.paisResidencia = columnas.getData(12);
            nuevoEmpleado.ciudadResidencia = columnas.getData(13);
            nuevoEmpleado.direccion = columnas.getData(14);
            nuevoEmpleado.barrio = columnas.getData(15);
            nuevoEmpleado.actividadLaboral = columnas.getData(16);
            nuevoEmpleado.tieneHijos = tieneHijosToBool(columnas.getData(17));
            nuevoEmpleado.numHijos = std::stoi(columnas.getData(18));
            nuevoEmpleado.nombreSucursal = columnas.getData(19);
            nuevoEmpleado.edad = std::stoi(columnas.getData(20));
        }
        std::string nombreCompletoEmpleado = nuevoEmpleado.nombre + " " + nuevoEmpleado.apellido;

        // Creo un nodo que será el que se agregará al arbol
        Nodo<std::string, Empleado> *nodoEmpleado = arbolEmpleados->createNodo(nombreCompletoEmpleado, nuevoEmpleado);

        // Agrego el nodo al arbol
        arbolEmpleados->Insert(arbolEmpleados, nodoEmpleado);
    }

    file.close();
}

RBTree<std::string, Empleado> *ControlDao::getArbol()
{
    return arbolEmpleados;
}

bool ControlDao::tieneHijosToBool(std::string tieneHijos)
{
    return tieneHijos == "Sí" ? true : false;
}

bool ControlDao::sexoToBool(std::string sexo)
{
    return sexo == "Masculino" ? true : false;
}