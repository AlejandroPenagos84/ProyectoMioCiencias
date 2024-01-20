#include "Controlador.hpp"

Controlador::Controlador()
{
    multilistaEmpleados = new MultilistaEmpleado;
    fabricaEmpleados = new FabricaEmpleado;
    vista = new Vista;

    ConfigurarRutas();
    LlenarMultilistas();
    ElegirMenuGlobal();
    ConfigurarNombresDeAtributosDeObjetos();
}

void Controlador::LlenarMultilistas()
{
    // Creo una lista de empleados, con ella creo una cola con los nombres en orden alfabetico para agregarlo en la multilista
    DoubleLinkedList<DoubleLinkedList<std::string>> listaEmpleados = controlDao.LeerDAO(ObtenerRutaRelativa("\\Archivos\\Empleados.csv"));
    Queue<Nodo<std::string, Empleado *> *> colaEmpleados = fabricaEmpleados->crearArbol(listaEmpleados)->inorden();

    while (!colaEmpleados.IsEmpty())
        multilistaEmpleados->Agregar(colaEmpleados.Dequeue('I')->Valor);
}

template <class T>
void Controlador::AgregarObjeto(
    Multilista<T> *multilista,
    DoubleLinkedList<std::string> atributos,
    std::string archivo,
    FabricaAbtracta<T> *fabricaObjeto)
{
    // Obtener el ultimo ID del archivo especificado
    atributos.AddFirst(controlDao.ObtenerUltimoID(archivo));
    T *nuevoObjeto = fabricaObjeto->crearObjeto(atributos);

    controlDao.Agregar(archivo, atributos); ///< Agrego el objeto al archivo
    multilista->Agregar(nuevoObjeto);
}

template <class T>
void Controlador::EliminarObjeto(
    Multilista<T> *multilista,
    std::string objeto,
    std::string archivo,
    FabricaAbtracta<T> *fabricaObjeto)
{
    std::string nombre = vista->SolicitarInfo(objeto, "eliminar");

    if (ComprobarExistenciaDeObjeto(multilista, nombre))
    {
        DoubleLinkedList<std::string> atributos = fabricaObjeto->crearListaDeAtributos(multilista->getObjeto(nombre));
        controlDao.Eliminar(archivo, atributos.getData(1));
        multilista->Eliminar(nombre);
    }
    else
        vista->Imprimir("No existe el " + objeto + " especificado");
}

template <class T>
void Controlador::ModificarObjeto(
    Multilista<T> *multilista,
    DoubleLinkedList<std::string> nombresAtributos,
    std::string objeto,
    std::string archivo,
    FabricaAbtracta<T> *fabricaObjeto)
{
    std::string nombre = vista->SolicitarInfo(objeto, "modificar");

    if (ComprobarExistenciaDeObjeto(multilista, nombre))
    {
        T *objetoOriginal = multilista->getObjeto(nombre);
        DoubleLinkedList<std::string> atributosObjetoOriginal = fabricaObjeto->crearListaDeAtributos(objetoOriginal);
        DoubleLinkedList<std::string> atributosNuevos = ElegirAtributoModificar(atributosObjetoOriginal, nombresAtributos);
        T *objetoModificado = fabricaObjeto->crearObjeto(atributosNuevos);

        controlDao.Modificar(archivo, atributosNuevos.getData(1), atributosNuevos);
        multilista->Modificar(nombre, objetoModificado);
    }
    else
        vista->Imprimir("No existe el " + objeto + " especificado");
}

DoubleLinkedList<std::string> Controlador::ElegirAtributoModificar(DoubleLinkedList<std::string> atributos, DoubleLinkedList<std::string> nombresAtributos)
{
    while (true)
    {
        int op = vista->MostrarMenuModificar(atributos);

        if (op == 0)
            break;

        std::cout << "Atributo Cambiado: " << atributos.getData(op + 1);
    }
    return atributos;
}

void Controlador::ConfigurarRutas()
{
    arregloDirecciones[0] = ObtenerRutaRelativa("\\Archivos\\Empleados.csv");
}

std::string Controlador::ObtenerRutaRelativa(const char *nombre_archivo)
{
    // Obtener el directorio de trabajo actual
    char buffer[FILENAME_MAX];
    if (getcwd(buffer, sizeof(buffer)) == NULL)
    {
        std::cerr << "Error al obtener el directorio actual." << std::endl;
        return NULL;
    }

    // Concatenar el nombre del archivo a la ruta del directorio actual
    std::string ruta_relativa = std::string(buffer) + nombre_archivo;

    return ruta_relativa;
}

void Controlador::ElegirMenuGlobal()
{
    while (true)
    {

        vista->Titulo();
        switch (vista->MenuGlobal())
        {
        case 1:
            // system("cls");
            ElegirMenuAccion();
            break;

        case 2:
            // system("cls");
            vista->Imprimir("IRÁN LAS CONSULTAS");
            break;

        case 3:
            // system("cls");
            return;

        default:
            // system("cls");
            vista->Imprimir("Opcion no valida");
            break;
        }
    }
}

void Controlador::ElegirMenuAccion()
{
    while (true)
    {
        vista->Titulo();
        switch (vista->MenuAccion())
        {
        case 1:
            // system("cls");
            ElegirMenuObjetos("AGREGAR");
            break;

        case 2:
            // system("cls");
            ElegirMenuObjetos("ELIMINAR");
            break;

        case 3:
            // system("cls");
            ElegirMenuObjetos("MODIFICAR");
            break;

        case 4:
            // system("cls");
            return;

        default:
            vista->Imprimir("Opcion no valida");
            break;
        }
    }
}

void Controlador::ElegirMenuObjetos(std::string m)
{
    while (true)
    {
        vista->Titulo();
        vista->Imprimir(m);
        switch (vista->MenuObjetos())
        {
        case 1:
            // system("cls");
            vista->Imprimir("AQUÍ IRA PAÍS");
            break;

        case 2:
            // system("cls");
            vista->Imprimir("AQUÍ IRA CIUDAD");
            break;

        case 3:
            // system("cls");
            vista->Imprimir("AQUÍ IRA SUCURSAL");
            break;

        case 4:
            // system("cls");
            if (m == "AGREGAR")
                AgregarObjeto(getMultilista(), vista->SolicitarDatosEmpleado(), arregloDirecciones[0], fabricaEmpleados);
            else if (m == "ELIMINAR")
                EliminarObjeto(getMultilista(), "empleado", arregloDirecciones[0], fabricaEmpleados);
            else if (m == "MODIFICAR")
                ModificarObjeto(getMultilista(), nombreAtributosEmpleado, "empleado", arregloDirecciones[0], fabricaEmpleados);
            break;

        case 5:
            // system("cls");
            vista->Imprimir("AQUI IRÁ HIJO");
            break;

        case 6:
            // system("cls");
            return;

        default:
            vista->Imprimir("Opcion no valida");
            break;
        }
    }
}

template <class T>
bool Controlador::ComprobarExistenciaDeObjeto(Multilista<T> *multilista, std::string nombre)
{
    return multilista->getObjeto(nombre) != NULL;
}

void Controlador::ConfigurarNombresDeAtributosDeObjetos()
{
    nombreAtributosEmpleado.AddLast("Nombre");
    nombreAtributosEmpleado.AddLast("Apellido");
    nombreAtributosEmpleado.AddLast("Tipo de Identificación");
    nombreAtributosEmpleado.AddLast("Número de Identificación");
    nombreAtributosEmpleado.AddLast("Sexo");
    nombreAtributosEmpleado.AddLast("Teléfono Celular");
    nombreAtributosEmpleado.AddLast("Teléfono Fijo");
    nombreAtributosEmpleado.AddLast("Email");
    nombreAtributosEmpleado.AddLast("Fecha de Nacimiento");
    nombreAtributosEmpleado.AddLast("Ciudad de Nacimiento");
    nombreAtributosEmpleado.AddLast("País de Nacimiento");
    nombreAtributosEmpleado.AddLast("País de Residencia");
    nombreAtributosEmpleado.AddLast("Ciudad de Residencia");
    nombreAtributosEmpleado.AddLast("Dirección");
    nombreAtributosEmpleado.AddLast("Barrio");
    nombreAtributosEmpleado.AddLast("Actividad Laboral");
    nombreAtributosEmpleado.AddLast("Tiene Hijos");
    nombreAtributosEmpleado.AddLast("Número de Hijos");
    nombreAtributosEmpleado.AddLast("Sucursal Donde Trabaja");
    nombreAtributosEmpleado.AddLast("Edad");
}