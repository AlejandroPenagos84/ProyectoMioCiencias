#include "Vista.hpp"

Vista::Vista()
{
    gestorDatosEmpleado = new GestorDatosVistaEmpleado;
}

DoubleLinkedList<std::string> Vista::SolicitarDatosEmpleado() { return gestorDatosEmpleado->SolicitarDatosParaAgregar(); }

void Vista::Imprimir(std::string m) { PRINTLN(m); }

int Vista::MenuGlobal()
{
    int op;
    PRINTLN("BIENVENIDO");
    PRINTLN("Para comenzar, elige una de las opciones: ");
    PRINTLN("1. Agregar, eliminar o modificar algún elemento de las multilistas");
    PRINTLN("2. Realizar una consulta");
    PRINTLN("3. Salir");
    PRINT("Elige una opción: ");
    std::cin >> op;
    PRINTLN("'\n\n\n\n");
    return op;
}

int Vista::MenuObjetos()
{
    int op;
    PRINTLN("Selecciona que quieres: ");
    PRINTLN("1. Pais");
    PRINTLN("2. Ciudad");
    PRINTLN("3. Sucursal");
    PRINTLN("4. Empleado");
    PRINTLN("5. Hijo");
    PRINTLN("6. Salir");
    std::cin >> op;
    PRINTLN("\n\n\n\n");
    return op;
}

int Vista::MenuAccion()
{
    int op;
    PRINTLN("Recuerda que si eliminas un objeto de mayor jerarquia eliminarás todos los que esten debajo");
    PRINTLN("es decir, si eliminas un pais, eliminarás todas las ciudad, sucursales, empleados e hijos que esten relacionado con el pais");
    PRINTLN("Selecciona que quieres hacer: ");
    PRINTLN("1. Agregar");
    PRINTLN("2. Eliminar");
    PRINTLN("3. Modificar");
    PRINTLN("4. Salir");
    std::cin >> op;
    PRINTLN("\n\n\n\n");
    return op;
}

std::string Vista::SolicitarInfo(std::string atributo, std::string accion)
{
    std::cin.ignore();
    std::string nombre;
    PRINTLN("Ingresa el nombre del " + atributo + " deseas buscar para " + accion);
    std::getline(std::cin, nombre);
    return nombre;
}

void Vista::Titulo()
{
    std::cout << "  ____  _     _                             _        ____                                  _           " << std::endl;
    std::cout << " / ___|(_)___| |_ ___ _ __ ___   __ _    __| | ___  / ___| _   _  ___ _   _ _ __ ___  __ _| | ___  ___ " << std::endl;
    std::cout << " \\___ \\| / __| __/ _ \\ '_ ` _ \\ / _` |  / _` |/ _ \\ \\___ \\| | | |/ __| | | | '__/ __|/ _` | |/ _ \\/ __|" << std::endl;
    std::cout << "  ___) | \\__ \\ ||  __/ | | | | | (_| | | (_| |  __/  ___) | |_| | (__| |_| | |  \\__ \\ (_| | |  __/\\__ \\" << std::endl;
    std::cout << " |____/|_|___/\\__\\___|_| |_| |_|\\__,_|  \\__,_|\\___| |____/ \\__,_|\\___|\\__,_|_|  |___/\\__,_|_|\\___||___/" << std::endl;
}

int Vista::MostrarMenuModificar(DoubleLinkedList<std::string> &atributos)
{
    int op = 0;
    if (atributos.Size() == 21)
        op = gestorDatosEmpleado->ElegirAtributo(atributos);

    return op;
}
