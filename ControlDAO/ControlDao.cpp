#include "ControlDao.hpp"

DoubleLinkedList<DoubleLinkedList<std::string>> ControlDao::LeerDAO(const std::string &filename)
{
    std::fstream file(filename.c_str(), std::ios::in);

    if (!file.is_open())
        std::cerr << "Error al abrir el archivo." << std::endl;

    // Leer la primera línea y descartarla
    std::string lineaObjeto;
    std::getline(file, lineaObjeto);

    // Leer el archivo linea por linea
    DoubleLinkedList<DoubleLinkedList<std::string>> objetos;
    CrearListaDeObjetos(file, objetos);

    file.close();

    return objetos;
}

void ControlDao::CrearListaDeObjetos(std::fstream &file, DoubleLinkedList<DoubleLinkedList<std::string>> &objetos)
{
    std::string lineaObjeto;
    while (std::getline(file, lineaObjeto))
    {
        std::stringstream ss(lineaObjeto);
        DoubleLinkedList<std::string> columnas; ///< Creo una lista que guardará cada dato de cada Objeto
        std::string columna;

        while (std::getline(ss, columna, ','))
            columnas.AddLast(columna);

        objetos.AddLast(columnas);
    }
}

void ControlDao::Agregar(const std::string &filename, DoubleLinkedList<std::string> objeto)
{
    std::ofstream file;
    file.open(filename.c_str(), std::ios::app);

    if (!file.is_open())
        throw std::runtime_error("Error al abrir el archivo.");

    file << std::endl;
    file << ConfigurarObjetoAgregado(objeto);
    file.close();
}

std::string ControlDao::ConfigurarObjetoAgregado(DoubleLinkedList<std::string> objeto)
{
    std::stringstream ss;

    for (int i = 1; i <= objeto.Size(); i++)
    {
        if (i == objeto.Size())
            ss << objeto.getData(i);
        else
            ss << objeto.getData(i) << ',';
    }

    return ss.str();
}

void ControlDao::Eliminar(const std::string &filename, std::string idAEliminar)
{
    std::fstream file(filename.c_str(), std::ios::in | std::ios::out | std::ios::app);

    if (!file.is_open())
        std::cerr << "Error al abrir el archivo." << std::endl;

    DoubleLinkedList<std::string> *objetosNoEliminados = new DoubleLinkedList<std::string>();
    std::string lineaObjeto;

    std::getline(file, lineaObjeto);
    objetosNoEliminados->AddLast(lineaObjeto);

    while (std::getline(file, lineaObjeto))
    {
        if (CompararId(idAEliminar, lineaObjeto))
            objetosNoEliminados->AddLast(lineaObjeto);
    }

    file.clear();
    file.seekp(0);
    file.close(); // Close the file

    EscribirElementosEnArchivo(filename, objetosNoEliminados);
    delete objetosNoEliminados;
}

void ControlDao::Modificar(
    const std::string &filename,
    std::string idAModificar,
    DoubleLinkedList<std::string> objetoModificado)
{
    std::fstream file(filename.c_str(), std::ios::in | std::ios::out | std::ios::app);

    if (!file.is_open())
        std::cerr << "Error al abrir el archivo." << std::endl;

    DoubleLinkedList<std::string> *objetosDelArchivo = new DoubleLinkedList<std::string>();

    std::string lineaObjeto;

    std::getline(file, lineaObjeto);
    objetosDelArchivo->AddLast(lineaObjeto);

    while (std::getline(file, lineaObjeto))
    {
        if (CompararId(idAModificar, lineaObjeto))
            objetosDelArchivo->AddLast(lineaObjeto);
        else
            objetosDelArchivo->AddLast(ConfigurarObjetoModificado(objetoModificado));
    }

    file.clear();
    file.seekp(0);

    EscribirElementosEnArchivo(filename, objetosDelArchivo);
    delete objetosDelArchivo;
}

void ControlDao::EscribirElementosEnArchivo(const std::string &filename, DoubleLinkedList<std::string> *objetos)
{
    std::fstream file(filename.c_str(), std::ios::out | std::ios::trunc); // Reopen the file in truncation mode

    if (!file.is_open())
        std::cerr << "Error al abrir el archivo para escribir." << std::endl;

    for (int i = 1; i <= objetos->Size(); i++)
    {
        file << objetos->getData(i);
        if (i < objetos->Size())
            file << '\n';
    }

    file.close();
}

std::string ControlDao::ConfigurarObjetoModificado(DoubleLinkedList<std::string> objetoModificado)
{
    std::stringstream objetoModificadoStream;
    for (int i = 1; i <= objetoModificado.Size(); i++)
    {

        if (i == objetoModificado.Size())
            objetoModificadoStream << objetoModificado.getData(i);
        else
            objetoModificadoStream << objetoModificado.getData(i) << ',';
    }

    return objetoModificadoStream.str();
}

bool ControlDao::CompararId(std::string idABuscar, std::string lineaObjeto)
{
    std::stringstream ss(lineaObjeto);

    std::string id;
    std::getline(ss, id, ',');

    return id != idABuscar;
}

std::string ControlDao::ObtenerUltimoID(const std::string &filename)
{
    std::fstream file;

    file.open(filename.c_str(), std::ios::in);
    std::string lineaObjeto;
    std::stringstream ss;
    while (std::getline(file, lineaObjeto))
    {
        ss.str("");
        ss << lineaObjeto;
    }

    std::string id;
    std::getline(ss, id, ',');

    std::istringstream iss(id);
    int numero;
    iss >> numero;

    numero += 1;

    std::ostringstream oss;
    oss << numero;
    std::string nuevoIDString = oss.str();
    file.close();

    return nuevoIDString;
}