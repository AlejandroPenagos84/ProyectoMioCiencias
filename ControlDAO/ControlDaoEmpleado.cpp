#include "ControlDaoEmpleado.hpp"

ControlDaoEmpleado::ControlDaoEmpleado()
{
    arbolEmpleados = new RBTree<std::string, Empleado>();
}
void ControlDaoEmpleado::LeerDAO(const std::string &filename)
{
    std::fstream file;

    file.open(filename, std::ios::in);

    if (!file.is_open())
        std::cerr << "Error al abrir el archivo." << std::endl;

    std::string lineaEmpleado;

    // Leer la primera línea y descartarla
    std::getline(file, lineaEmpleado);

    // Leer el archivo linea por linea
    while (std::getline(file, lineaEmpleado))
    {
        std::stringstream ss(lineaEmpleado);

        DoubleLinkedList<std::string> columnas; ///< Creo una lista que guardará cada dato de cada empleado
        std::string columna;

        while (std::getline(ss, columna, ','))
            columnas.AddLast(columna);

        Empleado nuevoEmpleado;

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

void ControlDaoEmpleado::AgregarDAO(const std::string &filename, Empleado Empleado)
{
    std::ofstream archivo;

    archivo.open(filename, std::ios::app);

    if (!archivo.is_open())
        std::cerr << "Error al abrir el archivo." << std::endl;

    archivo << Empleado.id << ',' << Empleado.nombre << ',' << Empleado.apellido << ',';

    archivo.close();
}

int obtenerUltimoID(const std::string &ruta_al_archivo)
{
    std::ifstream archivo(ruta_al_archivo);

    if (!archivo.is_open())
    {
        std::cerr << "Error al abrir el archivo." << std::endl;
        return -1; // Valor de error
    }

    std::string ultimaLinea;
    std::string lineaActual;

    // Leer el archivo línea por línea
    while (std::getline(archivo, lineaActual))
    {
        ultimaLinea = lineaActual;
    }

    archivo.close(); // Cerrar el archivo después de leer

    // Ahora, 'ultimaLinea' contiene el contenido de la última línea
    std::istringstream iss(ultimaLinea);
    int ultimoID;

    if (iss >> ultimoID)
    {
        return ultimoID;
    }
    else
    {
        std::cerr << "Error al convertir el ID a entero." << std::endl;
        return -1; // Valor de error
    }
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