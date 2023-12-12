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
            nuevoEmpleado.setId(std::stoi(columnas.getData(1)));
            nuevoEmpleado.setNombre(columnas.getData(2));
            nuevoEmpleado.setApellido(columnas.getData(3));
            nuevoEmpleado.setTipoIdentificacion(columnas.getData(4));
            nuevoEmpleado.setNumIdentificacion(columnas.getData(5));
            nuevoEmpleado.setSexo(sexoToBool(columnas.getData(6)));
            nuevoEmpleado.setTelefonoCelular(columnas.getData(7));
            nuevoEmpleado.setTelefonoFijo(columnas.getData(8));
            nuevoEmpleado.setEmail(columnas.getData(9));
            nuevoEmpleado.setFechaNacimiento(columnas.getData(10));
            nuevoEmpleado.setCiudadNacimiento(columnas.getData(11));
            nuevoEmpleado.setPaisNacimiento(columnas.getData(12));
            nuevoEmpleado.setPaisResidencia(columnas.getData(13));
            nuevoEmpleado.setCiudadResidencia(columnas.getData(14));
            nuevoEmpleado.setDireccion(columnas.getData(15));
            nuevoEmpleado.setBarrio(columnas.getData(16));
            nuevoEmpleado.setActividadLaboral(columnas.getData(17));
            nuevoEmpleado.setTieneHijos(tieneHijosToBool(columnas.getData(18)));
            nuevoEmpleado.setNumHijos(std::stoi(columnas.getData(19)));
            nuevoEmpleado.setNombreSucursal(columnas.getData(20));
            nuevoEmpleado.setEdad(std::stoi(columnas.getData(21)));
        }
        std::string nombreCompletoEmpleado = nuevoEmpleado.getNombre() + " " + nuevoEmpleado.getApellido();

        // Creo un nodo que será el que se agregará al arbol
        Nodo<std::string, Empleado> *nodoEmpleado = arbolEmpleados->createNodo(nombreCompletoEmpleado, nuevoEmpleado);

        // Agrego el nodo al arbol
        arbolEmpleados->Insert(arbolEmpleados, nodoEmpleado);
    }

    file.close();
}

void ControlDaoEmpleado::AgregarDAO(const std::string &filename, Empleado Empleado)
{
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

void ControlDaoEmpleado::EliminarDAO(const std::string &filename, Empleado Empleado) {}
void ControlDaoEmpleado::ModificarDAO(const std::string &filename, Empleado Empleado) {}