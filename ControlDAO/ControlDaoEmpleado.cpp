#include "ControlDaoEmpleado.hpp"

ControlDaoEmpleado::ControlDaoEmpleado()
{
    arbolEmpleados = new RBTree<std::string, Empleado>();
}

// Función para leer empleados desde un archivo CSV
void ControlDaoEmpleado::LeerDAO(const std::string &filename)
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

        if (columnas.Size() >= 21)
        {
            nuevoEmpleado.id = std::stoi(columnas.getData(1));
            nuevoEmpleado.nombre = columnas.getData(2);
            nuevoEmpleado.apellido = columnas.getData(3);
            nuevoEmpleado.tipoIdentificacion = columnas.getData(4);
            nuevoEmpleado.numIdentificacion = columnas.getData(5);
            nuevoEmpleado.sexo = sexoToBool(columnas.getData(6));
            nuevoEmpleado.telefonoCelular = columnas.getData(7);
            nuevoEmpleado.telefonoFijo = columnas.getData(8);
            nuevoEmpleado.email = columnas.getData(9);
            nuevoEmpleado.fechaNacimiento = columnas.getData(10);
            nuevoEmpleado.ciudadNacimiento = columnas.getData(11);
            nuevoEmpleado.paisNacimiento = columnas.getData(12);
            nuevoEmpleado.paisResidencia = columnas.getData(13);
            nuevoEmpleado.ciudadResidencia = columnas.getData(14);
            nuevoEmpleado.direccion = columnas.getData(15);
            nuevoEmpleado.barrio = columnas.getData(16);
            nuevoEmpleado.actividadLaboral = columnas.getData(17);
            nuevoEmpleado.tieneHijos = tieneHijosToBool(columnas.getData(18));
            nuevoEmpleado.numHijos = std::stoi(columnas.getData(19));
            nuevoEmpleado.nombreSucursal = columnas.getData(20);
            nuevoEmpleado.edad = std::stoi(columnas.getData(21));
        }
        std::string nombreCompletoEmpleado = nuevoEmpleado.nombre + " " + nuevoEmpleado.apellido;

        // Creo un nodo que será el que se agregará al arbol
        Nodo<std::string, Empleado> *nodoEmpleado = arbolEmpleados->createNodo(nombreCompletoEmpleado, nuevoEmpleado);

        // Agrego el nodo al arbol
        arbolEmpleados->Insert(arbolEmpleados, nodoEmpleado);
    }

    file.close();
}

RBTree<std::string, Empleado> *ControlDaoEmpleado::getArbol()
{
    return arbolEmpleados;
}

bool ControlDaoEmpleado::tieneHijosToBool(std::string tieneHijos)
{
    return tieneHijos == "Sí" ? true : false;
}

bool ControlDaoEmpleado::sexoToBool(std::string sexo)
{
    return sexo == "Masculino" ? true : false;
}

void ControlDaoEmpleado::AgregarDAO(const std::string &filename, Empleado Empleado) {}
void ControlDaoEmpleado::EliminarDAO(const std::string &filename, Empleado Empleado) {}
void ControlDaoEmpleado::ModificarDAO(const std::string &filename, Empleado Empleado) {}